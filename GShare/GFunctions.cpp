/* 
 * File:   GFunctions.cpp
 * Author: karsten
 * 
 * Created on 23. april 2011, 10:43
 */

#include <math.h>

#include "GFunctions.h"
#include "../Server/NetworkLayer/ObjSerial.h"
#include "../Network/Serialize.h"
#include "../Network/InputSerial.h"


#include "Enums.h"

void printBuffer(unsigned char* buffer, uint32_t len){
	int offset = 0;
	int loopoffset = 0;
	if (printbufferbool){
		while (offset < len){
			//cerr<<"offset "<<offset<<endl;
			SerialData* temp = (SerialData*)(buffer + offset);
			if (len - offset >= sizeof(uint32_t)*2 && temp->_size <= len - offset){
				cerr<<"parse len "<< temp->_size<<endl;
				SerialData* st = (SerialData*)(buffer+offset);
				cerr<<"Recived ********************"<<endl
						<<"\ttype "<<st->_type <<endl
						<<"\tsize "<<st->_size<<endl;

				switch(temp->_type)
				{
					case SerialType::SerialTime:{
						SerialTime* st = (SerialTime*)(buffer+offset);
						cerr<<"Recived RegTime*************"<<endl
						<<"\tTime "<<st->time<<endl;
						cerr<<"****************************"<<endl;

						break;
					}
					case SerialType::SerialReqJoin:{
						SerialReqJoin* st = (SerialReqJoin*)(buffer+offset);
						cerr<<"Recived RegJoin*************"<<endl
						<<"\tid "<<st->_unitId<<endl
						<<"\tpass "<<st->_pass<<endl;
						cerr<<"****************************"<<endl;
						break;
					}
					case SerialType::SerialAddComponent:{
						SerialAddComponent* st = (SerialAddComponent*)(buffer+offset);
						cerr<<"Recived SerialAddComponent*************"<<endl
						<<"\tid "<<st->_unitId<<endl
						<<"\tcompid "<<st->_compid<<endl;
						cerr<<"****************************"<<endl;
						break;
					}
					case SerialType::SerialInput:{
						SerialInput* st = (SerialInput*)(buffer+offset);
						cerr<<"Recived SerialInput*************"<<endl
						<<"\tunit "<<st->_unitId<<endl;
						SerialInputPayload* si = (SerialInputPayload*)(&st[1]);
						cerr<<"\ttype "<<si->_type<<endl;

						switch(si->_type){
							case SERIALINPUT::SerialInputCastPower:{
								SerialInputCastPower* scp = (SerialInputCastPower*)(&st[1]);
								cerr<<"\tpower "<<scp->_power<<endl
								<<"\ttarget "<<scp->_target<<endl;
								break;
							}
							case SERIALINPUT::SerialIndputSetCompValue:{
								SerialInputPayload* scp = (SerialInputPayload*)(&st[1]);
								
								break;
							}
							default:{
								cerr<<"UNKNOWN Serial Input Type"<<endl;
							}
						}
						cerr<<"****************************"<<endl;
						break;
					}
					case SerialType::SerialObjAll:{
						SerialObjAll* st = (SerialObjAll*)(buffer+offset);
						cerr<<"Recived SerialObjAll*************"<<endl
						<<"\tid "<<st->_id<<endl
						<<"\txitems "<<st->_xitems<<endl;
						for (int i = 0 ; i < st->_xitems ; i++){
							SerialDataKeyVal* sd = (SerialDataKeyVal*)(buffer+offset+ (sizeof(SerialDataKeyVal) * i));
							cerr<<"\t\t key "<<sd->_key<<" value "<<sd->_val<<endl;
						}
						
						cerr<<"****************************"<<endl;
						
						break;
					}
					case SerialType::SerialCmdCreateObj:{
						SerialCmdCreateObj* st = (SerialCmdCreateObj*)(buffer+offset);
						cerr<<"Recived SerialCmdCreateObj*************"<<endl
						<<"\ttemplate "<<st->_template<<endl;
						SerialObjData* sd = (SerialObjData*)st->_data;
						while(sd->_dataType){
							switch(sd->_dataType){
								case OBJDATA::position: {
									cerr<<"\t\tOBJDATA::position"<<endl
									<<"\t\t\tx="<<((SerialObjDataPos*)sd)->_x
											<<" y="<<((SerialObjDataPos*)sd)->_y
											<<" z="<<((SerialObjDataPos*)sd)->_z
											<<" d="<<((SerialObjDataPos*)sd)->_d<<endl;
									sd+= sizeof(SerialObjDataPos);
									break;
								}
								default:{
									cerr<<"\t\ttype"<<sd->_dataType<<endl
									<<"\t\tvalue="<<((SerialObjDataValue*)sd)->_value<<endl;
									sd+= sizeof(SerialObjDataValue);
									break;								
								}
							}
						}
						SerialObjComp* sc = (SerialObjComp*)(&sd[1]);
						//while(sc->_compType){

						//	sd += sizeof(SerialObjComp);
						//}
						
						cerr<<"****************************"<<endl;
						
						break;
					}
					default:{
						cerr<<"error recived unknown packate in GLobal"<<endl;
						offset = len;
						break;
					}
				}
				cerr<<"offset += "<<temp->_size<<endl;
		
				offset += temp->_size;

			}else{
				cerr<<"missing data "<<endl;
				break;
			}
		}
	}
}

