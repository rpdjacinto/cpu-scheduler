# include <iostream>
# include <stdio.h>
# include <vector>
# include "pcb.h"


#ifndef GANTT_H
#define GANTT_H

using namespace std;

class Gantt
{
	public:
		bool put(Pcb);
		bool put(int);

		bool printGantt();
		bool printStats();
		bool print();

	
	private:
		vector<int> pidList;


};




#endif
