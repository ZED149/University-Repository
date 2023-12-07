


#include <iostream>
#include "array_adt.h"
using namespace std;



int main()
{
	array_ADT<char> obj1(10);
	array_ADT<char> obj2(10);

	obj1.insert('A');
	obj1.insert('b');
	obj1.insert('C');
	obj1.insert('d');
	obj1.insert('E');
	obj1.insert('f');

	obj2.insert('z');
	obj2.insert('Y');
	obj2.insert('x');
	obj2.insert('W');
	obj2.insert('v');

	cout << "Obj1 is: " << endl;
	obj1.print();
	cout << endl << "Obj2 is: " << endl;
	obj2.print();

	array_ADT<char> obj3 = array_ADT<char>::Merg(obj2, obj1, 1);
	cout << "Obj3 is: " << endl;
	obj3.print();
	cout << endl << "Obj3 is sorted or not: " << "[" << obj3.IsSorted() << "]\n";
	cout << endl << "Obj3 after sorting is: " << endl;
	obj3.Sort();
	obj3.print();
	cout << endl << "Obj3 is sorted or not: " << "[" << obj3.IsSorted() << "]\n";
}