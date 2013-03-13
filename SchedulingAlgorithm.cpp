#include "Pcb.cpp"

using namespace std;

class SchedulingAlgorithm {

public:
	SchedulingAlgorithm( vector<Pcb> processes ) {
		this.processes = processes;
	}
	virtual int run() = 0;

private:
	
	//All Processes
	vector<Pcb> processes;
	//List of Processes in Ready Queue
	vector<Pcb> readyQueue;
	//List of Processes in Waiting Queue
	vector<Pcb> waitingQueue;

	// Average Waiting Time for each process
	float averageWaitingTime;
	// Number of completed processes
	float throughput;
	// Average turnaround time for a process?
	float tournaround; 
	void output();

};