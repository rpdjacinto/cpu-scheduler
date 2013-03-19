#include "scheduling-algorithm.h"
# include <iostream>
# include <string>

#ifndef FIRSTINFIRSTOUT_H
#define FIRSTINFIRSTOUT_H

class FirstInFirstOut : public SchedulingAlgorithm {

public:

	FirstInFirstOut(vector<Pcb> processes);

	void printVerbose(string message);

private:

	int selectProcess();


};

#endif
