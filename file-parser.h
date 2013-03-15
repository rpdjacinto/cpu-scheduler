#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "pcb.h"

#ifndef FILEPARSER_H
#define FILEPARSER_H

using namespace std;

class FileParser {

	string fileName;
	ifstream inputFile;
	vector<vector<int>> PCBData;
	vector<Pcb> pcbs;
	int numberOfPCBData;

	public:

	FileParser();
	FileParser(string);

	string getFilename();
	int getNumberOfPCBData();
	vector<int> getPCBData(int);
	vector<Pcb> getPCBs();

	void makePCBs();

	int parseFile();

};

#endif