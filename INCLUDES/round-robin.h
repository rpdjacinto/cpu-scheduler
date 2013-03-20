#include "scheduling-algorithm.h"

#ifndef	ROUNDROBIN_H
#define ROUNDROBIN_H

class RoundRobin : public SchedulingAlgorithm {

public:
	RoundRobin();
	RoundRobin( vector<Pcb> processes, int timeSlice = 0 );
	int getTimeSlice();
	void setTimeSlice( int timeSlice );

protected:
	void printVerbose(string message);

	
private:
	int timeSlice;
	int selectProcess();
};

#endif
