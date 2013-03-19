#include "scheduling-algorithm.h"

#ifndef FIRSTINFIRSTOUT_H
#define FIRSTINFIRSTOUT_H

class FirstInFirstOut : public SchedulingAlgorithm {

public:

	FirstInFirstOut(vector<Pcb> processes);

private:

	int selectProcess();


};

#endif
