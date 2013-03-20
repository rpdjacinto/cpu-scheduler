# include <stdio.h>
# include <string>
# include <string.h>
# include <iostream>
# include <fstream>
# include <map>
# include "file-parser.h"
# include "shortest-previous-burst.h"
# include "shortest-job-first.h"
# include "first-in-first-out.h"
# include "priority-npr.h"
# include "polite-priority.h"
# include "impatient-priority.h"
# include "pcb.h"
# include "gantt.h"


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
			printVerbose("FIFO/FCFS selected");

			FirstInFirstOut fifo(testParse.getPCBs());
			fifo.run();
		}
		
		if (scheduling_algorithm.compare("spb") == 0)
		{
			printVerbose("Shortest Previous Burst (SPB) selected");

			ShortestPreviousBurst spb(testParse.getPCBs(), 0.5);
			spb.run();
		}	
	
		if (scheduling_algorithm.compare("sjf") == 0)
		{
			printVerbose("Shortest Job First (SJF) selected");

			ShortestJobFirst sjf(testParse.getPCBs());
			sjf.run();
		}	

		if (scheduling_algorithm.compare("npr-pri") == 0)
		{
			printVerbose("Non Preemptive Priority selected");

			PriorityNpr prnpr(testParse.getPCBs());
			prnpr.run();
		}

		if (scheduling_algorithm.compare("pr-pol") == 0)
		{
			printVerbose("Preemptive Polite Priority selected");

			PolitePriority polpr(testParse.getPCBs());
			polpr.run();
		}

		if (scheduling_algorithm.compare("pr-impat") == 0)
		{
			printVerbose("Impatient Priority selected");

			ImpatientPriority primpat(testParse.getPCBs());
			primpat.run();
		}

		if (scheduling_algorithm.compare("rr") == 0)
		{
			printVerbose("Round Robin selected");

			// RoundRobin rr(testParse.getPCBs());
			// rr.run();
		}

		if (scheduling_algorithm.compare("all") == 0)
		{
			printVerbose("Simulating all algorithms:");

			FirstInFirstOut fifo(testParse.getPCBs());
			fifo.run();
			ShortestPreviousBurst spb(testParse.getPCBs(), 0.5);
			spb.run();
			ShortestJobFirst sjf(testParse.getPCBs());
			sjf.run();
			PriorityNpr prnpr(testParse.getPCBs());
			prnpr.run();
			PolitePriority polpr(testParse.getPCBs());
			polpr.run();
			ImpatientPriority primpat(testParse.getPCBs());
			primpat.run();
			// RoundRobin rr(testParse.getPCBs());
			// rr.run();

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



		cout<<"\nWould you like to turn verbose on? (y/n) : ";
		char choice;
		cin>>choice;
		if (choice == 'y' || choice == 'Y') verbose = 1;


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
