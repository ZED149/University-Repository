#pragma once



#include <string>
using namespace std;


#ifndef PERSON_H
#define PERSON_H
class person
{
	string name, gender;
	unsigned int age;
public:
	
	/******************************************/
	//Constructos

	//Default Constructor
	person();

	//Constructor with params
	person(const string name, const string gender, const unsigned int age);

	//Copy Constructor
	person(const person &obj);


	/******************************************/
	//Destructor
	virtual ~person();


	/******************************************/
	//Member Functions
	
	//Print
	virtual void print();


	//Input
	void input(const string name, const string gender, const int age);



	/******************************************/
	//Getters

	//Get Name
	string getName()const;

	//Get Gender
	string getGender()const;

	//Get Age
	int getAge()const;

};
#endif