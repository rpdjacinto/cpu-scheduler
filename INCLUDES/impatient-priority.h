#include "scheduling-algorithm.h"

#ifndef	IMPATIENTPRIORITY_H
#define IMPATIENTPRIORITY_H

class ImpatientPriority : public SchedulingAlgorithm {

public:
	ImpatientPriority();
	ImpatientPriority( vector<Pcb> processes );

private:
	int selectProcess();
};

#endif
