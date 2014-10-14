/* 
 * File:   SGlobals.cpp
 * Author: karsten
 * 
 * Created on 23. april 2011, 09:41
 */
#include "SGlobals.h"
#include "ModelLayer/SWorld.h"
#include "NetworkLayer/NetworkControler.h"


pthread_mutex_t lockNetInput  = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lockClientList= PTHREAD_MUTEX_INITIALIZER;

SWorld* world = NULL;
NetworkControler* networkControl = new NetworkControler();