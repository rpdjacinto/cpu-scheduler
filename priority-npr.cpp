#include "priority-npr.h"

using namespace std;

PriorityNpr::PriorityNpr() {
}

PriorityNpr::PriorityNpr( vector<Pcb> processes ) {
	setProcesses(processes);
	setInactiveProcesses(processes);
	setWaitingQueue(processes);
	setTime(0);
}

int PriorityNpr::selectProcess() {
	return 0;
}