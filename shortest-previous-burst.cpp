#include "shortest-previous-burst.h"

ShortestPreviousBurst::ShortestPreviousBurst( vector<Pcb> processes, float weight ) {
	this->weight = weight;
}

void ShortestPreviousBurst::selectProcess() {
	vector<Pcb> readyQueue = getReadyQueue();
	if( readyQueue.size() > 0 ) {
		int selectedProcessIndex = 0;
		float shortestBurst = readyQueue.front().getAverageBursts();
		for( int i = 0; i < readyQueue.size; i++) {
			if( readyQueue[i].getAverageBursts() < shortestBurst ) {
				shortestBurst = readyQueue[i].getAverageBursts();
				selectedProcessIndex = i;
			}
		}
	}
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
