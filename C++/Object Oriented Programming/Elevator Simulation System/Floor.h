


// This file contains the Floor class



// including libraries
#include <string>
#include <vector>
#include "Rider.h"
#include <queue>
#include "Panel.h"
using namespace std;

#ifndef FLOOR_H
#define FLOOR_H
class Floor
{
	// data members
	vector<Rider> riders_on_floor;	// vector containing all riders present on the floor
	queue<Rider> _hasUpRider;		// queue contianing riders for going up
	queue<Rider> _hasDownRider;		// queue containing riders for going down
	
public:
	// data members
	string floor_name;				// name of the floor
	int floor_id;					// floor number in the building
	Panel panel;					// panel for this particular floor

	// Constructor
	Floor(string floor_name="NaN", int floor_id = -9999);

	// member functions
	
	// print
	void print();

	// hasUpRider
	bool hasUpRider() const;

	// hasDownRider
	bool hasDownRider() const;

	// add_rider
	void add_rider(const Rider &rider);

	// getUpRiders
	int getUpRiders();

	// getDownRiders
	int getDownRiders();

	// operator overlaoding

	// <
	bool operator < (const Floor& obj) const
	{
		return this->floor_id < obj.floor_id ? true:false;
	}

	// >
	bool operator > (const Floor& obj) const
	{
		return this->floor_id > obj.floor_id ? true : false;
	}
};
#endif