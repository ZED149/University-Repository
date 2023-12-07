



#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "bogie.h"
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <cstdio>
#include "train.h"
#define color SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
using namespace std;



/********************************************* Static Variables *****************************************************/

//Bogie Counter
unsigned int bogie::bogieCounter = 0;


//
int bogie::abcForAdults = 0;

//
int bogie::abcForKids = 0;



/********************************************* Constructors *****************************************************/
//Default Constructor
bogie::bogie()
{
	this->id = 0;
	this->familyName = '\0';
	this->adults = this->kids = nullptr;
	this->next = nullptr;
	bogieCounter++;
	color 1);	//blue
	cout << "Bogie() Default called" << endl;
	color 7);	//white
}//default constructor




//Constructor with params
bogie::bogie(const unsigned int id)
{
	this->id = id;
	this->adults = this->kids = nullptr;
	this->familyName = '\0';
	this->next = nullptr;
	bogieCounter++;
	color 1);	//blue
	cout << "Bogie() with params called" << endl;
	color 7);	//white
}//constructor with params



/*
//Copy Constructor
bogie::bogie(const bogie &obj)
{
	color 1);	//blue
	cout << "Bogie() Copy called" << endl;
	color 7);	//white
}//copy constructor
*/





/********************************************* Destructor *****************************************************/
bogie::~bogie()
{
	color 3);	//cyan
	cout << "~Bogie() called for ID: " << this->id << endl;
	color 7);	//white
	if (this->numberOfAdults == 0)
		delete this->adults;
	else
		delete[] this->adults;

	if (this->numberOfKids == 0)
		delete this->kids;
	else
		delete[] this->kids;
	//delete this->next;
	next = nullptr;
	bogieCounter--;
}//destructor






/********************************************* Member Functions *****************************************************/





person* bogie::fileReadingAdults(string filename)
{
	person *adults = nullptr;
	//dynamic cast adult

	fstream fin(filename);
	char buff[500];
	string _name, _gender, _occupation, _qualification, _NIC;
	int _age, size, i=0;


	if (fin.is_open())
	{
		fin >> size;	//size of adults
		if (size >= 1 && size <= 4)
		{
			this->numberOfAdults = size;
			adults = new adult[numberOfAdults];
			adult* ptr = dynamic_cast<adult*>(adults);
			while (!fin.eof())
			{
				fin >> _name >> _gender >> _age >> _occupation >> _qualification >> _NIC;
				ptr[i++].input(_name, _gender, _age, _occupation, _qualification, _NIC);
			}//while
			fin.close();
			return adults;
		}
		else
		{
			return adults;
		}
	}
	else
	{
		color 4);	//red
		cout << "Unable to open file for Adults" << endl;
		color 7);	//white
		return adults;
	}
}//fileReadingAdults




//File Reading for Kids
person* bogie::fileReadingKids(string filename)
{
	person *kids = nullptr;
	//dynamic cast adult

	fstream fin(filename);
	char buff[500];
	string _name, _gender, _b_form_number;
	int _age, size, i = 0;


	if (fin.is_open())
	{
		fin >> size;	//size of adults
		if (size >= 1 && size <= 6)
		{
			this->numberOfKids = size;
			kids = new kid[numberOfKids];
			kid* ptr = dynamic_cast<kid*>(kids);
			while (!fin.eof())
			{
				fin >> _name >> _gender >> _age >> _b_form_number;
				ptr[i++].input(_name, _gender, _age, _b_form_number);
			}//while
			fin.close();
			return kids;
		}
		else
		{
			return kids;
		}
	}
	else
	{
		color 4);	//red
		cout << "Unable to open file for Adults" << endl;
		color 7);	//white
		return kids;
	}
}//fileReadingKids



