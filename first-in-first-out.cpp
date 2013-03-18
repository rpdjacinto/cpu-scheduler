#include "first-in-first-out.h"

FirstInFirstOut::FirstInFirstOut(vector<Pcb> processes){
	setProcesses(processes);
	setReadyQueue(processes);
	setWaitingQueue(processes);
	this->timeCount = 0;
}

<<<<<<< HEAD
int firstInFirstOut::run(){
	while(getWaitingQueue().size() != 0){
		cout << "\nWaiting Queue: " << getWaitingQueue().size() << "\nIO Bursts:" << getWaitingQueue()[0].ioBursts[0] << "\n" << "\nPID:" << getWaitingQueue()[0].pid << "\n";
		ioBurst();
		//cpuBurst();
=======
void FirstInFirstOut::startProcesses() {
>>>>>>> 0f416ea7263977f1a3f32d942dfcb0e2faaba27e
		
	}
	return 0;
}

void firstInFirstOut::startProcesses() {
	
}

void FirstInFirstOut::selectProcess()
{

}

void FirstInFirstOut::cpuBurst() {
}

<<<<<<< HEAD
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
=======
void FirstInFirstOut::ioBurst() {
}

void FirstInFirstOut::output() {
}
>>>>>>> 0f416ea7263977f1a3f32d942dfcb0e2faaba27e
