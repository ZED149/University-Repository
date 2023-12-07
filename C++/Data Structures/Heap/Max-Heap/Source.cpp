



#include <iostream>
#include "heap.h"
using namespace std;



int main()
{
	maxHeap<int> obj;

	obj.Insert(5);
	obj.Insert(5);
	obj.Insert(7);
	obj.Insert(11);
	obj.Insert(2);
	obj.Insert(6);
	obj.Insert(3);
	obj.Insert(9);
	obj.ExtractMax();
	obj.ExtractMax();
	obj.ExtractMax();
	obj.ExtractMax();
	obj.ExtractMax();
}