//Print
void bogie::print()
{
	system("cls");
	cout << "Print() of bogie called" << endl;
	color 11);	//violet
	cout << "Family Name: ";
	color 8);	//light grey
	cout << this->familyName << endl;
	color 11);	//violet
	cout << "Bogie ID: ";
	color 8);	//light grey
	cout << this->id << endl;

	//DYNAMIC CAST to avoid error
	//ERROR: is that we cant access more than one object
	//of derived class using a base class pointer so we
	//we use seperate input functions and dynamic_cast base
	//class pointer and call print etc functions using derived
	//class pointer.


	//FOR ADULTS
	if (this->numberOfAdults == 0)
	{
		color 4);	//red
		cout << "No data to be printed in adults" << endl;
		color 7);	//white
	}
	else if (this->numberOfAdults > 0 && this->numberOfAdults < 5)
	{
		color 6);	//yellow
		cout << "Data of Adults: " << endl;
		adult *aptr = dynamic_cast<adult*>(this->adults);
		for (int i = 0; i < this->numberOfAdults; i++)
		{
			color 2);	//green
			cout << "Adult " << i + 1 << endl;
			aptr[i].print();
			color 7);	//white
		}//for
		aptr = nullptr;
		delete aptr;
	}
	else
	{
		color 4);	//red
		cout << "Bogie can't have more than 4 adults" << endl;
		cout << "No. of adults entered by the user are: ";
		color 6);	//yellow
		cout << this->numberOfAdults << endl;
		color 7);	//white
	}


	//FOR KIDS
	if (this->numberOfKids == 0)
	{
		color 4);	//red
		cout << "No data to be printed in kids" << endl;
		color 7);	//white
	}
	else if (this->numberOfKids > 0 && this->numberOfKids < 7)
	{
		//DYNAMIC CAST to avoid error
		//ERROR: is that we cant access more than one object
		//of derived class using a base class pointer so we
		//we use seperate input functions and dynamic_cast base
		//class pointer and call print etc functions using derived
		//class pointer.

		color 6);	//yellow
		cout << "Data of Kids: " << endl;
		kid *kptr = dynamic_cast<kid*>(this->kids);
		for (int i = 0; i < this->numberOfKids; i++)
		{
			color 2);	//green
			cout << "Kid " << i + 1 << endl;
			kptr[i].print();
			color 7);	//white
		}//for
		kptr = nullptr;
		delete kptr;
	}
	else
	{
		color 4);	//red
		cout << "Bogie can't have more than 6 kids" << endl;
		cout << "No. of kids entered by the user are: ";
		color 6);	//yellow
		cout << this->numberOfKids << endl;
		color 7);	//white
	}
}//print



//Print for all Bogies
void bogie::print(const int dummy)
{
	cout << "Print() of bogie called" << endl;
	color 11);	//violet
	cout << "Family Name: ";
	color 8);	//light grey
	cout << this->familyName << endl;
	color 11);	//violet
	cout << "ID: ";
	color 8);	//light grey
	cout << this->id << endl;

	//DYNAMIC CAST to avoid error
	//ERROR: is that we cant access more than one object
	//of derived class using a base class pointer so we
	//we use seperate input functions and dynamic_cast base
	//class pointer and call print etc functions using derived
	//class pointer.

	if (this->numberOfAdults == 0)
	{
		color 4);	//red
		cout << "No data to be printed in adults" << endl;
		color 7);	//white
	}
	else if (this->numberOfAdults > 0 && this->numberOfAdults < 5)
	{
		color 6);	//yellow
		cout << "Data of Adults: " << endl;
		adult *aptr = dynamic_cast<adult*>(this->adults);
		for (int i = 0; i < this->numberOfAdults; i++)
		{
			color 2);	//green
			cout << "Adult " << i + 1 << endl;
			aptr[i].print();
			color 7);	//white
		}//for
		aptr = nullptr;
		delete aptr;
	}
	else
	{
		color 4);	//red
		cout << "Bogie can't have more than 4 adults" << endl;
		cout << "No. of adults entered by the user are: ";
		color 6);	//yellow
		cout << this->numberOfAdults << endl;
		color 7);	//white
	}

	if (this->numberOfKids == 0)
	{
		color 4);	//red
		cout << "No data to be printed in kids" << endl;
		color 7);	//white
	}
	else if (this->numberOfKids > 0 && this->numberOfKids < 7)
	{
		//DYNAMIC CAST to avoid error
		//ERROR: is that we cant access more than one object
		//of derived class using a base class pointer so we
		//we use seperate input functions and dynamic_cast base
		//class pointer and call print etc functions using derived
		//class pointer.

		color 6);	//yellow
		cout << "Data of Kids: " << endl;
		kid *kptr = dynamic_cast<kid*>(this->kids);
		for (int i = 0; i < this->numberOfKids; i++)
		{
			color 2);	//green
			cout << "Kid " << i + 1 << endl;
			kptr[i].print();
			color 7);	//white
		}//for
		kptr = nullptr;
		delete kptr;
	}
	else
	{
		color 4);	//red
		cout << "Bogie can't have more than 6 kids" << endl;
		cout << "No. of kids entered by the user are: ";
		color 6);	//yellow
		cout << this->numberOfKids << endl;
		color 7);	//white
	}
}//print for all bogies







