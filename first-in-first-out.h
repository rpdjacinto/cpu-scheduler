#include "scheduling-algorithm.h"

#ifndef FIRSTINFIRSTOUT_H
#define FIRSTINFIRSTOUT_H

class FirstInFirstOut : public SchedulingAlgorithm {

public:

	FirstInFirstOut(vector<Pcb> processes);

private:

	void startProcesses();
	int selectProcess();
	void cpuBurst();
	void ioBurst();
	void output();

	int timeCount;

};

#endif
