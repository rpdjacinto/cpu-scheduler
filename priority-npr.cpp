#include "INCLUDES/priority-npr.h"

using namespace std;

PriorityNpr::PriorityNpr() {
	this->threshold = 10;
	algorithmName = "NON PREEMPTIVE PRIORITY";
}

PriorityNpr::PriorityNpr( vector<Pcb> processes ) : SchedulingAlgorithm(processes) {
	this->threshold = 10;
	algorithmName = "NON PREEMPTIVE PRIORITY";
}

int PriorityNpr::selectProcess() {
	vector<Pcb> vipQueue = this->vipQueue;
	vector<Pcb> readyQueue = getReadyQueue();
	for( int i = 0; i < readyQueue.size(); i++ ) {
		if( readyQueue[i].getWaitingTime() >= this->threshold ) {
			vipQueue.push_back( readyQueue[i] );
			readyQueue.erase( readyQueue.begin() + i );
			setReadyQueue( readyQueue );
		}
	}
	if (isCurrentProcessSet == false){
		if( vipQueue.size() > 0 ) {
			int highestPriority = vipQueue[0].getPriority();
			int selectedProcessIndex = 0;
			for( int i = 0; i < vipQueue.size(); i++ ) {
				if( vipQueue[i].getPriority() < highestPriority ) {
					highestPriority = vipQueue[i].getPriority();
					selectedProcessIndex = i;
				}
			}
			setCurrentProcess( readyQueue[selectedProcessIndex] );
			readyQueue.erase( readyQueue.begin() + selectedProcessIndex );
			setReadyQueue( readyQueue );
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
void PriorityNpr::printVerbose(string message)
{

	if (verbose == 1)
	{
		cout << "\n[priority-npr.cpp] " << message;
	}
}