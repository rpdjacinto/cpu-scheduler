#include <vector>
#include <iostream>

#ifndef PCB_H
#define PCB_H

using namespace std;

class Pcb {

public:
	Pcb();
	Pcb(int pid, int tarq, int priority, int tncpu, vector<int> cpuBursts, vector<int> ioBursts);

	int getPid();
	int getTarq();
	int getPriority();
	int getAge();
	float getAverageBursts();
	int getCurrentWaitingTime();
	int getCurrentCpuTime();
	int getCurrentIoTime();
	int getCurrentCpuBurst();
	int getCurrentIoBurst();
	vector<int> getCpuBursts();
	vector<int> getIoBursts();
	int getCpuBurst(int index);

	void setAverageBursts( float averageBursts );
	void setCurrentWaitingTime( int currentWaitingTime );
	void setCurrentCpuTime( int currentCpuTime );
	void setCurrentIoTime( int currentIoTime );
	void setCurrentCpuBurst( int currentCpuBurst );
	void setCurrentIoBurst( int ioBurst );
	void setCpuBursts( vector<int> cpuBursts );
	void setIoBursts( vector<int> cpuBursts );
	void setCpuBurst (int burst, int index);

	void setWaitingTime(int time);
	int getWaitingTime();
	void setExecutionTime(int time);
	int getExecutionTime();
	
private:
	
	/* From workload file
	 */
	int pid;
	int tarq;
	int priority;
	int tncpu;
	int age;
	vector<int> cpuBursts;
	vector<int> ioBursts;

	/* Required for simulation
	 */
	int currentWaitingTime;
	int currentCpuTime;
	int currentIoTime;
	int currentCpuBurst;
	int currentIoBurst;
	float averageBursts;

	/* Result variables
	 */
	int waitingTime;
	int executionTime;

};

#endif
