
#include "TaskRemoveClientView.h"

#include "../Processor/Processor.h"

TaskRemoveClientView::TaskRemoveClientView(uint32_t clientId) :
Task(0){
	clientId = clientId;
}

uint32_t TaskRemoveClientView::execute() {
	
	_processor->removeClientView(clientId);
	return COMMAND_FINAL;
}

TaskRemoveClientView::~TaskRemoveClientView() {
}

