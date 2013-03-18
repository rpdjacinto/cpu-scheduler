#include "first-in-first-out.h"

FirstInFirstOut::FirstInFirstOut(vector<Pcb> processes){
	setProcesses(processes);
	setReadyQueue(processes);
<<<<<<< HEAD
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
=======
>>>>>>> parent of 250b72f... Added some functionality to FIFO.
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
}

void firstInFirstOut::output() {
<<<<<<< HEAD
}

void firstInFirstOut::selectProcess(){

}
=======
void FirstInFirstOut::ioBurst() {
}

void FirstInFirstOut::output() {
}
>>>>>>> 0f416ea7263977f1a3f32d942dfcb0e2faaba27e
=======
}
>>>>>>> parent of 250b72f... Added some functionality to FIFO.
