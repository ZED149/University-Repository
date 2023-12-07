#pragma once



#include "person.h"
#include <string>
using namespace std;


class kid:public person
{
	string bFormNumber;
public:

	/******************************************/
	//Constructors

	//Default Constructor
	kid();

	//Constructor with params
	kid(const string bFormNumber, const string name, const string gender, const unsigned int age);

	//Copy Constructor
	kid(const kid &obj, const person &obj1);


	/******************************************/
	//Destructor
	~kid();



	/******************************************/
	//Member Functions

	//Print
	void print();


	//Input
	void input(const string name, const string gender, const int age, const string bFormNumber);



	/******************************************/
	//Getters

	//Get BFormNumber
	string getBFormNumber()const;
};