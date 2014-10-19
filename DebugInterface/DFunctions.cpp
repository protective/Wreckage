
#include "DFunctions.h"

uint32_t getTime(){
	return SDL_GetTicks()+Gtime;
}


void* Connect(string ip, uint32_t playerid, uint32_t pass){

	struct sockaddr_in stSockAddr;

    int Res;
    connection.SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (-1 == connection.SocketFD)
    {
      perror("cannot create socket");
      exit(EXIT_FAILURE);
    }

    memset(&stSockAddr, 0, sizeof(struct sockaddr_in));

    stSockAddr.sin_family = AF_INET;
    stSockAddr.sin_port = htons(11142);
    Res = inet_pton(AF_INET, ip.c_str(), &stSockAddr.sin_addr);

    if (0 > Res)
    {
      perror("error: first parameter is not a valid address family");
      close(connection.SocketFD);
      exit(EXIT_FAILURE);
    }
    else if (0 == Res)
    {
      perror("char string (second parameter does not contain valid ipaddress");
      close(connection.SocketFD);
      exit(EXIT_FAILURE);
    }

	if (-1 == connect(connection.SocketFD, (const struct sockaddr *)&stSockAddr, sizeof(struct sockaddr_in))){
		perror("connect failed");
		close(connection.SocketFD);
		exit(EXIT_FAILURE);
	}
	//while (true){
	cerr<<"connected time "<<SDL_GetTicks()<<endl;
	connection.connected = true;


	pthread_create(&connection.listenThread, NULL, (void*(*)(void*))thread_Recive, NULL);
		char message[sizeof(SerialReqJoin)];
		memset(message,0,sizeof(SerialReqJoin));

		SerialReqJoin* data = (SerialReqJoin*)(message);
		data->_type = SerialType::SerialReqJoin;
		data->_size = sizeof(SerialReqJoin);
		data->_unitId = playerid; //TODO BIG TODO FIX THIS SOOON
		data->_pass = pass;
		send(connection.SocketFD,message,sizeof(SerialReqJoin),0);


		for (int i = 0; i < 5; i++){
			char message2[sizeof(SerialTime)];
			memset(message2,0,sizeof(SerialTime));

			SerialTime* data2 = (SerialTime*)(message2);
			data2->_type = SerialType::SerialTime;
			data2->_size = sizeof(SerialTime);
			data2->time = 0;
			data2->local = SDL_GetTicks();
			cerr<<"send Time req"<<data2->local<<endl;

			send(connection.SocketFD,message2,sizeof(SerialTime),0);

			usleep(200000);
		}
  }



void* thread_Recive(){

		connection.messagebuffer = (char*)malloc(2048);
		memset(connection.messagebuffer,0,2048);
		printf ("recv test....\n");
		int recsize;
		uint32_t time= getTime();
		int recived = 0;
		uint32_t delta = 0;

	
		while(connection.connected){

			recsize = recv(connection.SocketFD, connection.messagebuffer + recived, 1024,0);
			

			if (recsize < 0)
					fprintf(stderr, "error\n");
			recived +=recsize;

			if (recived >= 1){
				delta = 1;
				while (delta){
					pthread_mutex_lock(&lockInput);
					
					delta = parseBuffer(connection.messagebuffer,recived);
					pthread_mutex_unlock(&lockInput);
					memmove(connection.messagebuffer, connection.messagebuffer+ delta, 2048 - delta);
					recived -= delta;
				}
			}
			usleep(40);
		}


		shutdown(connection.SocketFD, SHUT_RDWR);

		close(connection.SocketFD);
		pthread_exit(0);
}




uint32_t parseBuffer(char* buffer, uint32_t len){
	uint32_t offset = 0;
	printBuffer(buffer,len);
	while (offset < len){
		SerialData* meta = (SerialData*)(buffer + offset);

		if (len - offset >= sizeof(uint32_t)*2 && meta->_size <= len - offset){


			switch(meta->_type)
			{
				case SerialType::SerialTime:{
					SerialTime* st = (SerialTime*)(buffer+offset);
					cerr<<"recived time req"<<st->time<< " local "<<SDL_GetTicks()<<endl;
					uint32_t tem = st->time + ((SDL_GetTicks()-st->local)/2);

					Gtime += tem -SDL_GetTicks();

					tTime ++;
					cerr<<"t"<<tTime<<endl;
					if (tTime == 5){
						Gtime = Gtime/5;
						cerr<<"final Gtime "<<Gtime<<endl;
					}
					break;

				}
			
				default:{
					cerr<<"ERROR PARSING debug recived = "<<(uint32_t) *(buffer+offset)<<endl;

					break;
				}
			}
				offset += meta->_size;
		}else{
			//cerr<<"missing data "<<endl;
			break;
		}
	}
	//updateFrames();
	//cerr<<"offset="<<offset<<endl;
	return offset;
}

  void* Disconnect(){

	cerr<<"Disconnect"<<endl;
	shutdown(connection.SocketFD, SHUT_RDWR);

	close(connection.SocketFD);
	connection.connected = false;
	pthread_join(connection.listenThread, NULL);
  }
