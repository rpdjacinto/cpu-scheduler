#include "impatient-priority.h"

using namespace std;

ImpatientPriority::ImpatientPriority() {
}

ImpatientPriority::ImpatientPriority( vector<Pcb> processes ) {
	setProcesses(processes);
	setInactiveProcesses(processes);
	setWaitingQueue(processes);
	setTime(0);
}

int ImpatientPriority::selectProcess() {
	return 0;
}