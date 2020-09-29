#include "MetroLine.h"
#include <vector>
#include <fstream>

using namespace std;

MetroLine::MetroLine() {
	// I AM TRYING TO CREATE A METROLINE OBJECT
	// BY READING IN ALL OF THE STATIONS FROM THE TEXT FILE
	numStations = 0;
	read_stations("stations.txt");
	StationVector[0].trainPresent = true;

	// print the original state.. or is this in metrosim...

}





void MetroLine::read_stations(string filename) {
	ifstream inFile;
	string line;

	inFile.open(filename);

	// Check if file opens
	if (!inFile) {
		cout << "Error: could not open file" << filename << endl;
		exit(1);
	}

	int stationsID = 1;

	while (getline (inFile, line)) {
		Station s;
		s.id = stationsID;
		s.name = line;
		s.trainPresent = false;
		StationVector.push_back(s);
		// maybe, use "this->"

		
		stationsID++;

		numStations++;
	}

	inFile.close();

}



void MetroLine::print() {
	cout << "Passengers on the train: " << "{";
	// print the train passenger queue
	train.print();

	cout << "}" << endl;


	for (size_t i = 0; i < numStations; i++) {


		if (StationVector[i].trainPresent == true) {
		cout << "TRAIN: ";
		cout << "[" << StationVector[i].id << "] " << 
		StationVector[i].name << " " << 
		"{";

		StationVector[i].queue.print();

		cout << "}" << endl;

		} else {
		cout << "       ";
		cout << "[" << StationVector[i].id << "] " << 
		StationVector[i].name << " " << 
		"{";

		StationVector[i].queue.print();

		cout << "}" << endl;
		}
	}
}




