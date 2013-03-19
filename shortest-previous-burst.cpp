#include "shortest-previous-burst.h"

ShortestPreviousBurst::ShortestPreviousBurst( vector<Pcb> processes, float weight ) : SchedulingAlgorithm(processes) {
	this->weight = weight;
}

int ShortestPreviousBurst::selectProcess() {
	vector<Pcb> readyQueue = getReadyQueue();

	//TODO: Clean up this monstrosity.
	for( int i = 0; i < readyQueue.size(); i++ ) {
		int burst = 0;
		vector<Pcb> processes = getProcesses();
		for( int j = 0; j < processes.size(); j++ ) {
			if( processes[j].getPid() == readyQueue[i].getPid() )
				burst = processes[j].getCpuBursts()[processes[j].getCurrentCpuBurst()];
		}
		calculateAverageBursts( burst, readyQueue[i] );
	}

	if( readyQueue.size() > 0 ) {
		int selectedProcessIndex = 0;
		float shortestBurst = readyQueue.front().getAverageBursts();
		for( int i = 0; i < readyQueue.size(); i++) {
			if( readyQueue[i].getAverageBursts() < shortestBurst ) {
				shortestBurst = readyQueue[i].getAverageBursts();
				selectedProcessIndex = i;
			}
		}
		setCurrentProcess( readyQueue[selectedProcessIndex] );
		readyQueue.erase( readyQueue.begin() + selectedProcessIndex );
		setReadyQueue( readyQueue );
		return 0;
	} return -1;
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
