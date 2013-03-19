#include "first-in-first-out.h"

FirstInFirstOut::FirstInFirstOut(vector<Pcb> processes){
	setProcesses(processes);
	setTime(0);
}

int FirstInFirstOut::selectProcess(){
	return -1;
}
