#include <vector>

using namespace std;

class Pcb {

public:

private:
	int pid;
	int tarq;
	int priority;
	int cpuBursts;
	vector<int> cpuBursts;
	vector<int> ioBursts;
};