# include "INCLUDES/gantt.h"

void Gantt::setAlgorithmName(string name) 
{
	algorithmName = name;
}

bool Gantt::put (Pcb pcb)
{
	pidList.push_back(pcb.getPid());

	return true;
}


bool Gantt::put (int pid)
{
	pidList.push_back(pid);

	return true;
}



bool Gantt::printGantt ()
{
	cout<<"\nGantt chart with CPU usage:\n";

	for (int i = 0; i < pidList.size(); i++)
	{
		cout<<"| "<<pidList[i]<<" ";
	}

	cout<<"|";

	return true;
}


bool Gantt::printStats()
{
	float averageWaitingTime = 0;
	float averageExecutionTime = 0;

	if (completedProcesses.size() != 0) {

		cout<<"\n\nMetrics for each process: ";
		for (int i = 0; i < completedProcesses.size(); i++) 
		{
			cout<<"\nPID: "<<completedProcesses[i].getPid();
			cout<<"\nTotal Waiting Time: "<<completedProcesses[i].getWaitingTime();
			cout<<"\nTotal Execution Time: "<<completedProcesses[i].getExecutionTime()<<"\n";

			averageWaitingTime += completedProcesses[i].getWaitingTime();
			averageExecutionTime += completedProcesses[i].getExecutionTime();
		}


		cout<<"\n\nMetrics for the entire simulation: ";
		cout<<"\nNumber of Processes Completed: "<<completedProcesses.size();
		averageWaitingTime /= completedProcesses.size();
		cout<<"\nAverage Waiting Time: "<<averageWaitingTime;
		averageExecutionTime /= completedProcesses.size();
		cout<<"\nTurnaround Time (avg. execution time of processes): "<<averageExecutionTime;
		cout<<"\nThroughput: "<<((float) completedProcesses.size())/totalTimeTaken;
		
		int nonIdleCycles = 0;
		for (int i = 0; i < pidList.size(); i++)
		{
			if (pidList[i] != -1) nonIdleCycles++;	
		}
		cout<<"\nCPU Utilization: "<< (((float) nonIdleCycles)/pidList.size())*100;
	}
	else
	{
		cout<<"\nNo processes were completed!";
	}
	return true;
}


bool Gantt::print()
{
	cout << "\n\n---------------------------------------------------------";
	cout <<"\nRESULTS FOR SIMULATING "<<algorithmName<<"\n";
	printGantt();
	printStats();
	cout<< "\n\n---------------------------------------------------------\n";
	return true;
}

void Gantt::analyze(vector<Pcb> processes, int time) 
{
	completedProcesses = processes;
	totalTimeTaken = time;
}