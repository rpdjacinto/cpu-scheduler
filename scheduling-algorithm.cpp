#include "INCLUDES/scheduling-algorithm.h"

using namespace std;

/*
 * Constructor definitions
 */
SchedulingAlgorithm::SchedulingAlgorithm() {
}

SchedulingAlgorithm::SchedulingAlgorithm( vector<Pcb> processes ) {
	this->processes = processes;
	this->inactiveProcesses = processes;
	this->time = 0;
	verbose = 0;
}

/*
 * Main run method to simulate scheduling algorithm
 */
int SchedulingAlgorithm::run() {
	while( !allProcessesCompleted() && time < 50) {
		debug();
		
		startProcesses();

		/* 
		 * Suggests next process to be run
		 */
		selectProcess();

		/* Increment CPU time of current process
		 */
		currentProcess.setCurrentCpuTime( currentProcess.getCurrentCpuTime() + 1 );
		/* Increment IO time of waitingQueue processes
		 */
		for( int i = 0; i < waitingQueue.size(); i++ ) 
			waitingQueue[i].setCurrentIoTime( waitingQueue[i].getCurrentIoTime() + 1 );
		
		cpuBurst();
		ioBurst();

		this->time++;
		
	}
	output();
	return 0;
}

/*
 * Method to determine when a process is ready to be put into the ready queue
 */
void SchedulingAlgorithm::startProcesses() {
	
	for( int i = 0; i < this->inactiveProcesses.size(); i++ ) {
		if( this->time == this->inactiveProcesses[i].getTarq() ) {
			cout<<"\nAdded: "<<this->inactiveProcesses[i].getPid();
			this->readyQueue.push_back( this->inactiveProcesses[i] );
			this->inactiveProcesses.erase( this->inactiveProcesses.begin() + i );
		}
	}
}

void SchedulingAlgorithm::debug()
{
	cout<<"\n\n\nAt time: "<<time<<"\nReady Queue: ";
	for (int i = 0; i< readyQueue.size(); i++){
		cout<<" "<<readyQueue[i].getPid();
	}

	cout<<"\tWaiting Queue: ";
	for (int i = 0; i< waitingQueue.size(); i++){
		cout<<" "<<waitingQueue[i].getPid();
	}
	cout<<"\tCompleted processes: ";
	cout<<completedProcesses.size();
}

/*
 * Method to simulate a CPU burst
 */
void SchedulingAlgorithm::cpuBurst() {

	if(currentProcess.getCpuBursts().size() != 0){

		if( currentProcess.getCurrentCpuTime() == currentProcess.getCpuBurst(currentProcess.getCurrentCpuBurst()) ) {
			
			if ( currentProcess.getIoBursts().size() == currentProcess.getCurrentIoBurst()  )
				completedProcesses.push_back(currentProcess);
			else
				waitingQueue.push_back(currentProcess);
		}

		cout << "\nCurrent PID "<< currentProcess.getPid();
	}
}

/*
 * Method to simulate an IO burst
 */
void SchedulingAlgorithm::ioBurst() {
	

	for( int i = 0; i < waitingQueue.size(); i++ ) {

		if( waitingQueue[i].getCurrentIoTime() == waitingQueue[i].getIoBursts()[waitingQueue[i].getCurrentIoBurst()] ) {
			
			waitingQueue[i].setCurrentIoBurst( waitingQueue[i].getCurrentIoBurst() + 1 );
			waitingQueue[i].setCurrentIoTime( 0 );

			if ( (waitingQueue[i].getCpuBursts().size() == waitingQueue[i].getCurrentCpuBurst()) && (waitingQueue[i].getIoBursts().size() == waitingQueue[i].getCurrentIoBurst()) )
				completedProcesses.push_back(waitingQueue[i]);
			else
				readyQueue.push_back( waitingQueue[i] );
			
			waitingQueue.erase( waitingQueue.begin() + i );
		}

	}
}

/* 
 * TODO add code to display Gantt chart and show stats
 */
void SchedulingAlgorithm::output() {

}


/*
 * Method to check if all processes have been completed
 * @return bool value, true if all processes have been completed
 */
bool SchedulingAlgorithm::allProcessesCompleted() {
	if( this->processes.size() == this->completedProcesses.size() ) return true;
	else return false;

}



/*
 * Accessor methods
 */

int SchedulingAlgorithm::getTime() {
	return this->time;
}

vector<Pcb> SchedulingAlgorithm::getProcesses() {
	return this->processes;
}

vector<Pcb> SchedulingAlgorithm::getReadyQueue() {
	return this->readyQueue;
}

Pcb SchedulingAlgorithm::getCurrentProcess(){
	return this->currentProcess;
}

/*
 * Mutator methods
 */

void SchedulingAlgorithm::setReadyQueue(vector<Pcb> processes){
	this->readyQueue = processes;
}

void SchedulingAlgorithm::setCompletedProcesses(vector<Pcb> processes){
	this->completedProcesses = processes;
}

void SchedulingAlgorithm::setCurrentProcess(Pcb currentProcess){
	this->currentProcess = currentProcess;
}

/*
 * Verbose function to print additional information if verbose is set
 */
void SchedulingAlgorithm::printVerbose(string message)
{
	if (verbose == 1)
	{
		cout<<"\n"<<message;
	}
}
