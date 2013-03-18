#include "scheduling-algorithm.h"

using namespace std;

SchedulingAlgorithm::SchedulingAlgorithm() {
}

SchedulingAlgorithm::SchedulingAlgorithm( vector<Pcb> processes ) {
	this->processes = processes;
}


int SchedulingAlgorithm::run() {
	while(1) {
		startProcesses();
		selectProcess();
		cpuBurst();
		ioBurst();
	}
	output();
	return 0;
}

void SchedulingAlgorithm::startProcesses() {
}

void SchedulingAlgorithm::cpuBurst() {
}

void SchedulingAlgorithm::ioBurst() {
}

void SchedulingAlgorithm::output() {
}



/*
 * Accessor methods
 */

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
