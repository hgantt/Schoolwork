// David Gantt
// Comp15
// hw3
// February 12, 2020
// "PassengerQueue.h"
// Definition of the PassengerQueue class

#ifndef PASSENGERQUEUE_H
#define PASSENGERQUEUE_H

#include "Passenger.h"
#include <iostream>
#include <vector>

using namespace std;


class PassengerQueue {
	public: 
		// Default constructor
		// takes nothing and returns nothing
		// creates a PassengerQueue object
		PassengerQueue();

		// destructor
		// takes nothing and returns nothing
		// clears a passenger queue
		~PassengerQueue();

		// front
		// takes nothing and returns a passenger
		// returns the first passenger in the queue
		Passenger front();

		// dequeue
		// takes nothing and returns nothing
		// removes the first passenger in the queue
		void dequeue();

		// enqueue
		// takes a pointer to a passenger and returns nothing
		// adds a passenger to the back of the queue
		void enqueue(const Passenger& passenger);
		
		// size
		// takes nothing and returns an int
		// returns the number of passengers in the queue
		int size();

		// print
		// takes nothing and returns nothing
		// prints the queue
		void print();

	private: 
		// private data members

		// a vector of passengers
		vector<Passenger> PassengerVector;
};

#endif
