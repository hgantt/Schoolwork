/*
 *
 */


#include "MetroSim.h"

MetroSim::MetroSim() {
}

void MetroSim::play() {
	string command;
	while (command != "m f") {
		line.print();
		cout << "Command? ";
		cin >> command;
		if (command == "m m") {
			moveTrain();
		} else if (command == "m f") {
			cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
			return;
		}
	}
}

void MetroSim::moveTrain() {
	for (size_t i = 0; i < line.numStations; i++) {
		if (line.StationVector[i].trainPresent == true) {
			line.StationVector[i].trainPresent == false;
			line.StationVector[i+1].trainPresent == true;
		}
	}
}