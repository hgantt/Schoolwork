#ifndef PASSENGERQUEUE_H
#define PASSENGERQUEUE_H

#include <iostream>
#include <vector>

using namespace std;

//testingtestingtesting

class PassengerQueue {
	public: 
		PassengerQueue();
		~PassengerQueue();
		Passenger front();
		void dequeue();
		void enqueue(const Passenger& passenger);
		int size();
		void print();

	private: 
		vector<Passenger> PassengerVector;
		int numPassengers;
		int front;
		int back;

		void printPassenger(Passenger& passenger);

};

#endif