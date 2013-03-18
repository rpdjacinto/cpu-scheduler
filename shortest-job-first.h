#include "scheduling-algorithm.h"

#ifndef SHORTESTJOBFIRST_H
#define SHORTESTJOBFIRST_H

class ShortestJobFirst : public SchedulingAlgorithm {

	public:
	        ShortestJobFirst();
	        ShortestJobFirst(vector<Pcb> processes);

	private:
	        void selectProcess();
};

#endif

