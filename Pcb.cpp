#include "pcb.h"


Pcb::Pcb() {
}
Pcb::Pcb(int pid, int tarq, int priority, vector<int> cpuBursts, vector<int> ioBursts){
	this->pid = pid;
	this->tarq = tarq;
	this->priority = priority;
	this->cpuBursts = cpuBursts;
	this->ioBursts = ioBursts;
	this->currentCpuBurst = 0;
	this->currentIoBurst = 0;
	this->tncpu = 0;
};

Pcb::Pcb(int pid, int tarq, int priority, int tncpu, vector<int> cpuBursts, vector<int> ioBursts){
	this->pid = pid;
	this->tarq = tarq;
	this->priority = priority;
	this->cpuBursts = cpuBursts;
	this->ioBursts = ioBursts;
	this->tncpu = tncpu;
	this->currentCpuBurst = 0;
	this->currentIoBurst = 0;
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
int Pcb::getAge() {
	return this->age;
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
//void Pcb::setPriority( int age ) {
//	this->age = age;
//}
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
