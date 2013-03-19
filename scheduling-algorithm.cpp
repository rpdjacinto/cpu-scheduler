#include "scheduling-algorithm.h"

using namespace std;

SchedulingAlgorithm::SchedulingAlgorithm() {
}

SchedulingAlgorithm::SchedulingAlgorithm( vector<Pcb> processes ) {
	this->processes = processes;
	this->inactiveProcesses = processes;
	this->time = 0;
}


int SchedulingAlgorithm::run() {
	while( !allProcessesCompleted() ) {
		startProcesses();
		if(getReadyQueue().size() != 0){
			selectProcess();
		}
		cpuBurst();
		ioBurst();
		setTime( getTime() + 1 );
		printVerbose("How many cpu bursts: "); cout << getCurrentProcess().getCpuBursts()[getCurrentProcess().getCurrentCpuBurst()];
		printVerbose("Waiting Queue Size: "); cout <<  getWaitingQueue().size();
		printVerbose("Ready Queue Size: "); cout <<  getReadyQueue().size();
		printVerbose("Completed Queue Size: "); cout << getCompletedProcesses().size();
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
	vector<int> tempCpuBursts;
	if(currentProcess.getCpuBursts().size() != 0){
		tempCpuBursts = currentProcess.getCpuBursts();
		tempCpuBursts[currentProcess.getCurrentCpuBurst()]--;
		currentProcess.setCpuBursts(tempCpuBursts);
		if(currentProcess.getCpuBursts()[currentProcess.getCurrentCpuBurst()] == 0){
			if(currentProcess.getIoBursts().size() == currentProcess.getCurrentIoBurst()){
				completedProcesses.push_back(currentProcess);
			}else{
				Pcb tempCurrentProcess = currentProcess;
				int tempCpuBurst = tempCurrentProcess.getCurrentCpuBurst();
				tempCurrentProcess.setCurrentCpuBurst(++tempCpuBurst);
				waitingQueue.push_back(tempCurrentProcess);
			}
		}
		printVerbose("Current PID: "); cout << currentProcess.getPid();
	}
}

void SchedulingAlgorithm::ioBurst() {
	
	vector<Pcb> tempWaitingQueue = getWaitingQueue();
	vector<Pcb> tempReadyQueue = getReadyQueue();
	vector<int> tempIoBursts;
	for( int i = 0; i < tempWaitingQueue.size(); i++ ) {
		vector<int> ioBursts = tempWaitingQueue[i].getIoBursts();
		ioBursts[tempWaitingQueue[i].getCurrentIoBurst()]--;
		tempWaitingQueue[i].setIoBursts( ioBursts );
		printVerbose("IO Bursts: "); cout << ioBursts[tempWaitingQueue[i].getCurrentIoBurst()]; 
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

Pcb SchedulingAlgorithm::getCurrentProcess(){
	return this->currentProcess;
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

void SchedulingAlgorithm::setCurrentProcess(Pcb currentProcess){
	this->currentProcess = currentProcess;
}

void SchedulingAlgorithm::printVerbose(string message)
{
	//if (verbose == 1)
	//{
		cout<<"\n[scheduling-algorithm.cpp] "<<message;
	//}
}
