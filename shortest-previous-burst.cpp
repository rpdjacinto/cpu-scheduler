#include "shortest-previous-burst.h"

ShortestPreviousBurst::ShortestPreviousBurst( vector<Pcb> processes, float weight ) {
	this->weight = weight;
	setProcesses(processes);
	setInactiveProcesses(processes);
	setWaitingQueue(processes);
	setTime(0);
}

int ShortestPreviousBurst::selectProcess() {
	vector<Pcb> readyQueue = getReadyQueue();
	for( int i = 0; i < readyQueue.size(); i++ ) {
		int burst = 0;
		vector<Pcb> processes = getProcesses();
		for( int i = 0; i < processes.size(); i++ ) {
			if( processes[i].getPid == readyQueue[i].getPid )
				burst = processes[i].getCpuBursts[processes[i].getCurrentCpuBurst()];
		}
		calculateAverageBursts( burst, readyQueue[i] );
	}

	if( readyQueue.size() > 0 ) {
		int selectedPid= -1;
		float shortestBurst = readyQueue.front().getAverageBursts();
		for( int i = 0; i < readyQueue.size(); i++) {
			if( readyQueue[i].getAverageBursts() < shortestBurst ) {
				shortestBurst = readyQueue[i].getAverageBursts();
				selectedPid = readyQueue[i].getPid();
			}
		}
		return selectedPid;
	} else return -1;
}

float ShortestPreviousBurst::getWeight() {
	return this->weight;
}

void ShortestPreviousBurst::setWeight( float weight ) {
	this->weight = weight;
}

void ShortestPreviousBurst::calculateAverageBursts( int burstLength, Pcb &pcb ){
	pcb.setAverageBursts( this->weight * burstLength + ( 1 - this->weight ) * pcb.getAverageBursts() );
}
