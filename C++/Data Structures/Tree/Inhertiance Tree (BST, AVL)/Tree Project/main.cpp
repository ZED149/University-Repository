
#include "tree.h"
#include "bst.h"

int main()
{
	BST<int> b("salman", 0);
	BST<int> a("awais", 1);

	b.insert(5);
	b.print(cout);
}