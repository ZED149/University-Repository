



#include "pch.h"
#include "kid.h"
#include <iostream>
#include <string>
#include <Windows.h>
#define color SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
using namespace std;




/********************************************* Constructors *****************************************************/
//Default Constructor
kid::kid() :
	person()
{
	this->bFormNumber = '\0';
	color 1);	//blue
	cout << "Kid() called" << endl;
	color 7);	//white
}//default constructor



//Constructor with params
kid::kid(const string bFromNumber, const string name, const string gender, const unsigned int age) :
	person(name, gender, age)
{
	this->bFormNumber = bFromNumber;
	color 1);	//blue
	cout << "Kid() with Params called" << endl;
	color 7);	//white
}//constructor with params



//Copy Constructor
kid::kid(const kid &obj, const person &obj1) :
	person(obj1)
{
	this->bFormNumber = obj.bFormNumber;
	color 1);	//blue
	cout << "Kid() Copy called" << endl;
	color 7);	//white
}//copy constructor



/********************************************* Destructor *****************************************************/
kid::~kid()
{
	color 3);	//cyan
	cout << "~kid() called" << endl;
	color 7);	//white
}//destructor




/********************************************* Member Functions *****************************************************/

//Print
void kid::print()
{
	person::print();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	//red
	cout << "Print() of kid called" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);	//violet
	cout << "B_Form_Number: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);	//light grey
	cout << this->bFormNumber << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//white
}//print



//Input
void kid::input(const string name, const string gender, const int age, const string bFormNumber)
{
	cout << "Input() of kid called" << endl;
	this->bFormNumber = bFormNumber;
	person::input(name, gender, age);
}//input





/********************************************* Getters *****************************************************/
//Get BFormNumber
string kid::getBFormNumber()const
{
	return this->bFormNumber;
}//getBFormNumber