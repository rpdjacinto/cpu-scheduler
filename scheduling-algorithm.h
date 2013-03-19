#include "pcb.h"

#ifndef SCHEDULINGALGORITHM_H
#define SCHEDULINGALGORITHM_H

class SchedulingAlgorithm {

public:
	//Constructors
	SchedulingAlgorithm();
	SchedulingAlgorithm( vector<Pcb> processes );
	// Run Scheduling Simulation
	int run();

	int getTime();
	vector<Pcb> getProcesses();
	vector<Pcb> getInactiveProcesses();
	vector<Pcb> getReadyQueue();
	vector<Pcb> getWaitingQueue();
	vector<Pcb> getCompletedProcesses();
	Pcb getCurrentProcess();

	void setTime( int time );
	void setProcesses(vector<Pcb>);
	void setInactiveProcesses(vector<Pcb>);
	void setReadyQueue(vector<Pcb>);
	void setWaitingQueue(vector<Pcb>);
	void setcompletedProcesses(vector<Pcb>);
	void setCurrentProcess(Pcb);

private:
	
	//All Processes
	vector<Pcb> processes;
	//List of inactive Processes;
	vector<Pcb> inactiveProcesses;
	//List of Processes in Ready Queue
	vector<Pcb> readyQueue;
	//List of Processes in Waiting Queue
	vector<Pcb> waitingQueue;
	//List of completed Processes
	vector<Pcb> completedProcesses;
	//Process in CPU
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
	// Produce Gantt Chart
	void output();

};

#endif