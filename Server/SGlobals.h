/* 
 * File:   SGlobals.h
 * Author: karsten
 *
 * Created on 23. april 2011, 09:41
 */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <pthread.h>
#include <SDL/SDL.h>
#include <list>
#include <vector>
#include <stack>
#include <map>

#define NRTHREADS 1
#define FRAMERATE 25

#ifndef SGLOBALS_H
#define	SGLOBALS_H
using namespace std;

class SWorld;
class NetworkControler;
extern SWorld* world;
extern NetworkControler* networkControl;
extern pthread_mutex_t lockNetInput;
extern pthread_mutex_t lockClientList;

#endif	/* SGLOBALS_H */

