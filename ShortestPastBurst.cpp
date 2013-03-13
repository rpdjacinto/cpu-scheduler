#include "SchedulingAlgorithm.cpp"

class ShortestPreviousBurst : public SchedulingAlgorithm {

public:
	ShortestPreviousBurst( int weight = 0 ) {
		this.weight = weight;
	}

	int run() {
		while( 1 ) {
			int shortestBursts = this.processes[0].;
			int selectedProcess = 0;
			for( int i = 0; i < this.processes.size(); i++ )
				if( processes[i].averageBursts < shortestBursts  )
					shortestBursts = processes[i].averageBursts;
			calculateAverageBursts( processes[i] );
			processes[i].run();
		}
		return 0;
	}

	int getWeight() {
		return this.weight;
	}

	void setWeight( int weight ) {
		this.weight = weight;
	}

private:
	float weight;
	float currentBurst;
	void calculateAverageBursts( &Pcb pcb ){
		pcb.setAverageBursts( weight * pcb.getAverageBursts + )
	}
}