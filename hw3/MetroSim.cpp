// David Gantt
// Comp15
// hw3
// February 12, 2020
// "MetroSim.cpp"
// implementation of the MetroSim class

#include "MetroSim.h"
#include "PassengerQueue.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <bits/stdc++.h> 

using namespace std;

MetroSim::MetroSim(string stationsFile, string outFileName) {
	// initalize data members
	numStations = 0;
	numPassengers = 1;

	// initialize rail line
	read_stations(stationsFile, outFileName);

	// put train at first station
	StationVector[0].trainPresent = true;

	// make the train
	for (size_t i = 0; i < numStations; i++) {
		PassengerQueue queue;
		train.push_back(queue);
	}

}

MetroSim::~MetroSim() {
}

void MetroSim::playWithCommands(string commandsFile) {
	ifstream inFile;
	inFile.open(commandsFile);

	// check for error
	if (inFile.fail()) {
		cerr << "Error: could not open file " << commandsFile << endl;
		exit(0);
	}

	while (!inFile.eof()) {

		print();

		// PROCESSING COMMANDS
		// string command;
		string input;
		string arg1 = "0", arg2 = "00", arg3 = "000";
		getline(inFile, input);

		istringstream ss(input);

		ss >> arg1 >> arg2 >> arg3;

		// base case, quit program
		if (arg1 == "m" and arg2 == "f") {
			cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
			outFile.close();
			exit(0);
		}

		// adds passenger
		if (arg3 != "000") {
			addPassenger(input);
		}

		// moving the train
		if (arg1 == "m" and arg2 == "m") {
			pickupPassengers();
			moveTrain();
			dropOffPassengers();
		}

	}
}

void MetroSim::play() {

	print();

	// PROCESSING COMMANDS
	string command;
	getline(cin, command);

	// base case, quit program
	if (command == "m f") {
		cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
		outFile.close();
		exit(0);
	}

	// adds passenger
	if (command[0] == 'p') {
		addPassenger(command);
	}

	// moving the train
	if (command == "m m") {
		pickupPassengers();
		moveTrain();
		dropOffPassengers();
	}

	// calls itself
	play();

}

void MetroSim::addPassenger(string command) {
	// parsing string
	vector <string> pieces;
	stringstream check1(command);
	string intermediate;

	// parse the command into many pieces, checking for spaces
	while(getline(check1, intermediate, ' ')) {
		pieces.push_back(intermediate);
	}

	// add a passenger
	Passenger p;
	p.id = numPassengers;
	p.from = stoi(pieces[1]);;
	p.to = stoi(pieces[2]);
	StationVector[p.from - 1].queue.enqueue(p);
	numPassengers++;


}


void MetroSim::pickupPassengers() {
	// for the station with the train at it
	for (size_t i = 0; i < numStations; i++) {
		if (StationVector[i].trainPresent == true) {
			// adds people waiting at the station to the correct queue in the train
			int ogSize = StationVector[i].queue.size();
			for (int j = 0; j < ogSize; j++) {
				int addAt = StationVector[i].queue.front().to;
				train[addAt-1].enqueue(StationVector[i].queue.front());
				StationVector[i].queue.dequeue();
			}
		}
	}
}

void MetroSim::dropOffPassengers() {
	// where the train is
	for (size_t i = 0; i < numStations; i++) {
		if (StationVector[i].trainPresent == true) {
			// drop off all the right passengers
			int ogSize = train[i].size();
			for (int j = 0; j < ogSize; j++) {
				outFile << "Passenger ";
				outFile << train[i].front().id;
				outFile << " left train at station ";
				outFile << StationVector[i].name << endl;
				train[i].dequeue();
			}
		}
	}
}


void MetroSim::moveTrain() {
	// change the train bool
	for (size_t i = 0; i < numStations; i++) {
		if (StationVector[i].trainPresent == true) {
			if (i == numStations-1) {
				StationVector[i].trainPresent = false;
				StationVector[0].trainPresent = true;
				return;
			} else {
				StationVector[i].trainPresent = false;
				StationVector[(i+1)].trainPresent = true;
				return;
			}
		}

	}
}

int MetroSim::size() {
	return numStations;
}


void MetroSim::read_stations(string inFileName, string outFileName) {
	// read in text stationsFile
	ifstream inFile;
	string line;
	inFile.open(inFileName);

	// Check if file opens
	if (!inFile) {
		cout << "Error: could not open file" << inFileName << endl;
		exit(1);
	}

	// init ID of stations
	int stationsID = 1;

	while (getline (inFile, line)) {
		// create station, add to back of vector
		Station s;
		s.id = stationsID;
		s.name = line;
		s.trainPresent = false;
		StationVector.push_back(s);
		stationsID++;
		numStations++;
	}
	// close file
	inFile.close();

	outFile.open(outFileName);
}



void MetroSim::print() {
	cout << "Passengers on the train: " << "{";
	// print the train passenger queue
	for (size_t i = 0; i < train.size(); i++) {
		train[i].print();
	}

	cout << "}" << endl;

	// loop through, print every station
	for (size_t i = 0; i < numStations; i++) {

		if (StationVector[i].trainPresent == true) {
		cout << "TRAIN: ";
		cout << "[" << StationVector[i].id << "] " << 
		StationVector[i].name << " " << "{";
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
	cout << "Command? ";
}