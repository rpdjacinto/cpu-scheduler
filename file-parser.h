#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class FileParser {

	string fileName;
	ifstream inputFile;
	vector<vector<int>> PCBData;
	int numberOfPCBData;

	public:

	FileParser();
	FileParser(string);

	string getFilename();
	int getNumberOfPCBData();
	vector<int> getPCBData(int);

	//ToMake
	int makePCBs();

	int parseFile();

};