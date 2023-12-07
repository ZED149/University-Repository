


#include "pch.h"
#include "train.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#define color SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
using namespace std;




/********************************************* Static Variables *****************************************************/

//Total number of bogies in a train
int train::bogieCounter = 0;

//Number of bogies in this train
int train::numberOfBogiesInThisTrain = 1;



/********************************************* Constructors *****************************************************/
//Default Constructor
train::train()
{
	engine = new bogie(0);
	bogieCounter++;
	color 1);	//blue
	cout << "Train() Default called" << endl;
	color 7);	//white
}//default constructor



//Copy Constructor







/********************************************* Destructor *****************************************************/
train::~train()
{
	color 3);	//cyan
	cout << "~Train() called" << endl;
	color 7);	//white
	if (engine==nullptr)
	{
		delete engine;
		engine = nullptr;
	}
	else
	{
		bogie *p = engine, *temp=p;
		while (p != nullptr)
		{
			temp = p;
			p = p->getNext();
			delete temp;
		}
		//delete p, temp;
		//delete  engine;
		engine = nullptr;
	}
}//destructor





/********************************************* Member Functions *****************************************************/

//Add Bogie
void train::addBogie(const int id)
{
	if (id < 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	//red
		cout << "Can't add bogie with a negative ID (" << id << ")" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//white
	}
	else
	{
		cout << "addBogie(" << id << ") called" << endl;
		bogie * temp = new bogie(id);
		if (engine == nullptr)
			engine->setNext(temp);		//engine = temp;
		else
		{
			bogie * ptr = engine;
			while (ptr->getNext() != nullptr)
				ptr = ptr->getNext();
			ptr->setNext(temp);
		}

		temp = nullptr;
		delete temp;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);	//green
		cout << "Bogie added with ID: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);	//light grey
		cout << id << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//white
		this->numberOfBogiesInThisTrain++;
	}
}//addBogie



//Seacrh Bogie
bool train::searchBogie(const int id)
{
	if (this->engine!=nullptr)	//bogie::getBogieCounter() >= 1 (Alternate Condition)
	{
		if (id < 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	//red
			cout << "Can't search bogie with a negative ID" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//white
			return false;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);	//green
			cout << "searchBogie(" << id << ") called" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//white
			bogie *temp = this->engine;
			bool flag = false;
			while (temp->getNext() != nullptr && !flag)
			{
				if (temp->getId() == id)
					flag = true;
				temp = temp->getNext();
			}//while
			if (temp->getId() == id)
				flag = true;

			temp = nullptr;
			delete temp;

			if (flag)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);	//green
				cout << "Searched Bogie is: ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);	//light grey
				cout << id << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//white
			}

			//return statement
			return (flag == true) ? true : false;
		}
	}
	else
	{
		cout << "No bogies to be searched" << endl;
		return false;
	}
}//searchBogie




//Add Passengers
void train::addPassengers(const int id)
{
	bogie *p = engine, *temp = engine;
	bool flag = true;
	while (p != nullptr && flag)
	{
		if (p->getId() == id)
		{
			temp = p;
			flag = false;
		}
		p = p->getNext();
	}//while

	temp->addPassengers(id);
}//addPassengers




//Print data of specific Bogie
void train::printDataOfSpecificBogie(const int id)
{
	cout << "PrintDataOfSpecificBogie() called" << endl;

	bool flag = true;
	bogie*p = engine, *temp=nullptr;

	while (p != nullptr && flag)
	{
		if (p->getId() == id)
		{
			temp = p;
			flag = false;
		}
		p=p->getNext();
	}//while

	temp->print();
	p = nullptr;
	delete p;
	temp = nullptr;
	delete temp;
}//print data of specific bogie




//Print data of all Bogies
void train::printDataOfAllBogies()
{
	system("cls");
	cout << "PrintDataOfAllBogies() called" << endl;

	bogie *p = engine;
	int i = 0;
	while (p != nullptr)
	{
		color 6);	//yellow
		cout << "Data of Bogie ";
		color 8);	//light grey
		cout << i++;
		color 6);	//yellow
		cout << " is" << endl;
		color 7);	//white
		p->print(0);
		p = p->getNext();
	}//while
	
}//print data of all bogies




//Print ID's of all Bogies
void train::printIdOfAllBogies()
{
	system("cls");
	cout << "PrintIdOfAllBogies() called" << endl;

	color 11);	//violet
	cout << "Total Bogies are: ";
	color 8);	//light grey
	cout << bogie::getBogieCounter() << endl;
	color 7); //white

	bogie *p = engine;
	int i = 0;
	while (p != nullptr)
	{
		color 11);	//violet
		cout << "ID of Bogie ";
		color 8);	//light grey
		cout << i++;
		color 11);	//violet
		cout << " is ";
		color 8);	//light grey
		cout << p->getId() << endl;
		p = p->getNext();
	}//while

	color 7);	//white
	p = nullptr;
	delete [] p;
}//print id of all bogies




