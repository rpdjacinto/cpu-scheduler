#include "round-robin.h"

RoundRobin::RoundRobin(vector<Pcb> processes, int quantumTime){
  setProcesses(processes);
	setInactiveProcesses(processes);
	setWaitingQueue(processes);
	setTime(0);
};

int RoundRobin::SelectProcess(){
	vector <Pcb> readyQueue = getReadyQueue();
	float timeSlice = (1.0 / (readyQueue.size()));
	float CpuBurst;
	//setCurrentProcess(getReadyQueue().front());

	while(readyQueue.size() > 0){
		setCurrentProcess(getReadyQueue().front());
		for (int i = 0; i < readyQueue.size(); i++){
			if  (readyQueue[i].getCpuBurst(readyQueue[i].getCurrentCpuBurst()) <= quantumTime){
				readyQueue.erase(readyQueue.begin());
				setReadyQueue(readyQueue);
			}//if
			else{
				readyQueue[i].getCpuBurst(readyQueue[i].getCurrentCpuBurst()) = CpuBurst;
				CpuBurst = CpuBurst - timeSlice;
				readyQueue.push_back(readyQueue.begin());
				setReadyQueue(readyQueue);
			}//else
		}//for
 

	}//if
} //select process


int RoundRobin::getQuantumTime() { 
	return this->quantumTime;
}//int

void RoundRobin::setQuantumTime( int quantumTime ) {
	this->quantumTime = quantumTime;
} //void

