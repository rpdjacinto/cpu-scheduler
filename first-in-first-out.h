#include "Pcb.h"
#include "scheduling-algorithm.h"

#ifndef FIRSTINFIRSTOUT_H
#define FIRSTINFIRSTOUT_H

class FirstInFirstOut : public SchedulingAlgorithm {

public:

	FirstInFirstOut(vector<Pcb> processes);

	int run();
	void selectProcess();

private:

	void startProcesses();
	void selectProcess();
	void cpuBurst();
	void ioBurst();
	void output();

	int timeCount;

};

#endif
