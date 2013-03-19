# include <stdio.h>
# include <string>
# include <string.h>
# include <iostream>
# include <map>
# include "file-parser.h"
# include "shortest-previous-burst.h"
# include "first-in-first-out.h"
# include "pcb.h"
# include "gantt.h"


using namespace std;


/*
 * Global Variables
 */

map <char, string> options;
char verbose = 1;


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
	

		/* End of program
		 */
		cout << "\n\nPress any key to continue..";	
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
		cout<<"\nEnter filename containing workload description: ";
		cin>>options['w'];
		cout<<"\nEnter algorithm: ";
		cin>>options['a'];
		cout<<"\nExtra parameter required for this algorithm (y/n) ? ";
		char c;
		cin>>c;
		if (c == 'y' || c == 'Y')
		{
			cout<<"\nEnter parameter for algorithm: ";
			cin>>options['p'];
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
