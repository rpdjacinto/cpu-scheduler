#include "scheduling-algorithm.h"

#ifndef	IMPATIENTPRIORITY_H
#define IMPATIENTPRIORITY_H

class ImpatientPriority : public SchedulingAlgorithm {

public:
	ImpatientPriority();
	ImpatientPriority( vector<Pcb> processes );

protected:
	void printVerbose(string message);
	
private:
	int selectProcess();
	int threshold;
	vector<Pcb> vipQueue;
};

#endif
