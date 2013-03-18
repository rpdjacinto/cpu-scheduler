#include <vector>
#include <iostream>

#ifndef PCB_H
#define PCB_H

using namespace std;

class Pcb {

public:
	Pcb(int pid, int tarq, int priority, vector<int> cpuBursts, vector<int> ioBursts);

	int getPid();
	int getStatus();
	int getTarq();
	int getPriority();
	float getAverageBursts();
	vector<int> getCpuBursts();
	vector<int> getIoBursts();

	void setPid( int pid );
	void setStatus( int Status );
	void setTarq( int tarq );
	void setPriority( int setPriority );
	void setAverageBursts( float averageBursts );
	void setCpuBursts( vector<int> cpuBursts );
	void setIoBursts( vector<int> cpuBursts );

private:
	int pid;
	int status;
	int tarq;
	int priority;
	float averageBursts;
	vector<int> cpuBursts;
	vector<int> ioBursts;
};

#endif