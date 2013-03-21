# include "INCLUDES/shortest-job-first.h"
# include "string.h"
# include "string"

ShortestJobFirst::ShortestJobFirst(vector<Pcb> processes) : SchedulingAlgorithm(processes) {
	algorithmName = "SHORTEST JOB FIRST";
	threshold = 10;
}



int ShortestJobFirst::selectProcess() 
{
    
	vector<Pcb> readyQueue = getReadyQueue();

    int pidOfSelectedProcess = 0; 
	
	for( int i = 0; i < readyQueue.size(); i++ ) {
		if( readyQueue[i].getCurrentWaitingTime() >= this->threshold ) {
			vipQueue.push_back( readyQueue[i] );
			readyQueue.erase( readyQueue.begin() + i );
			setReadyQueue( readyQueue );
		}
	}

	if (isCurrentProcessSet == false)
	{
		if (vipQueue.size() != 0)
		{
			/* Default values
			 */
			pidOfSelectedProcess = 0;
			int indexOfProcessToBeRemoved = 0;

			/* Finding process with shortest next cpu burst
			 */
			int shortestBurst = vipQueue.front().getCpuBurst(vipQueue.front().getCurrentCpuBurst());
			               
				for( int i = 0; i < vipQueue.size(); i++) 
				{
			        	if( vipQueue[i].getCpuBurst(vipQueue[i].getCurrentCpuBurst()) < shortestBurst ) 
						{
			                	shortestBurst = vipQueue[i].getCpuBurst(vipQueue[i].getCurrentCpuBurst());
			                    pidOfSelectedProcess = vipQueue[i].getPid();
								indexOfProcessToBeRemoved = i;
			            }
		        }

			setCurrentProcess(vipQueue[indexOfProcessToBeRemoved]);
			vipQueue.erase(vipQueue.begin() + indexOfProcessToBeRemoved);

			isCurrentProcessSet = true;
		}
		else if (readyQueue.size() != 0)
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