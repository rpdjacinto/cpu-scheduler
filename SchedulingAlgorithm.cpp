using namespace std;

class SchedulingAlgorithm {

public:
	virtual int run() = 0;

private:
	vector<PCB> processes;
	float averageWaitingTime; // Average Waiting Time for each process
	float throughput; // Number of completed processes
	float tournaround; // Average turnaround time for a process?
	void output();

};