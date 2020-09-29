// David Gantt
// Comp15
// hw3
// February 12, 2020
// "main.cpp"
// client of the MetroSim class

#include <iostream>
#include <fstream>
#include <string>

#include "MetroSim.h"

using namespace std;

int main(int argc, char *argv[])
{
	// check how many command line arguments are provided
	if (argc != 3 and argc != 4) { // MAKE '2' TO '4'
		cerr << "Usage: ./MetroSim stationsFile outputFile [commandsFile]" << endl;
		exit(0);
	}

	// make an instance of the MetroSim
	MetroSim sim(argv[1], argv[2]);
	
	// run the simulation
	if (argc == 3) {
		sim.play();
	} else {
		sim.playWithCommands(argv[3]);
	}
	return 0;
}