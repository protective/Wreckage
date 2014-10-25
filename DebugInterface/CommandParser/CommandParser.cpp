/* 
 * File:   CommandParser.cpp
 * Author: karsten
 * 
 * Created on 25. oktober 2014, 14:37
 */

#include <list>

#include "CommandParser.h"
#include "../DFunctions.h"
#include "../../Network/InputSerial.h"
#include "../../Network/Serialize.h"
#include <map>
void parseSerialInputCastPower(SerialInput* data, list<string> cmd){
	uint32_t size = sizeof(SerialInput)+ sizeof(SerialInputCastPower);
	
	SerialInput* si = (SerialInput*)malloc(size);
	cerr<<"si>"<<si<<endl;
	si->_type = SerialType::SerialInput;
	si->_size = size;
	si->_unitId = data->_unitId;
	
	SerialInputCastPower* cp = (SerialInputCastPower*)(&si[1]);
	cerr<<"size="<<sizeof(SerialInput)<<endl;
	cerr<<"cp>"<<cp<<endl;
	cp->_type = SERIALINPUT::SerialInputCastPower;
	cp->_size = sizeof(SerialInputCastPower);
	cp->_power = atoi(cmd.front().c_str());
	cmd.pop_front();
	cp->_target= atoi(cmd.front().c_str());
	cmd.pop_front();
	
	for (int i = 0; i < size / sizeof(uint32_t); i+= 1) {
		cerr<<((uint32_t*)si)[i]<<endl;;

	}

	
	send(connection.SocketFD,si,size,0);
	free(si);
	cerr<<"WTF done"<<endl;
}


typedef void (*InputSwitch)(SerialInput*, list<string>); // function pointer type
typedef std::map<std::string, InputSwitch> InputSwitch_map;

void parseSerialInput(list<string> cmd){
	InputSwitch_map _map;
	_map["cp"] = parseSerialInputCastPower;
	
	SerialInput data;
	data._unitId = atoi(cmd.front().c_str()); 
	cmd.pop_front();
	string s = cmd.front();
	cmd.pop_front();
	if(_map.find(s) != _map.end()){
		_map[s](&data,cmd);
	}else
		cerr<<"cmd not found>"<<s<<"<"<<endl;


}


typedef void (*MessageSwitch)(list<string>); // function pointer type
typedef std::map<std::string, MessageSwitch> MessageSwitch_map;


void parse(list<string> cmd){
	MessageSwitch_map _map;
	_map["inp"] = parseSerialInput;
	
	string s = cmd.front();
	cmd.pop_front();
	if(_map.find(s) != _map.end()){
		_map[s](cmd);
	}else
		cerr<<"cmd not found>"<<s<<"<"<<endl;

}