
#include "TaskAddClientView.h"

#include "../Processor/Processor.h"

TaskAddClientView::TaskAddClientView(uint32_t clientId) :
Task(0){
	clientId = clientId;
	
}

uint32_t TaskAddClientView::execute() {
	
	_processor->addClientView(clientId);
	return COMMAND_FINAL;
}

TaskAddClientView::~TaskAddClientView() {
}

