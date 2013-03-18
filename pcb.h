#include <vector>
#include <iostream>

#ifndef PCB_H
#define PCB_H

using namespace std;

class Pcb {

public:
	Pcb();
	Pcb(int pid, int tarq, int priority, vector<int> cpuBursts, vector<int> ioBursts);
	int getPid();
	int getStatus();
	int getTarq();
	int getPriority();
	float getAverageBursts();
	int getCurrentCpuBurst();
	int getCurrentIoBurst();
	vector<int> getCpuBursts();
	vector<int> getIoBursts();
	int getCpuBurst(int index);


	void setPid( int pid );
	void setStatus( int Status );
	void setTarq( int tarq );
	void setPriority( int setPriority );
	void setAverageBursts( float averageBursts );
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
	int currentCpuBurst;
	int currentIoBurst;
	float averageBursts;
	vector<int> cpuBursts;
	vector<int> ioBursts;
};

#endif