uint32_t myrandom(uint32_t min,uint32_t max){

	return ((rand()+ (rand()<<16)) % (1+max-min)) + min;
}

int32_t Deg(double x, double y){

	if(x > 0 && y == 0)
		return 0;
	else if(x > 0 && y < 0 )
		return 180 * atan((0-y)/x)/PI;
	else if(x == 0 && y < 0)
		return 90;
	else if(x < 0 && y < 0)
		return (180 * atan((0-x)/(0-y))/PI) +90;
	else if(x < 0 && y == 0)
		return 180;
	else if(x < 0 && y > 0)
		return (180 * atan(y/(0-x))/PI) +180;
	else if(x == 0 && y > 0)
		return 270;
	else if(x > 0 && y > 0)
		return (180 * atan(x/y)/PI) +270;
	return 0;
}

double VektorUnitX(uint32_t deg){
	if (deg >= 0 || deg < 360)
		return MyCos[deg];
	else
		cerr<<"ERROR out of degs rage"<<endl;
	return 0;
}

double VektorUnitY(uint32_t deg){
	if (deg >= 0 || deg < 360)
		return MySin[deg];
	else
		cerr<<"ERROR out of degs rage"<<endl;
	return 0;
}

uint32_t Rangecord(int32_t p1x,  int32_t p1y, int32_t p2x,int32_t p2y)
{
	p1x = p1x/100;
	p2x = p2x/100;
	p1y = p1y/100;
	p2y = p2y/100;

	return 100* sqrt(((p1x - p2x)*(p1x - p2x)) + ((p1y - p2y)*(p1y - p2y)));
}


bool LinePointIntersect(int32_t p1x,  int32_t p1y, int32_t p2x,int32_t p2y, int32_t pointx, int32_t pointy, int32_t range){
double a = 100 * Rangecord(p1x,p1y,p2x,p2y);
	if(a < range/2){
		int32_t x1 = p1x - pointx;
		int32_t y1 = p1y - pointy;
		int32_t x2 = p1x+p2x - pointx;
		int32_t y2 = p1y+p2y - pointy;

		int32_t dx = x2 - x1;
		int32_t dy = y2 - y1;
		double dr = sqrt((dx*dx)+(dy*dy));
		double D = x1*y2 - x2*y1;
		double dis = ((range/2)*(range/2))*(dr*dr)-(D*D);

		if(dis >= 0)
			return true;
		else
			return false;
	}
}

int32_t dirDiff(uint32_t d1, uint32_t d2){
	int32_t dd = d1 - d2;
	if(dd < 0)
		dd += 36000;

	if(dd > 18000)
		return  36000 - dd;
	else
		return dd;
}