//Add Passengers
bool bogie::addPassengers(const int id)
{
	if (id < 0)
		return false;
	else
	{
		//variables for string data in adults
		string family_name, _occupation, _qualification, _NIC;
		//variables for string data in kids
		string b_form_number;
		//variables for storing data in person
		string _name, _gender;
		int _age;
		//id
		int _id;


		

		this->numberOfAdults = 1;
		cout << "Enter number of adults to be added in bogie ID: ";
		color 2);	//green
		cout << this->id << endl;
		color 7);	//white
		cin >> this->numberOfAdults;
		

		
		if (numberOfAdults == 0)
		{
			color 4);	//red
			cout << "No Adults to be added" << endl;
			color 7);	//white
		}
		else if (numberOfAdults < 0)
		{
			color 4);	//red
			cout << "No. of Adults can't be negative" << endl;
			color 7);	//white
		}
		else if(numberOfAdults<5)	//if there are some adults to be added
		{
			//code for adults to add manually


			//FOR ADULTS
			system("cls");
			cout << "Enter Family Name" << endl;
			cin >> familyName;
			
			this->adults = new adult[numberOfAdults];
			//dynamic cast to avoid error
			adult *ptr = dynamic_cast<adult*>(adults);
			for (int i = 0; i < numberOfAdults; i++)
			{
				cout << "Enter information of Adult: " << i + 1 << endl;
				cout << "Enter Name" << endl;
				cin >> _name;
				cout << "Enter Gender" << endl;
				cin >> _gender;
				cout << "Enter Age" << endl;
				cin >> _age;
				cout << "Enter Occupation" << endl;
				cin >> _occupation;
				cout << "Enter Qualification" << endl;
				cin >> _qualification;
				cout << "Enter NIC" << endl;
				cin >> _NIC;
				ptr[i].input(_name, _gender, _age, _occupation, _qualification, _NIC);
			}//for

			ptr = nullptr;
			delete ptr;
			

			/*
			//code for adults to read from file
			string filename = "C:/Users/ZED/Desktop/Project/adult.txt";
			this->adults = fileReadingAdults(filename);
			if (this->adults == nullptr)
				this->numberOfAdults = 0;
			*/
			
		}
		else
		{
			color 4);	//red
			cout << "Bogie can't have more than 4 adults" << endl;
			color 7);	//white
		}



		//FOR KIDS
		this->numberOfKids = 1;
		cout << "Enter number of kids to be added" << endl;
		cin >> numberOfKids;
		

		
		if (numberOfKids == 0)
		{
			color 4);	//red
			cout << "No kids to be added" << endl;
			color 7);	//white
		}
		else if (numberOfKids < 0)
		{
			color 4);	//red
			cout << "No. of kids can't be negative" << endl;
			color 7);	//white
		}
		else if(numberOfKids<7)		//if there are some kids to be added
		{
			//code for kids to enter manually

			
			this->kids = new kid[numberOfKids];
			//dynamic cast to avoid error
			kid *ptr = dynamic_cast<kid*>(kids);
			for (int i = 0; i < numberOfKids; i++)
			{
				cout << "Enter information of kid" << i + 1 << endl;
				cout << "Enter Name" << endl;
				cin >> _name;
				cout << "Enter Gender" << endl;
				cin >> _gender;
				cout << "Enter Age" << endl;
				cin >> _age;
				cout << "Enter B_Form_Number" << endl;
				cin >> b_form_number;
				ptr[i].input(_name, _gender, _age, b_form_number);
			}//for

			ptr = nullptr;
			delete ptr;
			

			/*
			//code for kids to read from file
			string filename = "C:/Users/ZED/Desktop/Project/kid.txt";
			this->kids = fileReadingKids(filename);
			if (this->kids == nullptr)
				this->numberOfKids = 0;
			*/
		}
		else
		{
			color 4);	//red
			cout << "Bogie can't contain more than 6 kids" << endl;
			color 7);	//white
		}


		color 2);	//green
		cout << "Informaion of Adults and Kids added successfully" << endl;
		color 7);	//white
	}
}//add passengers




