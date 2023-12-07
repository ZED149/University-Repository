#pragma once




#include "bogie.h"
#include <string>
using namespace std;



class train
{
	bogie * engine;
	static int bogieCounter;
	static int numberOfBogiesInThisTrain;

	//Overloading Operators

	//Insertion Operator
	friend ostream& operator << (ostream &out, train &obj);

	//Extraction Operator
	friend istream& operator >> (istream &in, train &obj);
public:
	/******************************************/
	//Constructor

	//Default Constructor
	train();


	//Copy Constructor
	//train(const train &obj);

	
	/******************************************/
	//Destructor
	~train();



	/******************************************/
	//Getters

	//Number of Bogies in a Train
	int bogiesnumber();


	//Number of Bogies in this Train
	static int getNumberOfBogiesInThisTrain();


	/******************************************/
	//Member Functions

	//Add Bogie
	void addBogie(const int id);


	//Seacrh Bogie
	bool searchBogie(const int id);


	//Add Passengers
	void addPassengers(const int id);


	//Print data of specific Bogie
	void printDataOfSpecificBogie(const int id);


	//Print data of all Bogies
	void printDataOfAllBogies();


	//Print ID's of all Bogies
	void printIdOfAllBogies();


	//Remove Bogie
	bool removeBogie(const int id);



	//Save Data
	void saveData();


	//Load Data
	void loadData();



};