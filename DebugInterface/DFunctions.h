/* 
 * File:   DFunctions.h
 * Author: karsten
 *
 * Created on 18. oktober 2014, 20:02
 */

#ifndef DFUNCTIONS_H
#define	DFUNCTIONS_H

#include <unistd.h>
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
#include "../Network/Serialize.h"
#include "DGlobals.h"

#include "../Server/ModelLayer/enums.h"
#include "../GShare/GFunctions.h"

using namespace std;

void* Connect(string ip, uint32_t playerid, uint32_t pass);
void* Disconnect();
void* thread_Recive();
uint32_t getTime();
uint32_t parseBuffer(char* buffer, uint32_t len);

#endif	/* DFUNCTIONS_H */

