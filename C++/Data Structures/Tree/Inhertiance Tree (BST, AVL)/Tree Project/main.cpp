
#include "tree.h"
#include "bst.h"
#include "avl.h"

int main()
{
	BST<string> obj("Salman", 0, "sorted.txt");
	obj.print(cout);
	cout << endl << endl << "Computing height of the tree" << endl;
	cout << "Height ----> " << obj.get_height() << endl;

	// finding a specific node in sorted data avl tree
	cout << "Finding Node" << endl;
	cout << obj.find("Abby") << endl;

	/*
	obj.insert(4);
	obj.insert(8);
	obj.insert(9);
	obj.insert(11);
	cout << "INORDER HERE" << endl;
	obj.print(cout);
	auto ptr = obj.find(4);
	if (ptr)
		cout << "key found" << endl;
	else if (!ptr)
		cout << "key not found" << endl;
	cout << "Checking height here" << endl;
	cout << obj.get_height() << endl;

	cout << "Removing a Node here" << endl;
	obj.remove(4);
	ptr = obj.find(4);
	if (ptr)
		cout << "key found" << endl;
	else if (!ptr)
		cout << "key not found" << endl;
	obj.print(cout);
	cout << "Height is here" << endl;
	obj.insert(4);
	cout << endl << obj.get_height();
	cout << "Now inserting more to confirm tree height" << endl;
	obj.insert(5);
	obj.insert(7);
	cout << "Checking height again after two insertions" << endl;
	cout << obj.get_height() << endl;
	cout << "Checking is_empty before deleting" << endl;
	cout << obj.is_empty() << endl;
	cout << "Checking count before deleting" << endl;
	cout << obj.count << endl;
	obj.remove(9);
	obj.remove(11);
	obj.remove(8);
	obj.remove(4);
	cout << "Checking is empty in between deleting nodes" << endl;
	cout << obj.is_empty() << endl;
	cout << "Checking count in between deleting nodes" << endl;
	cout << obj.count << endl;
	cout << "Checking height at last" << endl;
	cout << obj.get_height() << endl;
	cout << "Checking is empty function" << endl;
	cout << obj.is_empty() << endl;
	cout << "Checking count at last deleting all" << endl;
	cout << obj.count << endl;
	*/
}