//Remove Bogie
bool train::removeBogie(const int id)
{
	bogie*p = engine;
	bool flag = true;
	if (engine->getId() == id)
	{
		color 4);	//red
		cout << "Engine cannot be removed\n";
		color 7);	//white
		flag = false;
	}
	else
	{
		color 2);	//green
		cout << "removeBogie(" << id << ") called" << endl;
		color 7);	//white
		bool flag = true;
		bogie *p = engine, *temp = nullptr, *temp1 = nullptr, *temp2 = nullptr;
		while (p->getNext() != nullptr && flag)
		{

			if (p->getId() == id)
			{
				temp = p;	//wo bogie jisne remove huna ha
				flag = false;
			}
			if (flag)
				temp1 = p;	//wo bogie jo remove hune wali bogie se phly ati ha
			p = p->getNext();
			temp2 = p;	//wo bogie jo remove hune wali bogie k baad ati ha
		}//while
		if (!flag)
		{
			delete temp;
			temp1->setNext(temp2);
			color 2);	//green
			cout << "Bogie removed with ID: ";
			color 8);	//light grey
			cout << id << endl;
			color 7);	//white
			this->numberOfBogiesInThisTrain--;
			return true;
		}
		else
		{
			temp = p;
			if (temp == temp2)
				temp2 = nullptr;
			delete temp;
			temp1->setNext(temp2);
			color 2);	//green
			cout << "Bogie removed with ID: ";
			color 8);	//light grey
			cout << id << endl;
			color 7);	//white
			this->numberOfBogiesInThisTrain--;
			return true;
		}

	}
}//removeBogie





//Save Data
void train::saveData()
{
	ofstream fout("C:/Users/ZED/Desktop/project/adultSave.txt");
	fout << train::getNumberOfBogiesInThisTrain() << endl;
	fout.close();
	fout.open("C:/Users/ZED/Desktop/project/kidSave.txt");
	fout << train::getNumberOfBogiesInThisTrain() << endl;
	fout.close();
	bogie *p = engine;
	while (p != nullptr)
	{
		p->saveData();
		p = p->getNext();
	}
	p = nullptr;
}//saveData




//Load Data
void train::loadData()
{
	int jugaad = 0;
	ifstream fin("C:/Users/ZED/Desktop/project/adultSave.txt", ios::app | ios::out | ios::in);
	fin >> jugaad;
	fin.clear();
	fin.close();
	if (jugaad > 1)		//if there are are bogies to be loaded i.e number of bogies > 1
	{
		for (int i = 1; i < jugaad; i++)
		{
			this->addBogie(i);
		}//for
		bogie *p = engine;
		while (p != nullptr)
		{
			p->loadData();
			p = p->getNext();
		}//while
	}
	else	//if there are no bogies to be added i.e number of bogies == 0
	{
		color 4);	//red
		cout << "No data to be loaded" << endl;
		color 7);	//white
	}
}//loadData



/********************************************* Getters *****************************************************/

//Bogies Number
int train::bogiesnumber()
{
	return bogie::getBogieCounter();
}//no. of bogies in a train



//Number of Bogies in This train
int train::getNumberOfBogiesInThisTrain()
{
	return numberOfBogiesInThisTrain;
}



/********************************************* Overloaded Operators *****************************************************/

//Insertion Opertor	"<<"
ostream& operator << (ostream &out, train &obj)
{
	cout << "Which Print do you want to call" << endl;
	cout << "'1' for Print data of all bogies" << endl;
	cout << "'2' for Print ID's of all bogies" << endl;
	cout << "'3' for Print data of a specific bogie" << endl;

	int printData = 0;
	cin >> printData;
	if (printData>=1 && printData<=3)	//Domain [1,3]
	{
		switch (printData)
		{
		case 1:
			obj.printDataOfAllBogies();
			break;
		case 2:
			obj.printIdOfAllBogies();
			break;
		case 3:
			cout << "Enter ID of bogie to print data" << endl;
			int id;
			cin >> id;
			if (obj.searchBogie(id))
				obj.printDataOfSpecificBogie(id);
			else
				cout << "Bogie with ID: " << id << " doesn't exists" << endl;
			break;
		default:
			color 4);	//red
			cout << "Invalid Selection" << endl;
			color 7);	//white
		}//switch
	}
	else
	{
		color 4);	//red
		cout << "Please select from given options" << endl;
		color 7);	//white
	}

	return out;
}//insertion operator



//Extraction Operator	">>"
istream& operator >> (istream &in, train &obj)
{
	cout << "Enter number of bogies you want to add" << endl;

	int numberOfBogies;
	cin >> numberOfBogies;

	for (int i = 1; i <= numberOfBogies; i++)
	{
		if (obj.searchBogie(i))
		{
			color 4);	//red
			cout << "Can't add bogie with ID: " << i << endl;
			cout << "Bogie with ID: " << i << " already exits" << endl;
			color 7);	//white
		}
		else
		{
			obj.addBogie(i);
			//obj.addPassengers(i);
		}
	}//for


	return in;
}//extraction operator