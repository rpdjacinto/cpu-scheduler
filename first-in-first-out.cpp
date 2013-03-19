#include "first-in-first-out.h"

FirstInFirstOut::FirstInFirstOut(vector<Pcb> processes){
	setProcesses(processes);
	setInactiveProcesses(processes);
	setTime(0);
}

int FirstInFirstOut::selectProcess(){
	
	
	if(getCurrentProcess().getCpuBursts().size() == 0){
		setCurrentProcess(getReadyQueue().front());
		vector<Pcb> tempReady = getReadyQueue();
		tempReady.erase(tempReady.begin());
		setReadyQueue(tempReady);
	}else if(getCurrentProcess().getCpuBursts()[getCurrentProcess().getCurrentCpuBurst()] == 0){
		setCurrentProcess(getReadyQueue().front());
		vector<Pcb> tempReady = getReadyQueue();
		tempReady.erase(tempReady.begin());
		setReadyQueue(tempReady);
	}
	
	return -1;
}
