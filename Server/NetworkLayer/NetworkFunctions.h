/* 
 * File:   NetworkFunctions.h
 * Author: karsten
 *
 * Created on 14. oktober 2014, 19:01
 */

#ifndef NETWORKFUNCTIONS_H
#define	NETWORKFUNCTIONS_H

#include "../BInclude.h"
#include "../../GShare/GFunctions.h"
#include "../ModelLayer/enums.h"
#include "../Network/Serialize.h"
#include "../Network/InputSerial.h"

class Client;
void* thread_Listen();
void* thread_Listen_websock();
void* thread_Recive(Client* client);

#endif	/* NETWORKFUNCTIONS_H */

