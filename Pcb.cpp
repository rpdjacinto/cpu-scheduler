#include "pcb.h"

Pcb::Pcb(int pid, int tarq, int priority, vector<int> cpuBursts, vector<int> ioBursts){
	this->pid = pid;
	this->tarq = tarq;
	this->priority = priority;
	this->cpuBursts = cpuBursts;
	this->ioBursts = ioBursts;
};

float Pcb::getAverageBursts() {
	return this->averageBursts;
}

void Pcb::setAverageBursts( float averageBursts ) {
	this->averageBursts = averageBursts;
}