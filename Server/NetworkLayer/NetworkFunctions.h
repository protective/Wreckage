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
class Client;
void* thread_Listen();
void* thread_Recive(Client* client);
uint32_t parseBuffer(Client* client,uint32_t len);
void* ReadBuffer(Client* client);
void sendtoC(Client* cli, char* buffer, uint32_t len);

#endif	/* NETWORKFUNCTIONS_H */

