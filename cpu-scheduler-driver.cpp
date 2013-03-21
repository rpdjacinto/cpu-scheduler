# include <stdio.h>
# include <string>
# include <string.h>
# include <iostream>
# include <stdlib.h>
# include <fstream>
# include <map>
# include "INCLUDES/file-parser.h"
# include "INCLUDES/shortest-previous-burst.h"
# include "INCLUDES/shortest-job-first.h"
# include "INCLUDES/first-in-first-out.h"
# include "INCLUDES/priority-npr.h"
# include "INCLUDES/polite-priority.h"
# include "INCLUDES/impatient-priority.h"
# include "INCLUDES/pcb.h"
# include "INCLUDES/gantt.h"
# include "INCLUDES/round-robin.h"


using namespace std;


/*
 * Global Variables
 */

map <char, string> options;
char verbose;


/*
 * Function declarations
 */

void printHelp();
void commandLine(int, char **);
void printVerbose(string);
void printVerbose(string, string);


/* 
 * MAIN
 */

int main(int argc, char *argv[])
{
	/* From command line
	 */
	string workload;
	string scheduling_algorithm;
	string parameter;
	char help = 0;


	/* Read command line options
 	 */
	commandLine(argc, argv);
	workload = options['w'];
	scheduling_algorithm = options['a'];
	parameter = options['p'];
	help = (options['h'] == "1") ? 1 : 0;
	verbose = (options['v'] == "1") ? 1 : 0;

	/* Print help information
	 */
	if (help == 1)
	{
		printHelp();
	}

	/* Error checking
	 */
	else if (workload.empty() || scheduling_algorithm.empty())
	{
		cout<<"\nIncomplete arguments. See 'cpusched -h' for usage.";
	}

	/* Main processing - parse workload file, initialize algorithm object
	 */
	else
	{
		/* Parse workload
		 */
		FileParser testParse(workload);
		printVerbose("Filename:", testParse.getFilename());
		stringstream ss;
		ss << testParse.getNumberOfPCBData();
		printVerbose("Number of PCBs:", ss.str());
		
		/* Choose appropriate algorithm
		 */
		if (scheduling_algorithm.compare("fifo") == 0 || scheduling_algorithm.compare("fcfs") == 0)
		{


			FirstInFirstOut fifo(testParse.getPCBs());
			if (verbose == 1) fifo.setVerbose();
			fifo.run();
		}
		
		if (scheduling_algorithm.compare("spb") == 0)
		{


			ShortestPreviousBurst spb(testParse.getPCBs(), atof(options['p'].c_str()));
			if (verbose == 1) spb.setVerbose();
			spb.run();
		}	
	
		if (scheduling_algorithm.compare("sjf") == 0)
		{


			ShortestJobFirst sjf(testParse.getPCBs());
			if (verbose == 1) sjf.setVerbose();
			sjf.run();
		}	

		if (scheduling_algorithm.compare("npr-pri") == 0)
		{

			PriorityNpr prnpr(testParse.getPCBs());
			if (verbose == 1) prnpr.setVerbose();
			prnpr.run();
		}

		if (scheduling_algorithm.compare("pr-pol") == 0)
		{

			PolitePriority polpr(testParse.getPCBs(), atoi(options['p'].c_str()));
			if (verbose == 1) polpr.setVerbose();
			polpr.run();
		}

		if (scheduling_algorithm.compare("pr-impat") == 0)
		{

			ImpatientPriority primpat(testParse.getPCBs());
			if (verbose == 1) primpat.setVerbose();
			primpat.run();
		}

		if (scheduling_algorithm.compare("rr") == 0)
		{
//			 RoundRobin rr(testParse.getPCBs(), atoi(options['p'].c_str()));
//			 if (verbose == 1) rr.setVerbose();
//		     rr.run();
		}

		if (scheduling_algorithm.compare("all") == 0)
		{
			cout<<"\n\n---------------------------------------------------------"; 			

			FirstInFirstOut fifo(testParse.getPCBs());
			if (verbose == 1) fifo.setVerbose();
			fifo.run();

			ShortestPreviousBurst spb(testParse.getPCBs(), 0.5);
			if (verbose == 1) spb.setVerbose();
			spb.run();

			ShortestJobFirst sjf(testParse.getPCBs());
			if (verbose == 1) sjf.setVerbose();
			sjf.run();

			PriorityNpr prnpr(testParse.getPCBs());
			if (verbose == 1) prnpr.setVerbose();
			prnpr.run();

			PolitePriority polpr(testParse.getPCBs(), 4);
			if (verbose == 1) polpr.setVerbose();
			polpr.run();

			ImpatientPriority primpat(testParse.getPCBs());
			if (verbose == 1) primpat.setVerbose();
			primpat.run();

//			RoundRobin rr(testParse.getPCBs(), 4);
//			if (verbose == 1) rr.setVerbose();
//			rr.run();

			// TODO add code to print aggregate results
		}

		/* End of program
		 */
		cout<<"\n\nAlas! This is the end. Press any key to continue..";	
		getchar();
		getchar();
	}



	return 0;
}


/*
 * Function that prints help information
 */

