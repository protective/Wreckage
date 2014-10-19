#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_opengl.h"
#include <pthread.h>
#include <cstdlib>
#include <cstdlib>
#include "../Server/ModelLayer/enums.h"
#include "DFunctions.h"



using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
	int argteam = 1;
	cerr<<"argc"<<argc<<endl;
	string argip = "127.0.0.1";
	
	Connect(argip,argteam, 42);
	
	uint32_t len = sizeof(SerialAddComponent)+  sizeof(SerialCompSpawnNode);
	char message[len];
	memset(message,0,len);

	SerialAddComponent* data = (SerialAddComponent*)(message);
	data->_type = SerialType::SerialAddComponent;
	data->_size = len;
	data->_unitId = 16777224; //TODO BIG TODO FIX THIS SOOON
	data->_compid = COMPID::reSpawnable;
	SerialCompSpawnNode* comp  = (SerialCompSpawnNode*)(message + sizeof(SerialAddComponent));
	comp->_spawnTemplate= 1;
	comp->_spawnTime = 10000;
	comp->_spawn = 0;
	send(connection.SocketFD,message,len,0);

	
	
	return 0;
}

