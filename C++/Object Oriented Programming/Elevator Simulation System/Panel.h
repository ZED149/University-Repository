
#pragma once


// This class contains the Panel class

// including libraries
#include <queue>


class Panel
{
public:

	struct Button
	{
		string label;
	};

	// Constructor
	Panel()
	{
		this->up.label = "up";
		this->down.label = "down";
	}

	// data members
	Button up;						// button for going up
	Button down;					// button for going down
	queue<Button> instructions;		// queue containing order of panel, means order of working of lift
	string label;

	// member functions
	
	// press
	void press(string code) 
	{
		this->label = code;
		if (strcmp(code.c_str(), "up") == 0)
			this->instructions.push(up);
		else if (strcmp(code.c_str(), "down") == 0)
			this->instructions.push(down);
	};
};