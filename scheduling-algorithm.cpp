#include "scheduling-algorithm.h"

using namespace std;

SchedulingAlgorithm::SchedulingAlgorithm() {
}

SchedulingAlgorithm::SchedulingAlgorithm( vector<Pcb> processes ) {
	this->processes = processes;
}


int SchedulingAlgorithm::run() {
	while( !allProcessesCompleted() ) {
		startProcesses();
		selectProcess();
		cpuBurst();
		ioBurst();
	}
	output();
	return 0;
}

void SchedulingAlgorithm::startProcesses() {
	for( int i = 0; i < this->inactiveProcesses.size; i++ ) {
		if( this->time == inactiveProcesses[i].getTarq() ) this->readyQueue.push_back( inactiveProcesses[i] );
	}
}

void SchedulingAlgorithm::cpuBurst() {

}

void SchedulingAlgorithm::ioBurst() {

}

void SchedulingAlgorithm::output() {

}

bool SchedulingAlgorithm::allProcessesCompleted() {
	if( this->processes.size == this->completedProcesses.size ) return true;
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
