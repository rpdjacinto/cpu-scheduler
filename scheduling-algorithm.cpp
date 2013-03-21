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
	algorithmName = "NOT AVAILABLE";
}

/*
 * Main run method to simulate scheduling algorithm
 */
int SchedulingAlgorithm::run() {
	while( !allProcessesCompleted()) {

		if (verbose == 1) cout<<"\n\n\n--------------------------------------------";
		
		startProcesses();

		/* 
		 * Suggests next process to be run
		 */
		selectProcess();

		if (readyQueue.size() == 0 && isCurrentProcessSet == false)
		{
			gantt.put(-1);
			if (verbose == 1) cout<<"\n\nGANTT: -1";
		}
		else
		{
			gantt.put(currentProcess);
			if (verbose == 1) cout<<"\n\nGANTT: "<<currentProcess.getPid();
		}

		if (verbose == 1) {
			cout<<"\nBEFORE: ";
			debug();
		}

		/* Update metric stats for each process
		 */
		for (int i = 0; i<readyQueue.size(); i++)
		{
			readyQueue[i].setWaitingTime(readyQueue[i].getWaitingTime() + 1);
			readyQueue[i].setExecutionTime(readyQueue[i].getExecutionTime() + 1);
		}
		for (int i = 0; i<waitingQueue.size(); i++)
		{
			waitingQueue[i].setExecutionTime(waitingQueue[i].getExecutionTime() + 1);
		}
		currentProcess.setExecutionTime(currentProcess.getExecutionTime() + 1);


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


		if (verbose == 1) {
			cout<<"\n\nAFTER: ";
			debug();
		}	


		
		

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
			if (verbose == 1) cout<<"\nAdded: "<<this->inactiveProcesses[i].getPid()<<"\n";
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

			if (verbose == 1) cout << "\n\nCurrent PID "<< currentProcess.getPid();
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
	gantt.setAlgorithmName(algorithmName);
	gantt.analyze(completedProcesses, time);
	gantt.print();
}


/*
 * Method to check if all processes have been completed
 * @return bool value, true if all processes have been completed
 */
bool SchedulingAlgorithm::allProcessesCompleted() {
	if( this->processes.size() == this->completedProcesses.size() ) 
		{
			if (verbose == 1) cout<<"\nAll processes completed!";
			return true;
		}
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

void SchedulingAlgorithm::setVerbose()
{
	verbose = 1;
}