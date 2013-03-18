#include "scheduling-algorithm.h"

using namespace std;

SchedulingAlgorithm::SchedulingAlgorithm() {
}

SchedulingAlgorithm::SchedulingAlgorithm( vector<Pcb> processes ) {
	this->processes = processes;
	this->time = 0;
}


int SchedulingAlgorithm::run() {
	while( !allProcessesCompleted() ) {
		startProcesses();
		selectProcess();
		cpuBurst();
		ioBurst();
		setTime( getTime() + 1 );
		cout << "\nTime: " << getTime() << "\n";
		
	}
	output();
	return 0;
}

void SchedulingAlgorithm::startProcesses() {
	for( int i = 0; i < this->inactiveProcesses.size(); i++ ) {
		if( this->time == inactiveProcesses[i].getTarq() ) {
			this->readyQueue.push_back( inactiveProcesses[i] );
			this->inactiveProcesses.erase( this->inactiveProcesses.begin() + i );
		}
	}
}

void SchedulingAlgorithm::cpuBurst() {
	currentProcess.getCpuBursts()[currentProcess.getCurrentCpuBurst()]--;
	if(currentProcess.getCpuBursts()[currentProcess.getCurrentCpuBurst()] == 0){
		if(currentProcess.getIoBursts().size() == currentProcess.getCurrentIoBurst() + 1){
			completedProcesses.push_back(currentProcess);
		}else{
			Pcb tempCurrentProcess = currentProcess;
			int tempCpuBurst = tempCurrentProcess.getCurrentCpuBurst();
			tempCurrentProcess.setCurrentCpuBurst(++tempCpuBurst);
			waitingQueue.push_back(tempCurrentProcess);
		}
	}
}

void SchedulingAlgorithm::ioBurst() {
	
	vector<Pcb> tempWaitingQueue = getWaitingQueue();
	vector<Pcb> tempReadyQueue = getReadyQueue();
	for( int i = 0; i < tempWaitingQueue.size(); i++ ) {
		cout << "\nStarting Iteration\n";
		cout << "\nWaiting Queue Size: " << tempWaitingQueue.size() << "\n";
		vector<int> ioBursts = tempWaitingQueue[i].getIoBursts();
		ioBursts[tempWaitingQueue[i].getCurrentIoBurst()]--;	
		cout << "\nIO Bursts: " << ioBursts[0] << "\n";
		tempWaitingQueue[i].setIoBursts( ioBursts );
		
		if( tempWaitingQueue[i].getIoBursts()[tempWaitingQueue[i].getCurrentIoBurst()] == 0 ) {
			tempWaitingQueue[i].setCurrentIoBurst( tempWaitingQueue[i].getCurrentIoBurst() + 1 );
			tempReadyQueue.push_back( tempWaitingQueue[i] );
			tempWaitingQueue.erase( tempWaitingQueue.begin() + i );
		}

		setWaitingQueue( tempWaitingQueue );
		setReadyQueue( tempReadyQueue );
	}
}

void SchedulingAlgorithm::output() {

}

bool SchedulingAlgorithm::allProcessesCompleted() {
	if( this->processes.size() == this->completedProcesses.size() ) return true;
	else return false;
}



/*
 * Accessor methods
 */

int SchedulingAlgorithm::getTime() {
	return this->time;
}

vector<Pcb> SchedulingAlgorithm::getProcesses() {
	return this->processes;
}

vector<Pcb> SchedulingAlgorithm::getInactiveProcesses() {
	return this->inactiveProcesses;
}

vector<Pcb> SchedulingAlgorithm::getReadyQueue() {
	return this->readyQueue;
}

vector<Pcb> SchedulingAlgorithm::getWaitingQueue() {
	return this->waitingQueue;
}

vector<Pcb> SchedulingAlgorithm::getCompletedProcesses() {
	return this->completedProcesses;
}

/*
 * Mutator methods
 */

void SchedulingAlgorithm::setTime( int time ) { 
	this->time = time;
}

void SchedulingAlgorithm::setProcesses(vector<Pcb> processes){
	this->processes = processes;
}

void SchedulingAlgorithm::setInactiveProcesses(vector<Pcb> processes){
	this->inactiveProcesses = processes;
}

void SchedulingAlgorithm::setReadyQueue(vector<Pcb> processes){
	this->readyQueue = processes;
}

void SchedulingAlgorithm::setWaitingQueue(vector<Pcb> processes){
	this->waitingQueue = processes;
}

void SchedulingAlgorithm::setcompletedProcesses(vector<Pcb> processes){
	this->completedProcesses = processes;
}
