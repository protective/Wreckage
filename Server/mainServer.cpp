/* 
 * File:   mainServer.cpp
 * Author: karsten
 *
 * Created on 13. oktober 2014, 19:55
 */

#include <cstdlib>
#include "BInclude.h"

#include "SGlobals.h"
#include "Processor/Processor.h"
#include "ModelLayer/SWorld.h"
#include "NetworkLayer/NetworkControler.h"
#include "NetworkLayer/NetworkFunctions.h"
#include "ModelLayer/Components/CompSpawnNode/CompSpawnNode.h"
#include "ModelLayer/Components/CompReSpawnable/CompReSpawnable.h"

using namespace std;

pthread_cond_t  procesConBegin = PTHREAD_COND_INITIALIZER;
pthread_cond_t  procesConallReady = PTHREAD_COND_INITIALIZER;
pthread_t procesThreads[NRTHREADS];
list<Processor*> processors;
int threadsReady;
/*
 * 
 */
int main(int argc, char** argv) {

	
	
	printbufferbool = true;
	
	pqxx::connection con("dbname= wreckage user=karsten");
	
	pqxx::work w(con);
	pqxx::result r = w.exec("select EXISTS(select * from information_schema.tables where table_name='objs');");
	if(!r[0][0].as<bool>()){
		cerr<<"MAIN INIT main OBJ table do not exist create"<<endl;
		w.exec("create table objs (objId BIGINT PRIMARY KEY, isTemplate BOOL);");
	}

	r = w.exec("select EXISTS(select * from information_schema.tables where table_name='comp');");
	if(!r[0][0].as<bool>()){
		cerr<<"MAIN INIT main component table do not exist create"<<endl;
		w.exec("create table comp (objId BIGINT, compId INT, PRIMARY KEY(objId, compId));");
	}	
	w.commit();
	
	CompSpawnNode csn;
	csn.dbTableInit(con);
	CompReSpawnable crsn;
	crsn.dbTableInit(con);
	
	world = new SWorld(NULL);
	SDL_Init(SDL_INIT_TIMER);
	
	for(int i = 0; i < NRTHREADS;i++)
	{
		cerr<<"create processor"<<endl;
		Processor* temp = new Processor();
		cerr<<"p "<<temp<<endl;
		processors.push_back(temp);
	}	

	

	pthread_t listenThread;
	pthread_create(&listenThread, NULL, (void*(*)(void*))thread_Listen, NULL);
	srand((unsigned)time(0));
        cerr<<"hello world"<<endl;
	//LOAD GAME DATA
		
			cerr<<"done load game"<<endl;
			
	//tempU->ActivateAI();
	list<Processor*>::iterator it = processors.begin();
	for (int i = 0 ; i< NRTHREADS; i++){
		Processor* temp = *it++;
		pthread_create(&procesThreads[i], NULL, &Processor::workThreadFunction, temp);
	}
	networkControl = new NetworkControler();

	//GAME LOOP************************
	uint32_t timer;
	uint32_t fpstimer = 0;
	uint32_t fpscounter= 0;
	uint32_t fpswait = 1000/FRAMERATE; // 25 fps men korigere lidt for skeduleren
	while(true){

		timer = SDL_GetTicks();
		networkControl->readBuffers();
		//************
		if ( SDL_GetTicks() > fpstimer +10000){
			fpstimer = SDL_GetTicks();
			cerr<<"fps "<<fpscounter/10<<endl;
			fpscounter = 0;
		}
		world->proces(0);
		while (SDL_GetTicks() < timer+fpswait)
			usleep(100);
		//*************


			threadsReady = 0;
			//cerr<<"done"<<endl;


		fpscounter +=1;


	}

	cerr<<"end do join join"<<endl;
	//END GAME LOOP********************
	pthread_join(listenThread, NULL);
	cerr<<"SERVER EXIT"<<endl;
	return 0;
}

