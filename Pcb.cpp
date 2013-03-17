#include "pcb.h"

Pcb::Pcb(int pid, int tarq, int priority, vector<int> cpuBursts, vector<int> ioBursts){
	pid = pid;
	tarq = tarq;
	priority = priority;
	cpuBursts = cpuBursts;
	ioBursts = ioBursts;
};

float Pcb::getAverageBursts() {
	return this->averageBursts;
}

void Pcb::setAverageBursts( float averageBursts ) {
	this->averageBursts = averageBursts;
}