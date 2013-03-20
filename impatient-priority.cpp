#include "INCLUDES/impatient-priority.h"

using namespace std;

ImpatientPriority::ImpatientPriority() {
}

ImpatientPriority::ImpatientPriority( vector<Pcb> processes ) : SchedulingAlgorithm(processes) {
}

int ImpatientPriority::selectProcess() {
	vector<Pcb> readyQueue = getReadyQueue();
	int selectedProcessIndex = 0;
	selectedProcessIndex = 0;
	int highestPriority;
	if(readyQueue.size() != 0){
		highestPriority = readyQueue[0].getPriority();
	
		for( int i = 0; i < readyQueue.size(); i++ ) {
			if( readyQueue[i].getPriority() < highestPriority ) {
				highestPriority = readyQueue[i].getPriority();
				selectedProcessIndex = i;
			}
		}

		if( readyQueue[selectedProcessIndex].getPriority() < getCurrentProcess().getPriority() || isCurrentProcessSet == false) {

			if(isCurrentProcessSet != false)
				readyQueue.push_back( getCurrentProcess() );
			setCurrentProcess( readyQueue[selectedProcessIndex] );
			readyQueue.erase( readyQueue.begin() + selectedProcessIndex );
			isCurrentProcessSet = true;
		
		}
	}
	
	

	setReadyQueue( readyQueue );

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
