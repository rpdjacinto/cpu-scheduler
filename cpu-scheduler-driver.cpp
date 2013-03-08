# include <stdio.h>
# include <string.h>
# include <iostream>

using namespace std;



void printHelp()
{
	cout<<"\ncpu-scheduler: A post-mortem utility designed to analyze the quality of CPU-scheduling algorithms.";
	cout<<"\nUsage:";
	cout<<"\n\tcpusched -w [text file with workload] -a [scheduling algorithm]"; 
	cout<<"\n\t\t[-h] print help";
	cout<<"\n\t\t[-v] verbose";
}

/* 
 * MAIN
 */

int main(int argc, char *argv[])
{

	// From command line
	string workload;
	string scheduling_algorithm;
	string parameter;
	char verbose = 0;
	char help = 0;


	/* Read command line options
 	 */
	int c;
	while ((c = getopt(argc,argv,"a:w:p:v:h")) != -1)
	{
		switch(c)
		{
	        	case 'a': scheduling_algorithm = optarg;  break;
			case 'w': workload = optarg;  break;
			case 'p': parameter = optarg;  break;
			case 'v': verbose = 1; break;
			case 'h': help = 1; break;
		}
	}



	if (help == 1)
	{
		printHelp();
	}


	return 0;
}
