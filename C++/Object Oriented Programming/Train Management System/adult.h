#pragma once




#include "person.h"
#include <string>
using namespace std;


class adult:public person
{
	string occupation, qualification, NIC;
public:

	/******************************************/
	//Constructors

	//Default Constructor
	adult();

	//Constructor with params
	adult(const string occupation, const string qualification, const string NIC, const string name, const string gender, const unsigned int age);

	//Copy Constructor
	adult(const adult &obj, const person &obj1);



	/******************************************/
	//Destructor
	~adult();


	/******************************************/
	//Member Functions

	//Print
	void print();


	//Input
	void input(const string name, const string gender, const int age, const string occupation, const string qualification, const string NIC);



	/******************************************/
	//Getters

	//Get Name
	string getName()const;

	//Get Gender
	string getGender()const;

	//Get Age
	int getAge()const;

	//Get Occupation
	string getOccupation()const;

	//Get Qualification
	string getQualification()const;

	//Get NIC
	string getNIC()const;
};