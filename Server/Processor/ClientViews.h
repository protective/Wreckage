/* 
 * File:   PClient.h
 * Author: karsten
 *
 * Created on 3. november 2014, 22:07
 */

#ifndef CLIENTVIEWS_H
#define	CLIENTVIEWS_H

#include "../BInclude.h"

struct ClientViews {
	
	ClientViews(uint32_t id){
		id = id;
	}
	ClientViews(ClientViews& s){
		id = s.id;
	}
	uint32_t id;
};

#endif	/* CLIENTVIEWS_H */

