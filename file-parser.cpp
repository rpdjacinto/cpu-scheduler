#include "file-parser.h"

FileParser::FileParser(){
	this->fileName = "Testing.txt";
}

FileParser::FileParser(string fileName){
	this->fileName = fileName;
	parseFile();
}

string FileParser::getFilename(){
	return fileName;
}

int FileParser::getNumberOfPCBData(){
	return numberOfPCBData;
}

vector<int> FileParser::getPCBData(int index){
	return PCBData[index];
}

int FileParser::parseFile(){

	string tempLine;
	string tempChar;
	vector<int> pushVector;
	int count = 0;
	int lineCount = 0;
	
	inputFile.open(fileName);

	while(getline(inputFile, tempLine)){

		PCBData.push_back(pushVector);

		stringstream   linestream(tempLine);

		while(getline(linestream, tempLine, '\t')){
			PCBData[count].push_back(atoi(tempLine.c_str()));
		}

		count++;
	}

	numberOfPCBData =  PCBData.size();
	return PCBData.size();

}