//Save Data
void bogie::saveData()
{
	/*
	char buff[1000];

	//code to save data from one file to another file
	
	FILE *p;
	p = fopen("C:/Users/ZED/Desktop/project/adultSave.txt", "w");

	if (p)
	{
		color 2);	//green
		cout << "File for saving opened successfully for adults" << endl;
		color 7);	//white
	}
	else
	{
		color 4);	//red
		cout << "Unable to open file for saving for adults" << endl;
		color 7);	//white
	}
	


	//FOR ADULTS
	fstream fin("C:/Users/ZED/Desktop/project/adult.txt", ios::app | ios::out | ios::in);
	if (fin.is_open())
	{
		fin.getline(buff, 500);	//wasting one line for size
		color 2);	//green
		cout << "File for reading opened succesfully for adults" << endl;
		color 7);	//white

		while (!fin.eof())
		{
			fputs("#: ", p);
			fin.getline(buff, 1000, '\n');
			fputs(buff, p);
			fputs("\n", p);
		}//while
		fin.close();
		fclose(p);
	}
	else
	{
		color 4);	//red
		cout << "Unable to open file fir reading for adults" << endl;
		color 7);	//white
	}


	//FOR KIDS

	p = fopen("C:/Users/ZED/Desktop/project/saveKids.txt", "w");

	if (p)
	{
		color 2);	//green
		cout << "File for saving opened successfully for kids" << endl;
		color 7);	//white
	}
	else
	{
		color 4);	//red
		cout << "Unable to open file for saving for kdis" << endl;
		color 7);	//white
	}



	fin.open("C:/Users/ZED/Desktop/project/kid.txt",  ios::out | ios::in | ios::app);

	if (fin.is_open())
	{
		fin.getline(buff, 500);		//wasting one line for size
		color 2);	//green
		cout << "File for reading opened successfully for kids" << endl;
		color 7);	//white


		while(!fin.eof())
		{
			fputs("#: ", p);
			fin.getline(buff, 500, '\n');
			fputs(buff, p);
			fputs("\n", p);
		}//while

		fin.close();
		fclose(p);
	}
	else
	{
		color 4);	//red
		cout << "Unable to open file for reading of kids" << endl;
		color 7);	//white
	}
	*/


	//code to save data from runtime


	

	ofstream fout("C:/Users/ZED/Desktop/project/adultSave.txt", ios::app);
	if (fout.is_open())
	{
		adult *ptr = dynamic_cast<adult *>(this->adults);
		color 2);	//green
		cout << "File opened successfully for saving of adults" << endl;
		color 7);	//white

		//fout << train::getNumberOfBogiesInThisTrain() << endl;
		fout << this->numberOfAdults << endl;

		for (int i = 0; i < this->numberOfAdults; i++)
		{
			fout << ptr[i].getName() << " " << ptr[i].getGender() << " " << ptr[i].getAge() << " " << ptr[i].getOccupation() << " " << ptr[i].getQualification() << " " << ptr[i].getNIC() << endl;
		}//for
		fout.close();
	}
	else
	{
		color 4);	//red
		cout << "Unable to open file for saving of adults" << endl;
		color 7);	//white
	}

	

	fout.open("C:/Users/ZED/Desktop/project/kidSave.txt", ios::app);
	if (fout.is_open())
	{
		color 2);	//green
		cout << "File opened successfully for saving of kids" << endl;
		color 7);	//white
		//fout << train::getNumberOfBogiesInThisTrain() << endl;
		fout << this->numberOfKids << endl;
		kid *ptr = dynamic_cast<kid*>(kids);

		for (int i = 0; i < numberOfKids; i++)
		{
			fout << ptr[i].getName() << " " << ptr[i].getGender() << " " << ptr[i].getAge() << " " << ptr[i].getBFormNumber() << endl;
		}//for

		fout.close();
	}
	else
	{
		color 4);	//red
		cout << "Unable to open file for saving of kids" << endl;
		color 7);	//white
	}
	
}//saveData




