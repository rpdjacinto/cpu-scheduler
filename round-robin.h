#include "scheduling-algorithm.h"

#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H

class RoundRobin: public SchedulingAlgorithm{
  
public: 
	RoundRobin();
	RoundRobin( vector <Pcb> processes, int quantumTime);

private:
	int quantumTime;
	int SelectProcess();
	int getQuantumTime();
	void setQuantumTime(int quantumTime);
};

#endif
