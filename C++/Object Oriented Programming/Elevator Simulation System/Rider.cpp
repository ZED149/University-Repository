

#include "Rider.h"
#include <iostream>
# include <string>
using namespace std;


// Constructor
Rider::Rider(string name, int age, int from, int to, bool goingUp, bool goingDown):
	rider_name(name), rider_age(age),
	from(from), to(to),
	goingUp(goingUp), goingDown(goingDown)
{
	/*cout << "Rider(params) called" << endl;*/
};

// print
void Rider::print()
{
	cout << this->rider_name << " " << this->rider_age;
	if (this->goingUp)
		cout << " UP" << endl;
	else if (this->goingDown)
		cout << " DOWN" << endl; 
}