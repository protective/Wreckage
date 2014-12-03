#include "NetworkFunctions.h"
#include "NetworkControler.h"


#include "Client.h"

#include "../ModelLayer/Components/ComponentFactory.h"
#include "../ModelLayer/Components/SComponent.h"
#include "../ModelLayer/Components/CompReSpawnable/CompReSpawnable.h"
#include "../ModelLayer/Components/CompSpawnNode/CompSpawnNode.h"



#include "../Tasks/TaskAddComponent.h"
#include "../Tasks/TaskRemoveObj.h"
#include "../Tasks/TaskAcceptInput.h"
#include "../Tasks/TaskAddClientView.h"
#include "../Tasks/TaskCreateObj.h"

void sendtoC(Client* cli, char* buffer, uint32_t len){
	pthread_mutex_lock(&cli->networkSendLock);
		if (cli->networkSendLockBool)
			send(cli->getSocket(),buffer, len,MSG_NOSIGNAL);
	pthread_mutex_unlock(&cli->networkSendLock);
}


void* thread_Listen(){
	struct sockaddr_in stSockAddr;
    int SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(-1 == SocketFD)
    {
      perror("can not create socket");
      exit(EXIT_FAILURE);
    }

    memset(&stSockAddr, 0, sizeof(struct sockaddr_in));

    stSockAddr.sin_family = AF_INET;
    stSockAddr.sin_port = htons(11142);
    stSockAddr.sin_addr.s_addr = INADDR_ANY;

    if(-1 == bind(SocketFD,(const struct sockaddr *)&stSockAddr, sizeof(struct sockaddr_in)))
    {
      perror("error bind failed");
      close(SocketFD);
      exit(EXIT_FAILURE);
    }

    if(-1 == listen(SocketFD, 10))
    {
      perror("error listen failed");
      close(SocketFD);
      exit(EXIT_FAILURE);
    }

	for(;;){
		int ConnectFD = accept(SocketFD, NULL, NULL);
		cerr<<"connected time "<<SDL_GetTicks()<<endl;

		if(0 > ConnectFD){
			perror("error accept failed");
			close(SocketFD);
			exit(EXIT_FAILURE);
		}


		//create new client
		
		Client* cli = new Client(ConnectFD);
		cerr<<"connected "<<endl;
		networkControl->addClient(cli);

		cerr<<"added to clients"<<endl;
		pthread_create(&(cli->listenThread), NULL, (void*(*)(void*))thread_Recive, cli);
		cerr<<"begin listen"<<endl;
	}

    close(SocketFD);
	return 0;
}



void* thread_Recive(Client* client){
	printf ("recv test....\n");
	int recsize;
	uint32_t timeout = 0;

	while(!client->isDisconnecting()){

		recsize = recv(client->getSocket(), (client->inputnetworkBuf->networkBuf) + client->inputnetworkBuf->recived, 512,0);

		if (recsize < 0){
			
			fprintf(stderr, "RECV  ERROR***********************\n");
			client->disconnect();
			break;
		}
		if (recsize)
			timeout = 0;

		client->inputnetworkBuf->recived +=recsize;
		bool switchdone = false;
		while (!switchdone){
			usleep(1000);
			pthread_mutex_lock(&client->networkBufLock);
			//************************************
			//CRITICAL
			if (!client->parsingoutput){
				switchdone = client->switchBuffer();
			}
			//CRITICAL
			//************************************
			pthread_mutex_unlock(&client->networkBufLock);
		}
		timeout+=1;
		if (timeout < 20)
			usleep(400);
		else{
			client->disconnect();
			cerr<<"timeout"<<endl;
			break;
		}
	}

	
	pthread_mutex_lock(&client->networkSendLock);
		client->networkSendLockBool = false;
	pthread_mutex_unlock(&client->networkSendLock);
	
	shutdown(client->getSocket(), SHUT_RDWR);

	close(client->getSocket());
	networkControl->removeClient(client);

	cerr<<"Delete"<<endl;
	delete client;
	
	pthread_exit(0);
}


void* ReadBuffer(Client* client){
		if (client->outputnetworkBuf->recived > 0){
			//************************************
			//CRITICAL
			pthread_mutex_lock(&client->networkBufLock);
			client->parsingoutput = true;
			pthread_mutex_unlock(&client->networkBufLock);
			//CRITICAL
			//************************************
			//if(printbufferbool)
			uint32_t delta = parseBuffer(client,client->outputnetworkBuf->recived);

			memmove(client->outputnetworkBuf->networkBuf, client->outputnetworkBuf->networkBuf+ delta, client->outputnetworkBuf->recived- delta);

			client->outputnetworkBuf->recived -= delta;

			//************************************
			//CRITICAL
			pthread_mutex_lock(&client->networkBufLock);
			client->parsingoutput = false;
			pthread_mutex_unlock(&client->networkBufLock);
			//CRITICAL
			//************************************
		}


}

