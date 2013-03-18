#include "first-in-first-out.h"

firstInFirstOut::firstInFirstOut(vector<Pcb> processes){
	setProcesses(processes);
	setReadyQueue(processes);
	setWaitingQueue(processes);
	this->timeCount = 0;
}

int firstInFirstOut::run(){
	while(getWaitingQueue().size() != 0){
		cout << "\nWaiting Queue: " << getWaitingQueue().size() << "\nIO Bursts:" << getWaitingQueue()[0].ioBursts[0] << "\n" << "\nPID:" << getWaitingQueue()[0].pid << "\n";
		ioBurst();
		//cpuBurst();
		
	}
	return 0;
}

void firstInFirstOut::startProcesses() {
	
}

void firstInFirstOut::cpuBurst() {
}

void firstInFirstOut::ioBurst() {
	
	if(getWaitingQueue().size() != 0){

		vector<Pcb> tempWaitingQueue = getWaitingQueue();

		if(tempWaitingQueue[0].ioBursts[0] != 0){
			tempWaitingQueue[0].ioBursts[0] = tempWaitingQueue[0].ioBursts[0] - 1;
			if(tempWaitingQueue[0].ioBursts[0] != 0){
				if(tempWaitingQueue[0].cpuBursts.size() != 0){
					vector<Pcb> tempReadyQueue = getReadyQueue();
					//tempReadyQueue.push_back(tempWaitingQueue[0]);
					tempWaitingQueue.push_back(tempWaitingQueue[0]);
					setReadyQueue(tempReadyQueue);
				}else{
					vector<Pcb> tempCompletedProcesses = getCompletedProcesses();
					tempCompletedProcesses.push_back(tempWaitingQueue[0]);
					setcompletedProcesses(tempCompletedProcesses);
				}
				tempWaitingQueue.erase(tempWaitingQueue.begin());
				tempWaitingQueue.shrink_to_fit();
			}	
		}
		this->timeCount++;
		setWaitingQueue(tempWaitingQueue);
	}
}

void firstInFirstOut::output() {
}

void firstInFirstOut::selectProcess(){

}