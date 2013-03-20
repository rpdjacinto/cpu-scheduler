#include "first-in-first-out.h"


FirstInFirstOut::FirstInFirstOut(vector<Pcb> processes) : SchedulingAlgorithm(processes) {
}

int FirstInFirstOut::selectProcess(){

	/* If current process has 0 cpu bursts then set currentProcess to next process
	 */
	if(getCurrentProcess().getCpuBursts().size() == 0){
		setCurrentProcess(getReadyQueue().front());
		
		vector<Pcb> tempReady = getReadyQueue();
		tempReady.erase(tempReady.begin());
		setReadyQueue(tempReady);
	}
	else {
		/* If current process has had cpu for a time equal to its current cpu burst
		 * then set currentProcess to next process
		 */
		if(getCurrentProcess().getCpuBurst(getCurrentProcess().getCurrentCpuBurst()) <= getCurrentProcess().getCurrentCpuTime()){

			setCurrentProcess(getReadyQueue().front());
			
			vector<Pcb> tempReady = getReadyQueue();
			tempReady.erase(tempReady.begin());
			setReadyQueue(tempReady);
		}
		else {
		
			// if(getCurrentProcess().getCpuBurst(getCurrentProcess().getCurrentCpuBurst()) < getCurrentProcess().getCurrentCpuTime()){
				
			// 	if(getReadyQueue().size() != 0){
			// 		setCurrentProcess(getReadyQueue().front());
			// 		vector<Pcb> tempReady = getReadyQueue();
			// 		tempReady.erase(tempReady.begin());
			// 		setReadyQueue(tempReady);
			// 	}
			// }
		}
	}

	return -1;
}

/*
 * @Override verbose function
 */
void FirstInFirstOut::printVerbose(string message)
{

	if (verbose == 1)
	{
		cout << "\n[first-in-first-out.cpp] " << message;
	}
}
