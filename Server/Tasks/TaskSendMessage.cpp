
#include "TaskSendMessage.h"
#include "../ModelLayer/Messages/Message.h"
#include "../Processor/Processor.h"
#include "../ModelLayer/SObj.h"


TaskSendMessage::TaskSendMessage(SObj* toId, Message* message) :
Task(0) {
	_toId = toId;
	_message = message;
}

uint32_t TaskSendMessage::execute(){
	_toId->message(_message->_type, _message);
	delete _message;
	return COMMAND_FINAL;
}

TaskSendMessage::~TaskSendMessage() {
}

