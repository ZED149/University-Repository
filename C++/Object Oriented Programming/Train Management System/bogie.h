#pragma once



#include "person.h"
#include "adult.h"
#include "kid.h"
#include <string>
using namespace std;



class bogie
{
	unsigned int id;
	int numberOfAdults, numberOfKids;
	string familyName;
	bogie * next;
	person * adults, *kids;
	static unsigned int bogieCounter;
	static int abcForAdults, abcForKids;
public:

	/******************************************/
	//Constructors

	//Default Constructor
	bogie();

	//Constructor with params
	bogie(const unsigned int id);

	//Copy Constructor
	//bogie(const bogie &obj);

	
	/******************************************/
	//Destructor
	~bogie();


	/******************************************/
	//Member Functions

	//Print
	void print();

	void print(const int dummy);

	//Add Passengers
	bool addPassengers(const int id);


	//File Reading for Adults
	person* fileReadingAdults(string filename);


	//File Reading for Kids
	person* fileReadingKids(string filename);


	//Save Data
	void saveData();


	//Load Data
	void loadData();


	/******************************************/
	//Getters

	//Next
	bogie * getNext()const;


	//ID
	int getId()const;


	//Bogie Counter
	static int getBogieCounter();



	/******************************************/
	//Setters

	//Next
	void setNext(bogie * obj);
};