void printHelp()
{
    cout<<"\ncpu-scheduler: A post-mortem utility designed to analyze the quality of CPU-scheduling algorithms.";
    cout<<"\nUsage:";
	cout<<"\n\tcpusched";
	cout<<"\n\t\twhen no arguments are provided, program will interactively ask for information";
    cout<<"\n\n\tcpusched -w [text file with workload] -a [scheduling algorithm]";
    cout<<"\n\t\t[-p] parameter for algorithm (if required)";
    cout<<"\n\t\t[-h] print help";
    cout<<"\n\t\t[-v] verbose";
    cout<<"\n\nThe algorithm choices, and any additional info required by them are:";
	cout<<"\n\tFirst Come First Serve (fifo)";
	cout<<"\n\tRound Robin (rr)";
	cout<<" - Requires timeslice input";
	cout<<"\n\tShortest Job First (sjf)";
	cout<<"\n\tShortest Previous Burst (spb)";
	cout<<" - Requires weight input";
	cout<<"\n\tImpatient Priority (pr-impat)";
	cout<<"\n\tPolite Priority (pr-pol)";
	cout<<" - Requires timeslice input";
	cout<<"\n\tNon Preemptive Priority (npr-pri)";
	cout<<"\n\tYou can also simulate all of the above in one go (all)";

}

/*
 * Command Line Parsing
 */

void commandLine(int argc, char *argv[])
{

	char *setOptions = "vh";
	char *argOptions = "awp";

	/* Set default
     */
    options['v'] = "0";
    options['h'] = "0";
	options['w'] = "";
	options['a'] = "";
	options['p'] = "";

	/* Read argv
     */
	if (argc == 1)
	{
		cout<<"\nWelcome to this adventure in exploring all kinds of CPU Scheduling possibilities! ";

		cout<<"\n\nTo begin, I need a text file that contains the workload description. What is the filename? ";
		cin>>options['w'];
		ifstream ifile;
		ifile.open(options['w'].c_str());
		while (ifile.fail()) {
			cout<<"\nUh-oh. I can't find it! Verify name and enter again: ";
			cin>>options['w'];
			ifile.open(options['w'].c_str());
		}
		
		cout<<"\n\nNow you need to specify an algorithm to run. Your choices are: ";
		cout<<"\n1. First Come First Serve (fifo)";
		cout<<"\n2. Round Robin (rr)";
		cout<<"\n3. Shortest Job First (sjf)";
		cout<<"\n4. Shortest Previous Burst (spb)";
		cout<<"\n5. Impatient Priority (pr-impat)";
		cout<<"\n6. Polite Priority (pr-pol)";
		cout<<"\n7. Non Preemptive Priority (npr-pri)";
		cout<<"\n8. You can also simulate all of the above in one go (all)";
		cout<<"\n\nTo select an algorithm, enter the code provided for it here: ";
		cin>>options['a'];

		while (	!(options['a'].compare("rr") == 0) && !(options['a'].compare("fifo") == 0) && 
				!(options['a'].compare("sjf") == 0) && !(options['a'].compare("npr-pri") == 0) && 
				!(options['a'].compare("spb") == 0) && !(options['a'].compare("pr-pol") == 0) && 
				!(options['a'].compare("pr-impat") == 0) && !(options['a'].compare("all") == 0)	) {
			
			cout<<"\n\nThat code doesn't exist. Enter again: ";
			cin>>options['a'];
		}

		if (options['a'].compare("rr") == 0 || options['a'].compare("pr-pol") == 0)
		{
			cout<<"\n\nI think this algorithm needs a timeslice input. What is your preferred timeslice? ";
			cin>>options['p'];

			while (atoi(options['p'].c_str()) <= 0)
			{
				cout<<"\nPlease enter a timeslice value of greater than 0: ";
				cin>>options['p'];
			}
		}

		if (options['a'].compare("spb") == 0)
		{
			cout<<"\nExcellent choice! What is the weight? ";
			cin>>options['p'];

			while (atof(options['p'].c_str()) <= 0 || atof(options['p'].c_str()) > 1)
			{
				cout<<"\nWeight should be in this range (0, 1]. Enter a valid weight: ";
				cin>>options['p'];
			}

		}

		cout<<"\n\nWould you like to turn verbose on? (y/n) : ";
		char choice;
		cin>>choice;
		if (choice == 'y' || choice == 'Y') {
			options['v'] = "1";
			cout<<"\nTurning Verbose on";
		}


	}
	else
	{
        	for (int i = 0; i<argc; i++)
        	{
                	if (argv[i][0] == '-')
                	{
						char c = argv[i][1];
						if (strchr(setOptions, c))
						{
							options[c] = "1";
						}
						else if (strchr(argOptions, c))
						{
							if (argv[i+1] != NULL)
							{
								options[c] = argv[i+1];
							}

						}
                	}
        	}

	}
}


/*
 * Functions to print information if verbose option is selected
 */

void printVerbose(string message)
{

	if (verbose == 1)
	{
		cout<<"\n[cpu-driver-scheduler.cpp] "<<message;
	}
}

void printVerbose(string message1, string message2)
{

	if (verbose == 1)
        {
                cout<<"\n[cpu-driver-scheduler.cpp] "<<message1<<" "<<message2;
        }
}
