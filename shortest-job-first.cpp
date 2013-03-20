# include "INCLUDES/shortest-job-first.h"
# include "string.h"
# include "string"

ShortestJobFirst::ShortestJobFirst(vector<Pcb> processes) : SchedulingAlgorithm(processes) {
}



int ShortestJobFirst::selectProcess() 
{
    
	vector<Pcb> readyQueue = getReadyQueue();

    int pidOfSelectedProcess = 0; 

	if (isCurrentProcessSet == false)
	{
		if (readyQueue.size() != 0)
		{
			/* Default values
			 */
			pidOfSelectedProcess = 0;
			int indexOfProcessToBeRemoved = 0;

			/* Finding process with shortest next cpu burst
			 */
			int shortestBurst = readyQueue.front().getCpuBurst(readyQueue.front().getCurrentCpuBurst());
			               
				for( int i = 0; i < readyQueue.size(); i++) 
				{
			        	if( readyQueue[i].getCpuBurst(readyQueue[i].getCurrentCpuBurst()) < shortestBurst ) 
						{
			                	shortestBurst = readyQueue[i].getCpuBurst(readyQueue[i].getCurrentCpuBurst());
			                    pidOfSelectedProcess = readyQueue[i].getPid();
								indexOfProcessToBeRemoved = i;
			            }
		        }

			setCurrentProcess(readyQueue[indexOfProcessToBeRemoved]);
			readyQueue.erase(readyQueue.begin() + indexOfProcessToBeRemoved);
			setReadyQueue(readyQueue);

			isCurrentProcessSet = true;
		}
	}


	return pidOfSelectedProcess;
}


/*
 * @Override verbose function
 */
void ShortestJobFirst::printVerbose(string message)
{

	if (verbose == 1)
	{
		cout << "\n[shortest-job-first.cpp] " << message;
	}
}