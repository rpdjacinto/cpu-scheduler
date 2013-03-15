#include <vector>

using namespace std;

class Pcb {

public:
	Pcb(int pid, int tarq, int priority, vector<int> cpuBursts, vector<int> ioBursts);

private:
	int pid;
	int tarq;
	int priority;
	vector<int> cpuBursts;
	vector<int> ioBursts;
};