//Load Data
void bogie::loadData()
{
	/*
	string junk;
	char buff[1000];

	ifstream fin("C:/Users/ZED/Desktop/project/adultSave.txt", ios::app | ios::out | ios::in);

	if (fin.is_open())
	{
		//variables to read adult data
		string _qualification, _occupation, _name, _gender, _NIC;
		int _age;


		int i = 0, counter=0;
		color 2);	//green
		cout << "Load data successfull" << endl;
		color 7);	//white



		while (!fin.eof())
		{
			counter++;
			fin >> junk;	//wasting indexes of file
			fin >> _name >> _gender >> _age >> _occupation >> _qualification >> _NIC;
			//ptr[i++].input(_name, _gender, _age, _occupation, _qualification, _NIC);
		}//while

		counter--;
		this->numberOfAdults = counter;
		this->adults = new adult[this->numberOfAdults];
		adult *ptr = dynamic_cast<adult *>(this->adults);

		fin.clear();

		while (!fin.eof())
		{
			fin >> junk;	//wasting indexes of file
			fin >> _name >> _gender >> _age >> _occupation >> _qualification >> _NIC;
			ptr[i++].input(_name, _gender, _age, _occupation, _qualification, _NIC);
		}//while
	}
	else
	{
		color 4);	//red
		cout << "Unable to open adult file for reading" << endl;
		color 7);	//white
	}
	*/



	//FOR ADULTS
	ifstream fin("C:/Users/ZED/Desktop/project/adultSave.txt", ios::app | ios::out | ios::in);

	if (fin.is_open())
	{
		color 2);	//green
		cout << "File for loading opened successfully for adults" << endl;
		color 7);	//white
		bool flag = true;
		int size = 0;
		char buff[500];
		for (int i = 0; i < this->abcForAdults; i++)
			fin.getline(buff, 500);

		//variables to read adult data
		string _qualification, _occupation, _name, _gender, _NIC;
		int _age, i = 0;


		fin.getline(buff, 500);
		fin >> size;
		this->numberOfAdults = size;
		this->abcForAdults = size+1;

		
		this->adults = new adult[this->numberOfAdults];
		adult *ptr = dynamic_cast<adult *>(this->adults);
		for (int j = 0; j < this->numberOfAdults; j++)
		{
			fin >> _name >> _gender >> _age >> _occupation >> _qualification >> _NIC;
			ptr[i++].input(_name, _gender, _age, _occupation, _qualification, _NIC);
		}//for
		
		
	}
	fin.close();



	//FOR KIDS
	fin.open("C:/Users/ZED/Desktop/project/kidSave.txt", ios::app | ios::in | ios::out);
	if (fin.is_open())
	{
		color 2);	//green
		cout << "File for Loading successfully opened for kids" << endl;
		color 7);	//white
		bool flag = true;
		int size = 0;
		char buff[500];
		for (int i = 0; i < this->abcForKids; i++)
			fin.getline(buff, 500);

		//variables to read adult data
		string _name, _gender, _b_Form_Number;
		int _age, i = 0;


		fin.getline(buff, 500);
		fin >> size;
		this->numberOfKids = size;
		this->abcForKids = size + 1;


		this->kids = new kid[this->numberOfKids];
		kid *ptr = dynamic_cast<kid *>(this->kids);
		for (int j = 0; j < this->numberOfAdults; j++)
		{
			fin >> _name >> _gender >> _age >> _b_Form_Number;
			ptr[i++].input(_name, _gender, _age, _b_Form_Number);
		}//for


	}
	fin.close();

}//loadData

/********************************************* Getters *****************************************************/


//NEXT
bogie* bogie::getNext()const
{
	return this->next;
}//getNext



//ID
int bogie::getId()const
{
	return this->id;
}//id



//Bogie Counter
int bogie::getBogieCounter()
{
	return bogieCounter;
}//getBogieCounter




/********************************************* Setters *****************************************************/

//Next
void bogie::setNext(bogie * obj)
{
	this->next = obj;
}//setNext