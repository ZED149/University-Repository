



#include <iostream>
#include "slist.h"
using namespace std;


template <typename T>
void printEmpty(slist<T> obj)
{
	if (obj.isEmpty())
		cout << "List is EMPTY" << endl;
	else if (!obj.isEmpty())
		cout << "List is NOT EMPTY" << endl;
}


int main()
{
	slist<int> obj;
	obj.insertAtHead(1);
	obj.insertAtHead(2);
	obj.insertAtHead(3);
	obj.insertAtHead(4);
	obj.insertAtTail(5);
	obj.insertAtTail(6);
	obj.insertAtTail(7);
	obj.insertAtTail(8);
	printEmpty(obj);
	obj.Print();
	obj.removeAtHead();
	obj.Print();
	obj.removeAtHead();
	obj.removeAtHead();
	obj.removeAtHead();
	obj.removeAtHead();
	obj.removeAtHead();
	obj.removeAtHead();
	obj.Print();
	obj.removeAtHead();
	obj.Print();
	printEmpty(obj);

	cout << "Check Again" << endl;
	obj.insertAtTail(1);
	obj.insertAtTail(2);
	obj.insertAtTail(3);
	obj.insertAtTail(4);
	obj.insertAtTail(5);
	obj.insertAtHead(6);
	obj.insertAtHead(7);
	obj.insertAtHead(8);
	obj.insertAtHead(9);
	obj.insertAtHead(10);
	printEmpty(obj);
	obj.Print();

	obj.removeAtTail();
	obj.Print();
	obj.removeAtHead();
	obj.Print();
	obj.removeAtTail();
	obj.removeAtTail();
	obj.removeAtTail();
	obj.removeAtTail();
	obj.removeAtTail();
	obj.removeAtTail();
	obj.removeAtTail();
	printEmpty(obj);
	obj.Print();
	obj.removeAtTail();
	printEmpty(obj);
	cout << "---From Here" << endl;
	obj.Print();

	cout << "Check ultra" << endl;
	obj.insertAtTail(1);
	obj.insertAtTail(2);
	obj.insertAtTail(3);
	obj.insertAtTail(4);
	obj.insertAtTail(5);
	obj.insertAtHead(6);
	obj.insertAtHead(7);
	obj.insertAtHead(8);
	obj.insertAtHead(9);
	obj.insertAtHead(10);
	printEmpty(obj);
	obj.Print();
	obj.removeAtKey(6);
	obj.Print();
	obj.removeAtKey(10);
	obj.Print();
	obj.removeAtKey(5);
	obj.Print();
	//obj.removeAtKey(1);
	obj.removeAtKey(2);
	obj.removeAtKey(3);
	obj.removeAtKey(4);
	//obj.removeAtKey(7);
	obj.removeAtKey(8);
	obj.removeAtKey(9);
	obj.Print();
	obj.removeAtKey(1);
	obj.Print();
	obj.removeAtKey(7);
	printEmpty(obj);



	cout << "Checking COPY CONSTRUCTOR " << endl;
	
	obj.insertAtTail(1);
	slist<int> obj1 = obj;
	obj1.Print();
	printEmpty(obj1);


	cout << "Checking REVERSE code" << endl;
	obj1.reverse();
	obj1.Print();
}