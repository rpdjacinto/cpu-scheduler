#include "INCLUDES/pcb.h"

/*
 * Contructors
 */
Pcb::Pcb() {
}

Pcb::Pcb(int pid, int tarq, int priority, int tncpu, vector<int> cpuBursts, vector<int> ioBursts){
	
	/* From workload file
	 */
	this->pid = pid;
	this->tarq = tarq;
	this->priority = priority;
	this->cpuBursts = cpuBursts;
	this->ioBursts = ioBursts;
	this->tncpu = tncpu;

	/* Initialize
	 */
	this->averageBursts = cpuBursts[0];
	this->currentCpuBurst = 0;
	this->currentIoBurst = 0;
	this->currentCpuTime = 0;
	this->currentIoTime = 0;
	this->age = 0;

	this->waitingTime = 0;
	this->executionTime = 0;
};


/*
 * Accessors
 */
int Pcb::getPid() {
	return this->pid;
}
int Pcb::getTarq() {
	return this->tarq;
}
int Pcb::getPriority() {
	return this->priority;
}
int Pcb::getAge() {
	return this->age;
}
float Pcb::getAverageBursts() {
	return this->averageBursts;
}
int Pcb::getCurrentCpuTime() {
	return this->currentCpuTime;
}
int Pcb::getCurrentIoTime() {
	return this->currentIoTime;
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

/*
 * Mutators
 */
void Pcb::setAverageBursts( float averageBursts ) {
	this->averageBursts = averageBursts;
}
void Pcb::setCurrentCpuTime( int currentCpuTime ) {
	this->currentCpuTime = currentCpuTime;
}
void Pcb::setCurrentIoTime( int currentIoTime ) {
	this->currentIoTime = currentIoTime;
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

/* Result methods
 */
void Pcb::setWaitingTime(int time) {
	this->waitingTime = time;
}
int Pcb::getWaitingTime() {
	return this->waitingTime;
}
void Pcb::setExecutionTime(int time) {
	this->executionTime = time;
}
int Pcb::getExecutionTime() {
	return executionTime;
}
