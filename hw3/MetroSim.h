// David Gantt
// Comp15
// hw3
// February 12, 2020
// "MetroSim.h"
// definition of the MetroSim class

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include <iostream>
#include <vector>
#include <fstream>
#include "Passenger.h"
#include "PassengerQueue.h"

class MetroSim
{
public:
	// constructor
	// takes a string (the name of a file of stations) and returns nothing
	// initializes a MetroSim obj
	MetroSim(string stationsFile, string outFileName);

	// destructor
	// takes nothing and return nothing
	// frees memory
	~MetroSim();

	// playWithCommands
	// takes a string (name of file of commands) and returns void
	// runs play, but with a file of given commands
	void playWithCommands(string commandsFile);

	// read_stations
	// takes a string filename (stationsFile) and returns nothing
	// intitializes all of the stations and the train
	void read_stations(string filename, string outFileName);

	// print
	// takes nothing and returns nothing
	// prints the train and all the stations
	void print();

	// size
	// takes nothing and returns an int
	// returns the number of stations
	int size();

	// pickupPassengers
	// takes nothing and returns nothing
	// picks up passengers waiting at station, puts them on train
	void pickupPassengers();

	// dropOffPassengers
	// takes nothing, returns nothing
	// drops of passengers from train at station
	void dropOffPassengers();

	// addPassenger
	// takes a string command
	// parses the string, and adds a passenger waiting at appropriate station
	void addPassenger(string command);

	// play
	// takes nothing and returns nothing
	// recursively takes in commands from cin, if commandsFile is not given
	// sends the output to an output file
	void play();

	// moveTrain
	// takes nothing and returns nothing
	// moves the Train from one to the next station
	void moveTrain();

private:
	// private data members


	// Station struct
	struct Station {
		int id;
		string name;
		PassengerQueue queue;
		bool trainPresent;
	};

	ofstream outFile;

	// train vector
	vector<PassengerQueue> train;

	// vector containing all the station structs
	vector<Station> StationVector;

	// number of total passengers, stations
	size_t numPassengers;
	size_t numStations;



};

#endif
