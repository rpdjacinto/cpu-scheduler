#include "scheduling-algorithm.h"

#ifndef	SHORTESTPREVIOUSBURST_H
#define SHORTESTPREVIOUSBURST_H

class ShortestPreviousBurst : public SchedulingAlgorithm {

public:
	ShortestPreviousBurst();
	ShortestPreviousBurst( vector<Pcb> processes, float weight = 0 );
	float getWeight();
	void setWeight( float weight );

protected:
	void printVerbose(string message);

private:
	float weight;
	float currentBurst;
	int selectProcess();
	void calculateAverageBursts(  int burstLength, Pcb &pcb );
	int threshold;
	vector<Pcb> vipQueue;
};

#endif
