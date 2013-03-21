#include "scheduling-algorithm.h"

#ifndef SHORTESTJOBFIRST_H
#define SHORTESTJOBFIRST_H

class ShortestJobFirst : public SchedulingAlgorithm {

	public:
	        ShortestJobFirst();
	        ShortestJobFirst(vector<Pcb> processes);

	protected:
			void printVerbose(string message);

	private:
	        int selectProcess();
	        int threshold;
			vector<Pcb> vipQueue;
};

#endif

