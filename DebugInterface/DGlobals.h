/* 
 * File:   CGlobals.h
 * Author: karsten
 *
 * Created on 24. april 2011, 13:54
 */

#ifndef DGLOBALS_H
#define	DGLOBALS_H

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
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_opengl.h"
#include <pthread.h>
#include <cstdlib>

using namespace std;

struct ConnectionStruct{
	int SocketFD;
	char* messagebuffer;
	char* messagepointer;
	bool connected;
	pthread_t listenThread;
};

extern pthread_mutex_t lockInput;
extern ConnectionStruct connection;
extern uint32_t tTime;

extern uint32_t playerId;

#endif	/* DGLOBALS_H */

