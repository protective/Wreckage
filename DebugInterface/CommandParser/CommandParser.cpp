/* 
 * File:   CommandParser.cpp
 * Author: karsten
 * 
 * Created on 25. oktober 2014, 14:37
 */

#include <list>

#include "CommandParser.h"
#include "../DFunctions.h"
#include "../../Network/Serialize.h"
#include "../../Network/InputSerial.h"

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


void parseSerialCmdAddObj(list<string> cmd){
	uint32_t size = sizeof(SerialCmdCreateObj);
	
	SerialCmdCreateObj* si = (SerialCmdCreateObj*)malloc(size);
	si->_type = SerialType::SerialCmdCreateObj;
	si->_size = size;
	si->_template = atoi(cmd.front().c_str());
	cmd.pop_front();
	si->_data[0]._dataType = 0;
	si->_comp[0]._compType = 0;
	
	for (int i = 0; i < size / sizeof(uint32_t); i+= 1) {
		cerr<<((uint32_t*)si)[i]<<endl;;

	}

	send(connection.SocketFD,si,size,0);
	free(si);
	cerr<<"WTF done"<<endl;
}


typedef void (*CmdObjSwitch)(list<string>); // function pointer type
typedef std::map<std::string, CmdObjSwitch> CmdObjSwitch_map;

void parseCmdObj(list<string> cmd){
	CmdObjSwitch_map _map;
	_map["add"] = parseSerialCmdAddObj;
	
	string s = cmd.front();
	cmd.pop_front();
	if(_map.find(s) != _map.end()){
		_map[s](cmd);
	}else
		cerr<<"parseCmd not found>"<<s<<"<"<<endl;
}

typedef void (*CmdSwitch)(list<string>); // function pointer type
typedef std::map<std::string, CmdSwitch> CmdSwitch_map;

void parseCmd(list<string> cmd){
	CmdSwitch_map _map;
	_map["obj"] = parseCmdObj;
	
	string s = cmd.front();
	cmd.pop_front();
	if(_map.find(s) != _map.end()){
		_map[s](cmd);
	}else
		cerr<<"parseCmd not found>"<<s<<"<"<<endl;
		
}

typedef void (*InputSwitch)(SerialInput*, list<string>); // function pointer type
typedef std::map<std::string, InputSwitch> InputSwitch_map;

void parseSerialInput(list<string> cmd){
	InputSwitch_map _map;
	_map["cp"] = parseSerialInputCastPower;
	
	SerialInput* data = (SerialInput*)malloc(sizeof(SerialInput));
	data->_unitId = atoi(cmd.front().c_str()); 
	cmd.pop_front();
	string s = cmd.front();
	cmd.pop_front();
	if(_map.find(s) != _map.end()){
		_map[s](data,cmd);
	}else
		cerr<<"cmd not found>"<<s<<"<"<<endl;
	free(data);

}


typedef void (*MessageSwitch)(list<string>); // function pointer type
typedef std::map<std::string, MessageSwitch> MessageSwitch_map;


void parse(list<string> cmd){
	MessageSwitch_map _map;
	_map["inp"] = parseSerialInput;
	_map["cmd"] = parseCmd;
	
	string s = cmd.front();
	cmd.pop_front();
	if(_map.find(s) != _map.end()){
		_map[s](cmd);
	}else
		cerr<<"cmd not found>"<<s<<"<"<<endl;

}