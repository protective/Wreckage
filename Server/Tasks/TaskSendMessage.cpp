
#include "TaskSendMessage.h"
#include "../ModelLayer/Messages/Message.h"
#include "../Processor/Processor.h"
#include "../ModelLayer/SObj.h"


TaskSendMessage::TaskSendMessage(OBJID toId, Message* message) :
Task(0) {
	_toId = toId;
	_message = message;
}

uint32_t TaskSendMessage::execute(){
	SObj* toobj = _processor->getObj(_toId);
	if(toobj)
		toobj->message(_message->_type, _message);
	delete _message;
	return COMMAND_FINAL;
}

TaskSendMessage::~TaskSendMessage() {
}

