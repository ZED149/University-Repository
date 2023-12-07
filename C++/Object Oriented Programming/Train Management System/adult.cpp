



#include "pch.h"
#include "adult.h"
#include <iostream>
#include <string>
#include <Windows.h>
#define color SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
using namespace std;



/********************************************* Constructor *****************************************************/
//Default Constructor
adult::adult():
	person()
{
	this->occupation = this->qualification = this->NIC = '\0';
	color 1);	//blue
	cout << "Adult() Default called" << endl;
	color 7);	//white
}//default constructor



//Constructor with params
adult::adult(const string occupation, const string qualification, const string NIC, const string name, const string gender, const unsigned int age) :
	person(name, gender, age)
{
	this->occupation = occupation;
	this->qualification = qualification;
	this->NIC = NIC;
	color 1);	//blue
	cout << "Adult() with params called" << endl;
	color 7);	//white
}//constructor with params



//Copy Constructor
adult::adult(const adult &obj, const person &obj1) :
	person(obj1)
{
	this->occupation = obj.occupation;
	this->qualification = obj.qualification;
	this->NIC = obj.NIC;
	color 1);	//blue
	cout << "Adult() Copy called" << endl;
	color 7);	//white
}//copy constructor



/********************************************* Destructor *****************************************************/
adult::~adult()
{
	color 3);	//cyan
	cout << "~Adult() caleld" << endl;
	color 7);	//white
}//destructor



/********************************************* Member Functions *****************************************************/

//Print
void adult::print()
{
	person::print();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	//red
	cout << "Print() of adult called" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);	//violet
	cout << "Occupation: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);	//light grey
	cout << this->occupation << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);	//violet
	cout << "Qualification: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);	//light grey
	cout << this->qualification << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);	//violet
	cout << "NIC: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);	//light grey
	cout << this->NIC << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//white
}//print



//Input
void adult::input(const string name, const string gender, const int age, const string occupation, const string qualification, const string NIC)
{
	cout << "Input() of adult called" << endl;
	this->occupation = occupation;
	this->qualification = qualification;
	this->NIC = NIC;
	person::input(name, gender, age);
}//input





/********************************************* Getters *****************************************************/

//Get Name
string adult::getName()const
{
	return person::getName();
}//getName


//Get Gender
string adult::getGender()const
{
	return person::getGender();
}//getGender


//Get Age
int adult::getAge()const
{
	return person::getAge();
}//getAge


//Get Occupation
string adult::getOccupation()const
{
	return this->occupation;
}//getOccupation


//Get Qualification
string adult::getQualification()const
{
	return this->qualification;
}//getQualification


//Get NIC
string adult::getNIC()const
{
	return this->NIC;
}//getNIC