#include "pcb.h"

Pcb::Pcb(int pid, int tarq, int priority, vector<int> cpuBursts, vector<int> ioBursts){
	this->pid = pid;
	this->tarq = tarq;
	this->priority = priority;
	this->cpuBursts = cpuBursts;
	this->ioBursts = ioBursts;
};

int Pcb::getPid() {
	return this->pid;
}
int Pcb::getStatus() {
	return this->status;
}
int Pcb::getTarq() {
	return this->tarq;
}
int Pcb::getPriority() {
	return this->priority;
}
float Pcb::getAverageBursts() {
	return this->averageBursts;
}
int Pcb::getCurrentCpuBurst() {
	return this->currentCpuBurst;
}
int Pcb::getCurrentIoBurst() {
	return this->currentIoBurst;
}
vector<int> Pcb::getCpuBursts() {
	return this->cpuBursts;
}
vector<int> Pcb::getIoBursts() {
	return this->ioBursts;
}
int Pcb::getCpuBurst(int index) {
	return this->cpuBursts[index];
}
void Pcb::setPid( int pid ) {
	this->pid = pid;
}
void Pcb::setStatus( int status ) {
	this->status = status;
}
void Pcb::setTarq( int tarq ) {
	this->tarq = tarq;
}
void Pcb::setPriority( int priority ) {
	this->priority = priority;
}
void Pcb::setAverageBursts( float averageBursts ) {
	this->averageBursts = averageBursts;
}
void Pcb::setCurrentCpuBurst( int currentCpuBurst ) {
	this->currentCpuBurst = currentCpuBurst;
}
void Pcb::setCurrentIoBurst( int currentIoBurst ) {
	this->currentIoBurst = currentIoBurst;
}
void Pcb::setCpuBursts( vector<int> cpuBursts ) {
	this->cpuBursts = cpuBursts;
}
void Pcb::setIoBursts( vector<int> ioBursts ) {
	this->ioBursts = ioBursts;
}
void Pcb::setCpuBurst(int burst, int index) {
	this->cpuBursts[index] = burst;
}
