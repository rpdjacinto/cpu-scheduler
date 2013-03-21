#include "INCLUDES/shortest-previous-burst.h"

ShortestPreviousBurst::ShortestPreviousBurst( vector<Pcb> processes, float weight ) : SchedulingAlgorithm(processes) {
	this->weight = weight;
	algorithmName = "SHORTEST PREVIOUS BURST";
	threshold = 3;
}

int ShortestPreviousBurst::selectProcess() {
	vector<Pcb> readyQueue = getReadyQueue();

	/* Ageing, put pcb over the threshold waiting time in the vip queue
	 */
	for( int i = 0; i < readyQueue.size(); i++ ) {
		if( readyQueue[i].getCurrentWaitingTime() >= this->threshold ) {
			vipQueue.push_back( readyQueue[i] );
			readyQueue.erase( readyQueue.begin() + i );
			setReadyQueue( readyQueue );
		}
	}
	
	for( int i = 0; i < readyQueue.size(); i++ ) {
		calculateAverageBursts( readyQueue[i].getCpuBurst(readyQueue[i].getCurrentCpuBurst()), readyQueue[i] );
	}
	for( int i = 0; i < vipQueue.size(); i++ ) {
		calculateAverageBursts( vipQueue[i].getCpuBurst(vipQueue[i].getCurrentCpuBurst()), vipQueue[i] );
	}

	
	if (isCurrentProcessSet == false){

		if( vipQueue.size() > 0 ) {
			int shortestBurst = vipQueue[0].getCpuBursts()[vipQueue[0].getCurrentCpuBurst()];
			int selectedProcessIndex = 0;
			for( int i = 0; i < vipQueue.size(); i++ ) {
				if( vipQueue[i].getCpuBursts()[vipQueue[i].getCurrentCpuBurst()] < shortestBurst ) {
					shortestBurst = vipQueue[i].getCpuBurst(vipQueue[i].getCurrentCpuBurst());
					selectedProcessIndex = i;
				}
			}
			//cout << endl << "Selected Process: " << vipQueue[selectedProcessIndex].getPid() << endl;
			setCurrentProcess( vipQueue[selectedProcessIndex] );
			vipQueue.erase( vipQueue.begin() + selectedProcessIndex );

			isCurrentProcessSet = true;
			return 0;
		} 
		else if( readyQueue.size() > 0 ) {
			int shortestBurst = readyQueue[0].getCpuBursts()[readyQueue[0].getCurrentCpuBurst()];
			int selectedProcessIndex = 0;
			for( int i = 0; i < readyQueue.size(); i++ ) {
				if( readyQueue[i].getCpuBursts()[readyQueue[i].getCurrentCpuBurst()] < shortestBurst ) {
					shortestBurst = readyQueue[i].getCpuBurst(readyQueue[i].getCurrentCpuBurst());
					selectedProcessIndex = i;
				}
			}
			//cout << endl << "Selected Process: " << readyQueue[selectedProcessIndex].getPid() << endl;
			setCurrentProcess( readyQueue[selectedProcessIndex] );
			readyQueue.erase( readyQueue.begin() + selectedProcessIndex );
			setReadyQueue( readyQueue );
			isCurrentProcessSet = true;
			return 0;
		} 
	}
	return -1;

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
