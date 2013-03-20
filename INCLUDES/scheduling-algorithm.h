# include "pcb.h"
# include <iostream>
# include <string>

#ifndef SCHEDULINGALGORITHM_H
#define SCHEDULINGALGORITHM_H

class SchedulingAlgorithm {

public:
	/*
	 * Constructors
	 */
	SchedulingAlgorithm();
	SchedulingAlgorithm( vector<Pcb> processes );
	
	/* 
	 * Main method to run scheduling simulation
	 */
	int run();

	/* 
	 * Getters
	 */
	int getTime();
	vector<Pcb> getProcesses();
	vector<Pcb> getReadyQueue();
	Pcb getCurrentProcess();

	/*
	 * Setters
	 */
	void setReadyQueue(vector<Pcb>);
	void setCompletedProcesses(vector<Pcb>);
	void setCurrentProcess(Pcb);

	/* 
	 * Verbose logging method
	 * Overriden by sub class
	 */
	void setVerbose();
	void debug();

protected:
	char verbose;
	void printVerbose(string message);

private:
	
	vector<Pcb> processes;
	vector<Pcb> inactiveProcesses;
	vector<Pcb> readyQueue;
	vector<Pcb> waitingQueue;
	vector<Pcb> completedProcesses;
	Pcb currentProcess;

	// Time units elapsed
	int time;
	// Average Waiting Time for each process
	float averageWaitingTime;
	// Number of completed processes
	float throughput;
	// Average turnaround time for a process?
	float turnaround;


	// Check if all processes terminated
	bool allProcessesCompleted();
	// Add inactive processes to ready queue
	void startProcesses();
	// Simulate CPU burst
	void cpuBurst();
	// Simulate IO Burst
	void ioBurst();
	// Select next process to run
	virtual int selectProcess() = 0;
	// Generate output for simulation
	void output();
	
};

#endif
