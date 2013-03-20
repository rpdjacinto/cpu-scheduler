#include <vector>
#include <iostream>

#ifndef PCB_H
#define PCB_H

using namespace std;

class Pcb {

public:
	Pcb();
	Pcb(int pid, int tarq, int priority, vector<int> cpuBursts, vector<int> ioBursts);
	Pcb(int pid, int tarq, int priority, int tncpu, vector<int> cpuBursts, vector<int> ioBursts);

	int getPid();
	int getStatus();
	int getTarq();
	int getPriority();
	int getAge();
	float getAverageBursts();
	int getCurrentCpuTime();
	int getCurrentIoTime();
	int getCurrentCpuBurst();
	int getCurrentIoBurst();
	vector<int> getCpuBursts();
	vector<int> getIoBursts();
	int getCpuBurst(int index);

	void setPid( int pid );
	void setStatus( int Status );
	void setTarq( int tarq );
	void setPriority( int priority );
	void setAge( int age );
	void setAverageBursts( float averageBursts );
	void setCurrentCpuTime( int currentCpuTime );
	void setCurrentIoTime( int currentIoTime );
	void setCurrentCpuBurst( int currentCpuBurst );
	void setCurrentIoBurst( int ioBurst );
	void setCpuBursts( vector<int> cpuBursts );
	void setIoBursts( vector<int> cpuBursts );
	void setCpuBurst (int burst, int index);

private:
	int pid;
	int status;
	int tarq;
	int priority;
	int tncpu;
	int age;
	int currentCpuTime;
	int currentIoTime;
	int currentCpuBurst;
	int currentIoBurst;
	float averageBursts;
	vector<int> cpuBursts;
	vector<int> ioBursts;
};

#endif