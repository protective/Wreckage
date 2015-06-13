/* 
 * File:   ClientWebSock.cpp
 * Author: karsten
 * 
 * Created on 17. maj 2015, 22:23
 */

#include "ClientWebSock.h"
#include <cryptopp/base64.h>
#include <cryptopp/sha.h>
#include <sstream>
#include <iomanip>

ClientWebSock::ClientWebSock(int socket) :
Client(socket){
	_handshakeing = true;
}

void ClientWebSock::handshake(){
	int recsize;
	uint32_t timeout = 0;

	char key[24+36];
	byte retsha[20];
	string encoded;
	bool end = false;
	char uuid[] = {"258EAFA5-E914-47DA-95CA-C5AB0DC85B11"};
	while (!end){
		recsize = recv(this->getSocket(), (this->outputnetworkBuf->networkBuf) + this->outputnetworkBuf->recived, 512,0);
		this->outputnetworkBuf->recived += recsize;
		if (recsize <= 0){
			fprintf(stderr, "RECV  ERROR WEBSOCK***************\n");
			this->disconnect();
			break;
		}
	
		uint32_t delta = 0;
		const char *search_key = "Sec-WebSocket-Key:";
		const char *end_key = "\r\n\r\n";
		uint32_t end_key_cmpsize = 4;
		uint32_t cmpsize = 18;
		cerr<<"size = "<<sizeof(search_key)<<" "<< this->outputnetworkBuf->recived<<endl;

		for (uint32_t i = 0; i < this->outputnetworkBuf->recived; i++){
			cout<<this->outputnetworkBuf->networkBuf[i];
		}
		cout<<endl;
		
		for (uint32_t i = 0; i < this->outputnetworkBuf->recived; i++){
			delta = i+1;
			if (i + cmpsize + 24 < 512 && memcmp(search_key,&this->outputnetworkBuf->networkBuf[i], cmpsize) == 0){
				cout<<"FOUND IT !!!!!!!!!!!!"<<endl;
				//_handshakeing = false;
				memcpy(key, &this->outputnetworkBuf->networkBuf[i + cmpsize + 1], 24);
				memcpy(key+ 24, uuid, 36);

				CryptoPP::SHA1 sha;
				sha.CalculateDigest(retsha, (byte*)key, 24+36);
				CryptoPP::StringSource ss(retsha,20,true,new CryptoPP::Base64Encoder(new CryptoPP::StringSink(encoded),false));

				string responce = "HTTP/1.1 101\r\nConnection: Upgrade\r\nUpgrade: websocket\r\nSec-WebSocket-Accept: " + encoded + "\r\n\r\n" ;
				cout<<"key  ="<<key<<endl;
				cout<<"sha1 ="<<retsha<<endl;
				cout<<"encoded ="<<encoded<<endl;
				cout<<"size="<<responce.size()<<endl;
				send(this->getSocket(), (void* )responce.c_str(),responce.size() ,MSG_NOSIGNAL);

			}else if (i + end_key_cmpsize < 512 && memcmp(end_key,&this->outputnetworkBuf->networkBuf[i], end_key_cmpsize) == 0){
				end = true;
				cout<<"found end"<<endl;
			}

		}

		memmove(this->outputnetworkBuf->networkBuf, this->outputnetworkBuf->networkBuf+ delta, this->outputnetworkBuf->recived- delta);
		this->outputnetworkBuf->recived -= delta;
	}
	
	
	cerr<<"recived size="<<this->outputnetworkBuf->recived<<endl;
}


void ClientWebSock::sendToC(void* block, uint32_t len){
	stringstream sstream;
	for (uint32_t i = 0; i < this->outputnetworkBuf->recived; i+=1){
		sstream <<std::hex <<setfill('0')<<setw( 2 ) << (uint16_t)(this->outputnetworkBuf->networkBuf[i] & 0x00FF) << " ";
	}		
	std::string result = sstream.str();
	cout<<"send    ="<<result<<endl;	
		
	char buffer[len +2];
	memcpy(buffer+2, block,len);
	
	buffer[0] = (char)0x82;
	buffer[1] = (char)( len);
	/*
	buffer[2] = 0;
	buffer[3] = 0;
	buffer[4] = 0;
	buffer[5] = 0;
	
	for (uint32_t i = 6; i < len + 6; i+=1){
		buffer[i] = ((char*)block)[i] ^ buffer[((i-6) % 4) + 2];
	}
	*/
	send(this->getSocket(), (void*)buffer, len+2,MSG_NOSIGNAL);
}

void ClientWebSock::ReadBuffer(){
	if (this->outputnetworkBuf->recived > 0){
		

		//************************************
		//CRITICAL
		pthread_mutex_lock(&this->networkBufLock);
		this->parsingoutput = true;
		pthread_mutex_unlock(&this->networkBufLock);
		//CRITICAL
		//************************************
		//if(printbufferbool)
		stringstream sstream;
		
		
		cout<<"size="<<this->outputnetworkBuf->recived<<endl;
		

		for (uint32_t i = 0; i < this->outputnetworkBuf->recived; i+=1){
			sstream <<std::hex <<setfill('0')<<setw( 2 ) << (uint16_t)(this->outputnetworkBuf->networkBuf[i] & 0x00FF) << " ";
		}	
		std::string result = sstream.str();
		cout<<"res     ="<<result<<endl;	
		
		stringstream maskstream;

		uint32_t headerlength = 2;
		uint32_t maskLength = 4;
		
		for (uint32_t i = 6; i < this->outputnetworkBuf->recived; i+=1){
			this->outputnetworkBuf->networkBuf[i] =
					this->outputnetworkBuf->networkBuf[i] ^ this->outputnetworkBuf->networkBuf[((i-6) % 4) + 2];
		}
		for (uint32_t i = 0; i < this->outputnetworkBuf->recived; i+=1){
			maskstream <<std::hex <<setfill('0')<<setw( 2 ) << (uint16_t)(this->outputnetworkBuf->networkBuf[i] & 0x00FF) << " ";
		}
		
		uint32_t delta = headerlength + maskLength;
		uint32_t payloadLen = (this->outputnetworkBuf->networkBuf[1] & 0x7F);
		
		memmove(this->outputnetworkBuf->networkBuf, this->outputnetworkBuf->networkBuf+ delta, this->outputnetworkBuf->recived- delta);
		this->outputnetworkBuf->recived -= delta;
		
		result = maskstream.str();
		cout<<"unmasked="<<result<<endl;
		
		for (uint32_t i = 0; i < this->outputnetworkBuf->recived; i+=1){
			cout<<this->outputnetworkBuf->networkBuf[i];
		}	
		cout<<endl;
		
		
		parseBuffer(this->outputnetworkBuf->recived);

		delta = payloadLen;
		memmove(this->outputnetworkBuf->networkBuf, this->outputnetworkBuf->networkBuf+ delta, this->outputnetworkBuf->recived- delta);
		this->outputnetworkBuf->recived -= delta;

		//************************************
		//CRITICAL
		pthread_mutex_lock(&this->networkBufLock);
		this->parsingoutput = false;
		pthread_mutex_unlock(&this->networkBufLock);
		//CRITICAL
		//************************************
	}
}

ClientWebSock::~ClientWebSock() {
}
