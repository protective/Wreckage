/* 
 * File:   CGlobals.cpp
 * Author: karsten
 * 
 * Created on 24. april 2011, 13:54
 */

#include "DGlobals.h"

ConnectionStruct connection;
uint32_t tTime = 0;
pthread_mutex_t lockInput= PTHREAD_MUTEX_INITIALIZER;
uint32_t playerId;
