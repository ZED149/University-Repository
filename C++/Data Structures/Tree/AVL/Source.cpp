


#include <iostream>
#include "avl.h"
using namespace std;



int main()
{
	avl<int> obj;

	//Exception at this input
	//this is the extended example from your slides
	/*obj.insertR(3);
	obj.insertR(2);
	obj.insertR(1);
	obj.insertR(4);
	obj.insertR(5);
	obj.insertR(6);
	obj.insertR(7);
	obj.insertR(16);
	obj.insertR(15);
	obj.insertR(14);
	obj.remove(14);
	obj.remove(15);
	obj.remove(16);
	obj.remove(1);
	obj.remove(2);
	obj.remove(4);
	obj.remove(5);
	obj.remove(6);
	obj.remove(7);
	obj.remove(3);*/
	

	
	//this is also another example from the same slides
	//this works fine
	/*obj.insertR(14);
	obj.insertR(17);
	obj.insertR(11);
	obj.insertR(7);
	obj.insertR(53);
	obj.insertR(4);
	obj.insertR(13);
	obj.insertR(12);
	obj.insertR(8);
	obj.remove(8);
	obj.remove(53);
	obj.remove(4);
	obj.remove(14);
	obj.remove(13);
	obj.remove(17);
	obj.remove(7);
	obj.remove(12);
	obj.remove(11);*/




	//Example 3
	/*obj.insertR(10);
	obj.insertR(20);
	obj.insertR(30);
	obj.insertR(25);
	obj.insertR(28);
	obj.insertR(27);
	obj.insertR(5);
	obj.remove(5);
	obj.remove(27);
	obj.remove(28);
	obj.remove(25);
	obj.remove(30);
	obj.remove(20);
	obj.remove(10);*/



	/*
	//Example 4 ultra pro max
	obj.insertR(1);
	obj.insertR(2);
	obj.insertR(3);
	obj.insertR(4);
	obj.insertR(5);
	obj.insertR(6);
	obj.insertR(7);
	obj.insertR(8);
	obj.insertR(9);
	obj.remove(4);
	*/
	

	/*obj.insertR('A');
	obj.insertR('b');
	obj.insertR('C');
	obj.insertR('d');
	obj.insertR('E');
	obj.insertR('f');
	obj.insertR('G');
	obj.insertR('h');
	obj.remove('A');
	obj.remove('b');
	obj.remove('C');
	obj.remove('d');
	obj.remove('E');
	obj.remove('f');
	obj.remove('G');
	obj.remove('h');*/
	
	cout << "INORDER HERE" << endl;
	obj.inorder(obj.getRoot());

	cout << "-------- height ------------" << endl;
	cout << obj.height(obj.getRoot()) << endl;

}