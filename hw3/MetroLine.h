#ifndef METROLINE_H
#define METROLINE_H

#include <iostream>
#include <vector>
#include "PassengerQueue.h"

class MetroLine {
	public:
		MetroLine();
		void read_stations(string filename);
		void print();

	private:
		struct Station {
			int id;
			string name;
			PassengerQueue queue;
			bool trainPresent;
		};

		PassengerQueue train;

		int numStations;

		vector<Station> StationVector;

		// SHOULD I PUT A "TRAIN" IN HERE?
		// IS A TRAIN JUST A PASSENGERQUEUE

};

#endif