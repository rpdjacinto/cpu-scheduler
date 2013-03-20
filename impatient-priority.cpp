#include "impatient-priority.h"

using namespace std;

ImpatientPriority::ImpatientPriority() {
}

ImpatientPriority::ImpatientPriority( vector<Pcb> processes ) : SchedulingAlgorithm(processes) {
}

int ImpatientPriority::selectProcess() {
	vector<Pcb> readyQueue = getReadyQueue();
	int highestPriority = readyQueue[0].getPriority();
	int selectedProcessIndex = 0;
	for( int i = 0; i < readyQueue.size(); i++ ) {
		if( readyQueue[i].getPriority() < highestPriority ) {
			highestPriority = readyQueue[i].getPriority();
			selectedProcessIndex = i;
		}
	}
	if( readyQueue[selectedProcessIndex].getPriority() < getCurrentProcess().getPriority() ) {
		setCurrentProcess( readyQueue[selectedProcessIndex] );
		readyQueue.erase( readyQueue.begin() + selectedProcessIndex );
		setReadyQueue( readyQueue );
	}
	return 0;
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
