

#pragma once

#include "Floor.h"
#include <vector>
// This file contains the Elevator class

class Elevator
{
	vector<Floor> floors;		// vector of floors on which this elevator can move up or down
	
public:
	// data members
	string state;				// position of elevator at the start of the program
	int starting_floor;			// starting floor of the elelvator at start of the program
	int riders;					// number of riders in the elevator

	// Constructor
	Elevator(string state="NaN", int starting_floor = 0, int riders = 0);

	// member functions
	
	// open_door
	void open_door();
};