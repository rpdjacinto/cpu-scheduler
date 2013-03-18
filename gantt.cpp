# include "gantt.h"



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






	return true;
}


bool Gantt::print()
{
	printGantt();
	printStats();

	return true;
}
