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
	isCurrentProcessSet = false;
}

/*
 * Main run method to simulate scheduling algorithm
 */
int SchedulingAlgorithm::run() {
	while( !allProcessesCompleted() && time < 50) {

		cout<<"\n\n\n--------------------------------------------";
		startProcesses();

		/* 
		 * Suggests next process to be run
		 */
		selectProcess();

		cout<<"\nBEFORE: ";
		debug();


		/* Increment CPU time of current process
		 */
		currentProcess.setCurrentCpuTime( currentProcess.getCurrentCpuTime() + 1 );
		/* Increment IO time of waitingQueue processes
		 */
		for( int i = 0; i < waitingQueue.size(); i++ ) 
			waitingQueue[i].setCurrentIoTime( waitingQueue[i].getCurrentIoTime() + 1 );

		if (isCurrentProcessSet)
		{	
			cpuBurst();
		}

		ioBurst();



		cout<<"\n\nAFTER: ";
		debug();

		this->time++;

		/* If CPU is idle, gantt shows -1
		 */
		if (!allProcessesCompleted())
		{
			if (isCurrentProcessSet == false && readyQueue.size() == 0)
				gantt.put(-1);
			else
				gantt.put(currentProcess);
		}
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
			cout<<"\nAdded: "<<this->inactiveProcesses[i].getPid()<<"\n";
			this->readyQueue.push_back( this->inactiveProcesses[i] );
			this->inactiveProcesses.erase( this->inactiveProcesses.begin() + i );
		}
	}
}

void SchedulingAlgorithm::debug()
{
	cout<<"\nAt time: "<<time<<"\nReady Queue: ";
	for (int i = 0; i< readyQueue.size(); i++){
		cout<<" "<<readyQueue[i].getPid();
	}

	cout<<"\tWaiting Queue: ";
	for (int i = 0; i< waitingQueue.size(); i++){
		cout<<" "<<waitingQueue[i].getPid();
	}
	cout<<"\tCompleted processes: ";
	cout<<completedProcesses.size();
	cout<<"\tisCurrentSet: ";
	cout<<isCurrentProcessSet;
}

/*
 * Method to simulate a CPU burst
 */
void SchedulingAlgorithm::cpuBurst() {


		if(currentProcess.getCpuBursts().size() != 0){

			if( currentProcess.getCurrentCpuTime() >= currentProcess.getCpuBurst(currentProcess.getCurrentCpuBurst()) ) {


				currentProcess.setCurrentCpuTime(0);
				if (currentProcess.getCurrentCpuBurst() < currentProcess.getCpuBursts().size())
					currentProcess.setCurrentCpuBurst(currentProcess.getCurrentCpuBurst() + 1);


				if ( currentProcess.getIoBursts().size() <= currentProcess.getCurrentIoBurst() )
				{
					isCurrentProcessSet = false;
					completedProcesses.push_back(currentProcess);
				}
				else
				{
					isCurrentProcessSet = false;
					waitingQueue.push_back(currentProcess);
				}
			}

			cout << "\n\nCurrent PID "<< currentProcess.getPid();
		}
}

/*
 * Method to simulate an IO burst
 */
void SchedulingAlgorithm::ioBurst() {


	for( int i = 0; i < waitingQueue.size(); i++ ) {

		if( waitingQueue[i].getCurrentIoTime() >= waitingQueue[i].getIoBursts()[waitingQueue[i].getCurrentIoBurst()] ) {

			waitingQueue[i].setCurrentIoTime( 0 );
			if (waitingQueue[i].getCurrentIoBurst() < waitingQueue[i].getIoBursts().size())
				waitingQueue[i].setCurrentIoBurst( waitingQueue[i].getCurrentIoBurst() + 1 );

			readyQueue.push_back( waitingQueue[i] );
			waitingQueue.erase( waitingQueue.begin() + i );
		}

	}
}

/* 
 * TODO add code to display Gantt chart and show stats
 */
void SchedulingAlgorithm::output() {
	gantt.print();
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
	isCurrentProcessSet = true;
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