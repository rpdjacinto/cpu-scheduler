# include "shortest-job-first.h"


void ShortestJobFirst::selectProcess() 
{
	        vector<Pcb> readyQueue = getReadyQueue();

	        int pidOfSelectedProcess = -1; 
		
		if( readyQueue.size() > 0 ) 
		{
	                pidOfSelectedProcess = 0;
	                
			int shortestBurst = readyQueue.front().getCpuBurst(readyQueue.front().getCurrentCpuBurst());
	                
			for( int i = 0; i < readyQueue.size(); i++) 
			{
	                        if( readyQueue[i].getCpuBurst(readyQueue[i].getCurrentCpuBurst()) < shortestBurst ) 
				{
	                                shortestBurst = readyQueue[i].getCpuBurst(readyQueue[i].getCurrentCpuBurst());
	                                pidOfSelectedProcess = readyQueue[i].getPid();
	                        }
	                }
	        }
}