uint32_t parseBuffer(Client* client, uint32_t len){
	char* buffer = client->outputnetworkBuf->networkBuf;
	uint32_t offset = 0;
	uint32_t remaning = 0;
	printBuffer(buffer,len);
	while (offset < len && !client->isDisconnecting()){
		SerialData* temp = (SerialData*)(buffer + offset);
		if(temp->_size < sizeof(SerialData))
			client->disconnect();
		
		if (len - offset >= sizeof(uint32_t)*2 && temp->_size <= len - offset){
			//cerr<<"parse single "<<endl;
			remaning = len - offset;
			switch(temp->_type)
			{
				case SerialType::SerialTime:{
					SerialTime* st = (SerialTime*)(buffer+offset);

					char message[sizeof(SerialTime)];
					memset(message,0,sizeof(SerialTime));

					SerialTime* data = (SerialTime*)(message);
					data->_type = SerialType::SerialTime;
					data->_size = sizeof(SerialTime);
					data->time = SDL_GetTicks();
					data->local = st->local;
					send(client->getSocket(),message,sizeof(SerialTime),0);

					break;
				}
				case SerialType::SerialReqJoin:{
					SerialReqJoin* st = (SerialReqJoin*)(buffer+offset);
					client->setPlayerId(st->_unitId);
					client->initTransfere();

					break;
				}
				case SerialType::SerialAddComponent:{
					SerialAddComponent* st = (SerialAddComponent*)(buffer+offset);
					SObj* obj = networkControl->getObj(st->_unitId);
					if(!obj){
						//cerr<<"SerialType::SerialAddComponent: obj not found "<<endl;
						break;
					}
					//TaskAddComponent * t = new TaskAddComponent(obj, new CompSpawnNode(10000,1,0));
					TaskRemoveObj * t = new TaskRemoveObj(st->_unitId);
					networkControl->addTaskToObj(t,st->_unitId);

					break;
				}
				case SerialType::SerialInput:{
					cerr<<"SerialType::SerialInput"<<endl;
					SerialInput* st = (SerialInput*)(buffer+offset);
					SObj* obj = networkControl->getObj(st->_unitId);
					if(!obj){
						break;
					}
					
					SerialInputPayload* data = NULL;
					switch (((SerialInputPayload*)(&st[1]))->_type){
						case SERIALINPUT::SerialInputCastPower:{
							data = (SerialInputPayload*)malloc(sizeof(SerialInputCastPower));
							memcpy(data, &st[1], sizeof(SerialInputCastPower));
							cerr<<"cp data"<<endl;
							break;
						}
						default:{
							break;
						}
						
					}
					TaskAcceptInput * t = new TaskAcceptInput(st->_unitId, data);
					networkControl->addTaskToObj(t,st->_unitId);

					break;
				}
				case SerialType::SerialCmdCreateObj:{
					SerialCmdCreateObj* st = (SerialCmdCreateObj*)(buffer+offset);
					
					//TaskAddComponent * t = new TaskAddComponent(obj, new CompSpawnNode(10000,1,0));
					cerr<<"st "<<st<<endl;
					TaskCreateObj* t = new TaskCreateObj(0, st->_template, true);
					SerialObjData* sd = (SerialObjData*)st->_data;
					cerr<<"sd "<<sd<<endl;
					while(sd->_dataType){
						switch(sd->_dataType){
							case OBJDATA::position: {
								t->addPos(new SPos((SerialObjDataPos*)sd));	
								sd = &(((SerialObjDataPos*)sd)[1]);
							}
							default:{
								t->addData((OBJDATA::Enum)((SerialObjDataValue*)sd)->_dataType,((SerialObjDataValue*)sd)->_value);
								sd = &(((SerialObjDataValue*)sd)[1]);
							}
						}
						
						cerr<<"WARNING shoudl be empty "<<sd->_dataType<<endl;
						break;
					}
					SerialObjComp* sc = (SerialObjComp*) (&sd[1]);
					cerr<<"sc "<<sc<<endl;
					while(sc->_compType){
						cerr<<"WARNING shoudl also be empty "<<sc->_compType<<endl;
				
						//component size is max the min of remaning buffer of the size of the package
						int32_t cmpSize = min(remaning, temp->_size);
						t->addComponent(createComponent(sc, &cmpSize));
						if(cmpSize){
							sc += cmpSize; //increasse by the buffer read by the factory
						}else{
							cerr<<"parse buffer SerialType::SerialCmdCreateObj WARNING this should not happen"<<endl;
							break;
						}
					}
					
					networkControl->addTaskToObj(t,0);

					break;
				}
				default:{
					cerr<<"error no packet parse function defined"<<endl;
					offset = len;
					break;
				}
			}
			offset += temp->_size;
		}else{
			cerr<<"servermissing data"<<endl;
			break;
		}
			
	}
	//cerr<<"end parse  "<<endl;
	return offset;
}
