#include "first-in-first-out.h"

FirstInFirstOut::FirstInFirstOut(vector<Pcb> processes){
	setProcesses(processes);
	setReadyQueue(processes);
	setWaitingQueue(processes);
	this->timeCount = 0;
}

void FirstInFirstOut::selectProcess(){

}