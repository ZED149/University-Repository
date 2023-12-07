


#include <iostream>
#include "minheap.h"
using namespace std;


int main()
{
	minHeap<int> obj;
	obj.Insert(11);
	obj.Insert(2);
	obj.Insert(5);
	obj.Insert(1);
	obj.ExtractMin();
	obj.ExtractMin();
	obj.ExtractMin();
	obj.ExtractMin();
	obj.ExtractMin();
	obj.Insert(11);
	obj.Insert(2);
	obj.Insert(5);
	obj.Insert(1);
	obj.ExtractMin();
	obj.ExtractMin();
	obj.ExtractMin();
	obj.ExtractMin();
	obj.ExtractMin();
}