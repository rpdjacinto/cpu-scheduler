#include "file-parser.h"

FileParser::FileParser(){
	this->fileName = "Testing.txt";
}

FileParser::FileParser(string fileName){
	this->fileName = fileName;
	parseFile();
	makePCBs();
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
	inputFile.open(fileName.c_str());
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

void FileParser::makePCBs(){
	int pcbCount;
	int burstCount;
	vector<int> tempCPUBursts;
	vector<int> tempIOBursts;
	int tempPid;
	int tempPriority;
	int tempTarq;
	int tempTnCpu;
	for(pcbCount = 0 ; pcbCount < getNumberOfPCBData() ; pcbCount++){
		tempCPUBursts.clear();
		tempIOBursts.clear();
		tempPid = PCBData[pcbCount][0];
		tempTarq = PCBData[pcbCount][1];
		tempPriority = PCBData[pcbCount][2];
		tempTnCpu = PCBData[pcbCount][3];
		for(burstCount = 4 ; burstCount < PCBData[pcbCount].size() ; burstCount += 2){
			tempCPUBursts.push_back(PCBData[pcbCount][burstCount]);
			if(PCBData[pcbCount].size() > burstCount + 1){
				tempIOBursts.push_back(PCBData[pcbCount][burstCount + 1]);
			}
		}
		pcbs.push_back(Pcb(tempPid, tempTarq, tempPriority, tempTnCpu, tempCPUBursts, tempIOBursts));
	}
};

vector<Pcb> FileParser::getPCBs(){
	return pcbs;
};
