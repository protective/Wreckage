#include "NetworkFunctions.h"
#include "NetworkControler.h"


#include "Client.h"
#include "ClientWebSock.h"

#include "../ModelLayer/Components/ComponentFactory.h"
#include "../ModelLayer/Components/SComponent.h"
#include "../ModelLayer/Components/CompReSpawnable/CompReSpawnable.h"
#include "../ModelLayer/Components/CompSpawnNode/CompSpawnNode.h"



#include "../Tasks/TaskAddComponent.h"
#include "../Tasks/TaskRemoveObj.h"
#include "../Tasks/TaskAcceptInput.h"
#include "../Tasks/TaskAddClientView.h"
#include "../Tasks/TaskCreateObj.h"
#include "ClientWebSock.h"

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


void* thread_Listen_websock(){
	struct sockaddr_in stSockAddr;
    int SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(-1 == SocketFD)
    {
      perror("can not create socket");
      exit(EXIT_FAILURE);
    }

    memset(&stSockAddr, 0, sizeof(struct sockaddr_in));

    stSockAddr.sin_family = AF_INET;
    stSockAddr.sin_port = htons(11143);
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
		cerr<<"connected Websocket time "<<SDL_GetTicks()<<endl;

		if(0 > ConnectFD){
			perror("error accept failed");
			close(SocketFD);
			exit(EXIT_FAILURE);
		}


		//create new client
		
		ClientWebSock* cli = new ClientWebSock(ConnectFD);
		cerr<<"connected "<<endl;
		//blocks
		cli->handshake();
		
		networkControl->addClient(cli);

		cerr<<"added to clients"<<endl;
		pthread_create(&(cli->listenThread), NULL, (void*(*)(void*))thread_Recive, cli);
		cerr<<"begin listen"<<endl;
	}

    close(SocketFD);
	return 0;
}


void* thread_Recive(Client* client){
	int recsize;
	uint32_t timeout = 0;

	while(!client->isDisconnecting()){

		recsize = recv(client->getSocket(), (client->inputnetworkBuf->networkBuf) + client->inputnetworkBuf->recived, 512,0);
		cerr<<"rec timeout="<<timeout<<endl;
		if (recsize < 0){
			
			fprintf(stderr, "RECV  ERROR WEBSOCK***************\n");
			client->disconnect();
			break;
		}
		if (recsize){
			timeout = 0;
		}
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
		if (timeout < 200000)
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
