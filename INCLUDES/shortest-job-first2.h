#include "scheduling-algorithm.h"

#ifndef SHORTESTJOBFIRST2_H
#define SHORTESTJOBFIRST2_H

class ShortestJobFirst : public SchedulingAlgorithm {

  public:
	        ShortestJobFirst();
	        ShortestJobFirst(vector<Pcb> processes);

	        void printVerbose(string message);
	private:
	        int selectProcess();
};

#endif
