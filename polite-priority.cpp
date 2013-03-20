#include "polite-priority.h"

using namespace std;

PolitePriority::PolitePriority() {
}

PolitePriority::PolitePriority( vector<Pcb> processes, int timeSlice ) : SchedulingAlgorithm(processes) {
}

int PolitePriority::selectProcess() {
	vector<Pcb> readyQueue = getReadyQueue();
	if( getCurrentProcess().getCurrentCpuTime() == this->timeSlice ) {
		readyQueue.push_back( getCurrentProcess() );
	}
	if( readyQueue.size() > 0 ) {
		int highestPriority = readyQueue[0].getPriority();
		int selectedProcessIndex = 0;
		for( int i = 0; i < readyQueue.size(); i++ ) {
			if( readyQueue[i].getPriority() < highestPriority ) {
				highestPriority = readyQueue[i].getPriority();
				selectedProcessIndex = i;
			}
		}
		setCurrentProcess( readyQueue[selectedProcessIndex] );
		readyQueue.erase( readyQueue.begin() + selectedProcessIndex );
	}
	setReadyQueue( readyQueue );
	return 0;
}

int PolitePriority::getTimeSlice() { 
	return this->timeSlice;
}

void PolitePriority::setTimeSlice( int timeSlice ) {
	this->timeSlice = timeSlice;
}

/*
 * @Override verbose function
 */
void PolitePriority::printVerbose(string message)
{

	if (verbose == 1)
	{
		cout << "\n[polite-priority.cpp] " << message;
	}
}