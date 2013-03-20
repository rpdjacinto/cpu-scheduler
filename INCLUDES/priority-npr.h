#include "scheduling-algorithm.h"

#ifndef PRIORITYNPR_H
#define PRIORITYNPR_H

class PriorityNpr : public SchedulingAlgorithm {

public:
	PriorityNpr();
	PriorityNpr( vector<Pcb> processes );

protected:
	void printVerbose(string message);
	
private:
	int selectProcess();
};

#endif
