#include "round-robin.h"

using namespace std;

RoundRobin::RoundRobin() {
	algorithmName = "ROUND ROBIN";
}

RoundRobin::RoundRobin( vector<Pcb> processes, int timeSlice ) : SchedulingAlgorithm(processes) {
	this->timeSlice = timeSlice;
	algorithmName = "ROUND ROBIN";
}

int RoundRobin::selectProcess() {
	vector<Pcb> readyQueue = getReadyQueue();
	if( (getCurrentProcess().getCurrentCpuTime() >= this->timeSlice) && (getCurrentProcess().getCurrentCpuTime() % this->timeSlice == 0)) {
		readyQueue.push_back( getCurrentProcess() );
		isCurrentProcessSet = false;
	}
	if(isCurrentProcessSet == false){
		if( readyQueue.size() > 0 ) {
			setCurrentProcess( readyQueue[0] );
			readyQueue.erase( readyQueue.begin() );
			isCurrentProcessSet = true;
		}
	}
	setReadyQueue( readyQueue );
	return 0;
}

int RoundRobin::getTimeSlice() { 
	return this->timeSlice;
}

void RoundRobin::setTimeSlice( int timeSlice ) {
	this->timeSlice = timeSlice;
}

/*
 * @Override verbose function
 */
void RoundRobin::printVerbose(string message)
{

	if (verbose == 1)
	{
		cout << "\n[round-robin.cpp] " << message;
	}
}
