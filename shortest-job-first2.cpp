#include "shortest-job-first2.h"
#include <string>
#include <string.h>

ShortestJobFirst::ShortestJobFirst(vector<Pcb> processes)
{
          setProcesses(processes);
	        setInactiveProcesses(processes);
	        setWaitingQueue(processes);
	        setTime(0);
}

int ShortestJobFirst::selectProcess() 
{
	        vector<Pcb> readyQueue = getReadyQueue();

	        int pidOfSelectedProcess = -1; 
		
		if( readyQueue.size() > 0 ) 
		{
	                pidOfSelectedProcess = 0;
					int pidOfEqualProcess = 9999;
	                
			int shortestBurst = readyQueue.front().getCpuBurst(readyQueue.front().getCurrentCpuBurst());
	                
			for( int i = 0; i < readyQueue.size(); i++) 
			{
	                        if( readyQueue[i].getCpuBurst(readyQueue[i].getCurrentCpuBurst()) < shortestBurst ) {
	                                shortestBurst = readyQueue[i].getCpuBurst(readyQueue[i].getCurrentCpuBurst());
	                                pidOfSelectedProcess = readyQueue[i].getPid();
	                        } // if
							else if (readyQueue[i].getCpuBurst(readyQueue[i].getCurrentCpuBurst()[i]) = shortestBurst ) {
								pidOfEqualProcess = readyQueue[i].getPid();
							} //else if
			}
			if (pidOfEqualProcess < pidOfSelectedProcess){
				pidOfSelectedProcess = pidOfEqualProcess;
	        } //if
	        } //if
		else{
			cout << "No processes in the ready Queue \n";
		} //else
		return pidOfSelectedProcess;
}

