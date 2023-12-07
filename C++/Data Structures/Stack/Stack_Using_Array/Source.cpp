

#include <iostream>
#include "stack.h"
using namespace std;



int main()
{
	stack<int> obj;

	obj.Push(3);
	obj.Push(3);
	obj.Push(3);
	obj.Push(3);
	obj.Push(3);
	obj.Push(3);
	cout << "Stack before pop is: " << endl;
	obj.Print();
	obj.Pop();
	obj.Pop();
	obj.Pop();
	obj.Pop();
	obj.Pop();
	obj.Pop();
	obj.Pop();
	obj.Pop();
	cout << "Stack after pop is: " << endl;
	obj.Print();
	cout << "Stack after pop push is: " << endl;
	obj.Push(11);	//1
	obj.Push(12);	//2
	obj.Push(13);	//4
	obj.Push(14);
	obj.Push(15);	//8
	obj.Push(16);
	obj.Print();
	obj.Reverse();
	obj.Print();
	obj.Push(33);
	obj.Push(43);
	obj.Push(53);
	obj.Push(63);
	obj.Print();
	obj.Reverse();
	obj.Print();
	obj.Pop();
	obj.Pop();
	obj.Pop();
	obj.Pop();
	obj.Pop();
	obj.Pop();
	obj.Pop();
	obj.Pop();
	obj.Print();
	obj.Reverse();
	obj.Print();
	obj.Pop();
	obj.Pop();
	obj.Pop();
	cout << "-----------" << endl;
	obj.Print();
	obj.Reverse();
	obj.Print();
	obj.Push(21);
	obj.Print();
	obj.Reverse();
	obj.Print();
	obj.Pop();

}