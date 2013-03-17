#include <vector>
#include <iostream>

#ifndef PCB_H
#define PCB_H

using namespace std;

class Pcb {

public:
	Pcb(int pid, int tarq, int priority, vector<int> cpuBursts, vector<int> ioBursts);
	float getAverageBursts();
	void setAverageBursts( float averageBursts );

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