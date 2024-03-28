

#pragma once


// this file contains the Buidling class

// including libraries
#include "Floor.h"
#include <iostream>
#include "Elevator.h"
#include <vector>
using namespace std;

class Building
{
public:
	static vector<Floor> Floors;			// vector containing the list of floors that are present in this bulding
	static vector<Elevator> Elevators;		// vector containing list of lifts in the building

	// Constructor
	Building();

	// member funcitons
	
	// add_floor
	//void add_floor(const Floor& obj);
};