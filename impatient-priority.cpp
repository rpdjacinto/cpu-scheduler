#include "INCLUDES/impatient-priority.h"

using namespace std;

ImpatientPriority::ImpatientPriority() {
	this->threshold = 10;
}

ImpatientPriority::ImpatientPriority( vector<Pcb> processes ) : SchedulingAlgorithm(processes) {
	this->threshold = 10;
	algorithmName = "IMPATIENT PRIORITY";
}

int ImpatientPriority::selectProcess() {
	vector<Pcb> readyQueue = getReadyQueue();
	for( int i = 0; i < readyQueue.size(); i++ ) {
		if( readyQueue[i].getCurrentWaitingTime() >= this->threshold ) {
			this->vipQueue.push_back( readyQueue[i] );
			readyQueue.erase( readyQueue.begin() + i );
			setReadyQueue( readyQueue );
		}
	}
	if (isCurrentProcessSet == false) {
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
			setReadyQueue( readyQueue );
			isCurrentProcessSet = true;
			return 0;
		} 
	}
	return -1;
}


/*
 * @Override verbose function
 */
void ImpatientPriority::printVerbose(string message)
{

	if (verbose == 1)
	{
		cout << "\n[impatient-priority.cpp] " << message;
	}
}
