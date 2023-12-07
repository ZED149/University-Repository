

#include <iostream>
#include "doubly_linked_list.h"
using namespace std;



int main()
{
	//My Testing
	/*{
		doubly_linked_list<int> obj;
		obj.insertAtEnd(1);
		cout << obj;

		cout << "Inserting more than 1 values to check" << endl;
		obj.insertAtStart(2);
		obj.insertAtStart(3);
		obj.insertAtStart(4);
		obj.insertAtStart(5);
		obj.insertAtStart(6);
		cout << obj;

		cout << "Inserting more than 1 values at end to check" << endl;
		obj.insertAtEnd(7);
		obj.insertAtEnd(8);
		obj.insertAtEnd(9);
		obj.insertAtEnd(10);
		obj.insertAtEnd(11);
		obj.insertAtEnd(12);
		cout << obj;

		cout << "Now checking delete at start" << endl;
		obj.deleteFromStart();
		cout << obj;

		cout << "Now checking delete from end" << endl;
		obj.deleteFromEnd();
		cout << obj;


		cout << "Now checking Insert Before" << endl;
		cout << obj.insertBefore(20, 4) << endl;
		cout << obj;

		cout << "Now checking Reverse Code" << endl;
		obj.reverse();
		cout << obj;
	}*/


	//Now Ma'am Testing
	doubly_linked_list<int> obj;
	obj.insertAtEnd(7);
	obj.insertAtEnd(9);
	obj.insertAtStart(11);
	obj.insertAtEnd(10);
	obj.insertAtEnd(2);
	cout << obj;
	obj.insertBefore(6, 7);
	cout << obj;
	obj.reverse();
	cout << obj;
}