# include <iostream>
# include <stdio.h>
# include <string.h>
# include <vector>
# include "pcb.h"


#ifndef GANTT_H
#define GANTT_H

using namespace std;

class Gantt
{
	public:
		void setAlgorithmName(string name);

		bool put(Pcb);
		bool put(int);

		bool printGantt();
		bool printStats();
		bool print();

		void analyze(vector<Pcb>);

	protected:
		void printVerbose(string message);
	
	private:
		vector<int> pidList;
		vector<Pcb> completedProcesses;
		string algorithmName;

};




#endif
