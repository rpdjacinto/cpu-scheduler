#include "INCLUDES/polite-priority.h"

using namespace std;

PolitePriority::PolitePriority() {
	this->timeSlice = 4;
}

PolitePriority::PolitePriority( vector<Pcb> processes, int timeSlice ) : SchedulingAlgorithm(processes) {
	this->timeSlice = timeSlice;
}

int PolitePriority::selectProcess() {
	vector<Pcb> readyQueue = getReadyQueue();
	if( getCurrentProcess().getCurrentCpuTime() == this->timeSlice ) {
		readyQueue.push_back( getCurrentProcess() );
		isCurrentProcessSet = false;
	}
	for( int i = 0; i < readyQueue.size(); i++ ) {
		if( readyQueue[i].getCurrentWaitingTime() >= this->threshold ) {
			this->vipQueue.push_back( readyQueue[i] );
			readyQueue.erase( readyQueue.begin() + i );
		}
	}
	if(isCurrentProcessSet == false){
		if( this->vipQueue.size() > 0 ) {
			int highestPriority = this->vipQueue[0].getPriority();
			int selectedProcessIndex = 0;
			for( int i = 0; i < this->vipQueue.size(); i++ ) {
				if( this->vipQueue[i].getPriority() < highestPriority ) {
					highestPriority = this->vipQueue[i].getPriority();
					selectedProcessIndex = i;
				}
			}
			this->vipQueue[selectedProcessIndex].setCurrentWaitingTime(0);
			setCurrentProcess( this->vipQueue[selectedProcessIndex] );
			this->vipQueue.erase( this->vipQueue.begin() + selectedProcessIndex );
			isCurrentProcessSet = true;
			return 0;
		} else if( readyQueue.size() > 0 ) {
			int highestPriority = readyQueue[0].getPriority();
			int selectedProcessIndex = 0;
			for( int i = 0; i < readyQueue.size(); i++ ) {
				if( readyQueue[i].getPriority() < highestPriority ) {
					highestPriority = readyQueue[i].getPriority();
					selectedProcessIndex = i;
				}
			}
			readyQueue[selectedProcessIndex].setCurrentWaitingTime(0);
			setCurrentProcess( readyQueue[selectedProcessIndex] );
			readyQueue.erase( readyQueue.begin() + selectedProcessIndex );
			isCurrentProcessSet = true;
		}
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