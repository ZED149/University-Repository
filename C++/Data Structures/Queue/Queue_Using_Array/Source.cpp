



#include <iostream>
#include "queue.h"
using namespace std;



int main()
{
	/*
	//Test Data 1
	queue<char> a;
	a.Print();
	a.Enqueue('A');
	a.Enqueue('B');
	a.Enqueue('C');
	a.Enqueue('D');
	a.Enqueue('E');
	a.Print();
	cout << "Dequeue Time" << endl;
	a.Dequeue();
	a.Print();
	a.Dequeue();
	a.Print();
	a.Dequeue();
	a.Print();
	a.Dequeue();
	a.Print();
	a.Dequeue();	//size = 0; sab nikal gaya
	a.Print();
	cout << "Check Time " << endl;
	a.Dequeue();
	a.Print();

	cout << "---------------------------------" << endl;
	cout << "Ultimate Test" << endl;
	a.Enqueue('A');
	a.Enqueue('B');
	a.Enqueue('C');
	a.Enqueue('D');
	a.Enqueue('E');
	a.Enqueue('F');
	a.Print();
	cout << "Dequeue Time" << endl; //idher tak ok ha
	a.Dequeue();
	a.Print();
	a.Dequeue();
	a.Print();
	a.Dequeue();
	a.Print();
	a.Dequeue();
	a.Print();
	a.Dequeue();
	a.Print();
	cout << "Check Time " << endl;
	a.Dequeue();
	a.Print();
	a.Dequeue();
	a.Print();

	cout << "--------------------------------------" << endl;
	cout << "Ultra Ultimate Test" << endl;
	cout << "---------------------------------" << endl;
	cout << "Ultimate Test" << endl;
	a.Enqueue('A');
	a.Enqueue('B');
	a.Enqueue('C');
	a.Enqueue('D');
	a.Enqueue('E');
	a.Enqueue('F');
	a.Enqueue('G');
	a.Print();
	cout << "Dequeue Time" << endl;
	a.Dequeue();
	a.Print();
	a.Dequeue();
	a.Print();
	a.Dequeue();
	a.Print();
	a.Dequeue();
	a.Print();
	a.Dequeue();
	a.Print();
	cout << "Check Time " << endl;
	a.Dequeue();
	a.Print();
	a.Dequeue();
	a.Print();
	a.Dequeue();
	a.Print();
	a.Dequeue();
	a.Print();
	*/


	//Test Data 2
	queue<int> obj;
	obj.Enqueue(42);
	obj.Enqueue(-3);
	obj.Enqueue(17);
	cout << "Peek is: " << obj.Peek() << endl;
	obj.Print();
	obj.Dequeue();
	cout << "Peek is: " << obj.Peek() << endl;
	obj.Print();
	obj.Dequeue();
	cout << "Peek is: " << obj.Peek() << endl;
	obj.Print();
	obj.Dequeue();
	cout << "Peek is: " << obj.Peek() << endl;
	obj.Print();

	cout << "---------------------------------" << endl;
	cout << "Now checking copy constructor" << endl;
	obj.Enqueue(-1);
	obj.Enqueue(1);
	obj.Enqueue(-2);
	obj.Enqueue(2);
	obj.Enqueue(-3);
	obj.Enqueue(3);
	queue<int> obj1 = obj;
	obj1.Print();

	cout << "-----------------------------------" << endl;
	cout << "Now checking Assignment" << endl;
	queue<int> obj3;
	obj3.Enqueue(8);
	obj3.Enqueue(9);
	obj3.Enqueue(10);
	obj3.Enqueue(11);
	obj3.Enqueue(12);
	cout << "Queue before Assignment is: " << endl;
	obj3.Print();
	cout << "Queue after Assignment is: " << endl;
	obj1.Dequeue();
	obj1.Dequeue();
	obj1.Dequeue();
	obj1.Dequeue();
	obj1.Dequeue();
	obj1.Dequeue();
	obj1.Dequeue();
	obj1.Dequeue();
	obj3 = obj1;
	obj3.Print();
}