


#include <iostream>
#include "bst.h"
using namespace std;



int main()
{
	bst<int> obj;
	
	obj.insertR(4);
	obj.insertR(8);
	obj.insert(9);
	obj.insert(11);
	cout << "INORDER HERE" << endl;
	obj.inorder(obj.getRoot());
	auto ptr = obj.search(49.54);
	if (ptr)
		cout << "key found" << endl;
	else if(ptr == nullptr)
		cout << "key not found" << endl;

	cout << "Removing a Node here" << endl;
	obj.inorder(obj.getRoot());

	cout << "Height is here" << endl;
	cout << endl << obj.height(obj.getRoot());
}