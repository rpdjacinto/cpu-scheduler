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
		int selectedProcessIndex = 0;
		float shortestBurst = readyQueue.front().getAverageBursts();
		for( int i = 0; i < readyQueue.size(); i++) {
			if( readyQueue[i].getAverageBursts() < shortestBurst ) {
				shortestBurst = readyQueue[i].getAverageBursts();
				selectedProcessIndex = i;
			}
		}
		if( getCurrentProcess().getCurrentCpuTime == getCurrentProcess().getCpuBursts()[getCurrentProcess().getCurrentCpuBurst()] ) {
			setCurrentProcess( readyQueue[selectedProcessIndex] );
			readyQueue.erase( readyQueue.begin() + selectedProcessIndex );
			setReadyQueue( readyQueue );
		}
		return 0;
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


/*
 * @Override verbose function
 */
void ShortestPreviousBurst::printVerbose(string message)
{

	if (verbose == 1)
	{
		cout << "\n[shortest-previous-burst.cpp] " << message;
	}
}