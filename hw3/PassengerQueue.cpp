// David Gantt
// Comp15
// hw3
// February 12, 2020
// "PassengerQueue.cpp"
// implementation of the PassengerQueue class and its public member functions


#include "PassengerQueue.h"
#include <vector>

using namespace std;


PassengerQueue::PassengerQueue() {
	// empty default constructor
}

PassengerQueue::~PassengerQueue() {
	// clears vector
	PassengerVector.clear();
}


Passenger PassengerQueue::front() {
	// returns first passenger
	return PassengerVector[0];
}


void PassengerQueue::dequeue() {
	// erases first passenger
	PassengerVector.erase(PassengerVector.begin());
}


void PassengerQueue::enqueue(const Passenger& passenger) {
	// adds a passenger w push_back
	PassengerVector.push_back(passenger);
}


int PassengerQueue::size() {
	// use built in size fxn
	return PassengerVector.size();
}

void PassengerQueue::print() {
	// loops, prints the passengers
	for (size_t i = 0; i < PassengerVector.size(); i++) {
		cout << "[" << PassengerVector.at(i).id << ", " << 
		PassengerVector.at(i).from << "->" 
		<< PassengerVector.at(i).to << "]";
	}
}