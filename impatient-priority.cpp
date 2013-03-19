#include "impatient-priority.h"

using namespace std;

ImpatientPriority::ImpatientPriority() {
}

ImpatientPriority::ImpatientPriority( vector<Pcb> processes ) : SchedulingAlgorithm(processes) {
	setWaitingQueue(processes);
}

int ImpatientPriority::selectProcess() {
	vector<Pcb> readyQueue = getReadyQueue();
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
		setReadyQueue( readyQueue );
		return 0;
	} return -1;
}


