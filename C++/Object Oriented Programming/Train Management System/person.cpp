



#include "pch.h"
#include "person.h"
#include <iostream>
#include <string>
#include <Windows.h>
#define color SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
using namespace std;


/********************************************* Constructor *****************************************************/

//Default Constructor
person::person()
{
	this->name = this->gender = '\0';
	this->age = 0;
	color 1);	//blue
	cout << "Person() Default called" << endl;
	color 7);	//white
}//default constructor


//Constructor with params
person::person(const string name, const string gender, const unsigned int age)
{
	this->name = name;
	this->gender = gender;
	this->age = age;
	color 1);	//blue
	cout << "Person() with Params called" << endl;
	color 7);	//white
}//constructor with params


//Copy Constructor
person::person(const person &obj)
{
	this->name = obj.name;
	this->gender = obj.gender;
	this->age = obj.age;
	color 1);	//blue
	cout << "Person() Copy called" << endl;
	color 7);	//white
}//copy constructor



/********************************************* Destructor *****************************************************/
person::~person()
{
	color 3);	//cyan
	cout << "~Person() called" << endl;
	color 7);	//white
}//destructor



/********************************************* Member Functions *****************************************************/

//Print
void person::print()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	//red
	cout << "Print() of person called" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);	//violet
	cout << "Name: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);	//light grey
	cout << this->name << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);	//violet
	cout << "Gender: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);	//light grey
	cout << this->gender << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);	//violet
	cout << "Age: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);	//light grey
	cout << this->age << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//white
}//print



//Input
void person::input(const string name, const string gender, const int age)
{
	cout << "Input() of person called" << endl;
	this->name = name;
	this->gender = gender;
	this->age = age;
}//input





/********************************************* Getters *****************************************************/
//Get Name
string person::getName()const
{
	return this->name;
}//getName


//Get Gender
string person::getGender()const
{
	return this->gender;
}//getGender


//Get Age
int person::getAge()const
{
	return this->age;
}//getAge