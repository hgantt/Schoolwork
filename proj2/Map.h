/* David Gantt
 * April 2020
 * COMP15
 * Proj2
 * "Map.h"
 * This is the interface for the Map class. Map is a graph class
 * which stores a vector of Vertex, each of which represents a location on a
 * map. These may be read in from any sort of data files, provided they are
 * formatted correctly.
 */


#ifndef MAP_H
#define MAP_H

#include "Location.h"
#include <vector>
#include <sstream>
#include <string>
#include <stack>

using namespace std;


// Vertex struct for the graph class. 
// Contains a location, a name of 
// the location, and a vector of connections
struct Vertex {
	Location location;
	string name;
	vector <Vertex*> neighbors;
	bool visited;
};

class Map {

public:
	// paramaterized constructor
	// takes two fileNames and initializes a Map obj by reading
	// in the contents of the two files
	Map(string vertexFile, string edgeFile);

	// run
	// takes nothing and returns nothing
	// processes commands given from cin
	void run();

private:

	// This is a vector of Vertex, which represents the graph.
    vector<Vertex> graph;

    // number of vertices
    int numVertices;

    // Helper functions

	// readVertices
	// takes a string fileName and returns nothing
	// loads the vertex data into the class obj
	void readVertices(string fileName);

	// readEdges
	// takes a string fileName and returns nothing
	// loads the edge data into the class obj
	void readEdges(string fileName);

	// printDistance
	// takes two city names, returns nothing
	// executes the "dist" command
	void printDistance(string city1, string city2);

	// printVertices
	// takes nothing and returns nothing
	// executes the "list" command
	void printVertices();

	// findPath
	// takes two city names and a string representing 
	// the number of paths to print
	// returns nothing
	// executes the "path command"
	void findPath(string city1, string city2, string maxPaths);

	// pathHelper
	// takes a current vertex, a goal vertex, and a pointer to a stack
	// returns void
	// helper function that finds a path
	void printAllPaths(Vertex * current, Vertex * goal, Vertex* *path, 
		int &index, int &toPrint, int &printed);

	// printPath
	// takes an array of vertex pointers, and three integers by reference
	// returns void
	// prints one path
	void printPath(Vertex* *path, int &printed, int &index, int &toPrint);

	// IntPathDist
	// takes an array of vertex pointers, and an integer
	// returns an int
	// returns the distance (as an int) b/w two cities in a path
	int IntPathDist(Vertex* *path, int i);

};

#endif