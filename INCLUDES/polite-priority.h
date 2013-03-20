#include "scheduling-algorithm.h"

#ifndef	POLITEPRIORITY_H
#define POLITEPRIORITY_H

class PolitePriority : public SchedulingAlgorithm {

public:
	PolitePriority();
	PolitePriority( vector<Pcb> processes, int timeSlice = 0 );
	int getTimeSlice();
	void setTimeSlice( int timeSlice );

protected:
	void printVerbose(string message);

	
private:
	int timeSlice;
	int selectProcess();
};

#endif