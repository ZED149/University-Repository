
#pragma once

// This file contains the Rider class

// including libraries
#include <string>
using namespace std;

class Rider
{
	// data members
	string rider_name;			// name of the rider
	int rider_age;				// age of the rider
	
public:
	// data members
	int from;					// starting floor of the rider on the elevator
	int to;						// destination floor of the rider to arrive on
	const bool goingUp;			// index of floor on which rider is currenlty on
	const bool goingDown;		// index of floor on which rider is going through elevator
	// Constructor
	Rider(string name="NaN", int age=-1, 
		int from = -1, int to = -1,
		bool goingUp = 0, bool goingDown = 0);

	// print
	void print();
};