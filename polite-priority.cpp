#include "polite-priority.h"

using namespace std;

PolitePriority::PolitePriority() {
}

PolitePriority::PolitePriority( vector<Pcb> processes, int timeSlice = 0 ) {
	setProcesses(processes);
	setInactiveProcesses(processes);
	setWaitingQueue(processes);
	setTime(0);
}

int PolitePriority::selectProcess() {
	return 0;
}

int PolitePriority::getTimeSlice() { 
	return this->timeSlice;
}

void PolitePriority::setTimeSlice( int timeSlice ) {
	this->timeSlice = timeSlice;
}