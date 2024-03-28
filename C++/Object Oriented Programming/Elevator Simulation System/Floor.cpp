

#include "Floor.h"
#include <iostream>
#include <vector>
using namespace std;


// Contructor
Floor::Floor(string floor_name, int floor_id):
	floor_name(floor_name), floor_id(floor_id)
{
	/*cout << "Floor(params) called" << endl;*/
}

// print
void Floor::print()
{
	cout << "Floor Name: " << this->floor_name << ", Floor ID: " << this->floor_id << endl;
	if (!this->riders_on_floor.empty())
	{
		cout << "Riders are as follows: " << endl;
		for (auto item : this->riders_on_floor)
			item.print();
		cout << "--------------------------------------" << endl;
	}
	else
	{
		cout << "No riders currenlty present on the floor" << endl;
		cout << "--------------------------------------" << endl;
	}
}

// add_rider
void Floor::add_rider(const Rider &rider)
{
	// add a rider to the vector
	this->riders_on_floor.push_back(rider);
	if (rider.goingUp)
	{
		// rider should press the button up
		this->panel.press("up");
		this->_hasUpRider.push(rider);
	}
	else if (rider.goingDown)
	{
		// rider should press the button down
		this->panel.press("down");
		this->_hasDownRider.push(rider);
	}
}

// hasUpRider
bool Floor::hasUpRider() const
{
	return !this->_hasUpRider.empty() ? true : false;
}

// hasDownRider
bool Floor::hasDownRider() const
{
	return !this->_hasDownRider.empty() ? true : false;
}

// getUpRiders
int Floor::getUpRiders()
{
	return this->_hasUpRider.size();
}

// getDownRiders
int Floor::getDownRiders()
{
	return this->_hasDownRider.size();
}