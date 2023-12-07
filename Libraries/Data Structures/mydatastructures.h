

#pragma once

// My Data Structures
// mydatastructures.h


#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

namespace zed
{
	// This is an Abstract Data Type(ADT) class
	template <typename T>
	class array_ADT
	{
		//we need 3 variables
		/*
		1. Size => Logical Size (Current size of the array)
		2. Capacity => Physical Size (Total size of the array)
		3. T pointer for any type of data
		*/
		T* arr;
		int size, capacity;

	public:

		//Constructor
		//Default Constructor
		array_ADT(int capacity)
		{
			//cout << "array_ADT() called" << endl;
			this->size = 0;
			this->capacity = capacity;
			this->arr = new T[capacity];
		}

		//Copy Constructor
		array_ADT(const array_ADT& obj)
		{
			this->size = obj.size;
			this->capacity = obj.capacity;
			this->arr = new T[obj.size];
			for (int i = 0; i < obj.size; i++)
				this->arr[i] = obj.arr[i];

			return *this;
		}

		//Member Functions
		//Print
		void print()
		{
			cout << "print() called" << endl;
			if (size <= capacity)
			{
				for (int i = 0; i < size; i++)
					cout << this->arr[i] << " ";
			}
		}


		//Insert
		void insert(const T& value)
		{
			if (this->size < this->capacity)
			{
				this->arr[size++] = value;
			}
		}


		//Delete
		void Delete(const int index)
		{
			//Delete function will take index as a parameter
			//at which the value needs to be deleted
			if (index < size)
			{
				size--;
				for (int i = index; i < size; i++)
					arr[i] = arr[i + 1];
			}
		}

		//Search
		int search(const T& key)
		{
			static int temp = 0;
			for (int i = 0; i < size; i++)
			{
				if (arr[temp] == key)
					return temp;
				if (arr[i] == key)
				{
					temp = i;
					return i;
				}
			}
			return -1;
		}


		//Binary Search
		int binarySearch(const T& key)
		{
			int low, high, mid = 0;
			low = 0;
			high = this->size - 1;

			while (low <= high)
			{
				mid = (low + high) / 2;
				if (key == arr[mid])
					return mid;
				else if (key < arr[mid])
					high = mid - 1;
				else
					low = mid + 1;
			}

			return -1;
		}


		//Binary Search Recursive Version
		int RBinarySearch(const T& key)
		{
			//This is the wrapper function for recursive binary search
			return RBinarySearch(0, this->size - 1, key);
		}

		int RBinarySearch(int low, int high, const T& key)
		{
			if (low <= high)
			{
				int mid = (low + high) / 2;
				if (key == arr[mid])
					return mid;
				else if (key < arr[mid])
					return RBinarySearch(low, mid - 1, key);
				else
					return RBinarySearch(mid + 1, high, key);
			}
			return -1;
		}


		//Sum Recursive Version
		//Return the sum of total size if 'i' is not specified
		//else return the value from 'i' to size
		int Sum(int i = 0)
		{
			//This is the wrapper fucntion for sum
			if (i >= 0 && i < size)
			{
				return Sum(0, i);
			}
			return 0;
		}

		int Sum(T total, int i)
		{
			if (i < size)
			{
				return total = Sum(total + arr[i], i + 1);;
			}
			return total;
		}


		//Get
		//Return the value at a specified index
		T Get(int index)
		{
			if (index >= 0 && index < size)
				return arr[index];
			return -1;
		}


		//Set
		//Sets the value at a specified index
		void Set(int index, const T& value)
		{
			if (index >= 0 && index < size)
				arr[index] = value;
		}

		//Max
		//Return the maximum of an array
		T Max()
		{
			T max = arr[0];
			for (int i = 1; i < size; i++)
				if (arr[i] > max)
					max = arr[i];
			return max;
		}


		//Min
		//Return the minimum of an array
		T Min()
		{
			T min = arr[0];
			for (int i = 1; i < size; i++)
				if (arr[i] < min)
					min = arr[i];
			return min;
		}


		//Average
		//Return the average of an array
		T Avg()
		{
			T sum = this->Sum(0, 0);
			return (sum / size);
		}


		//Reverse
		//Reverses an array
		void Reverse()
		{
			int i = 0, j = this->size - 1;
			while (i < j)
			{
				swap(arr[i], arr[j]);
				i++;
				j--;
			}
		}


		//Rotations
		//Left Rotation
		void LeftRotation(const int& times)
		{
			for (int i = 0; i < times; i++)
			{
				T temp = arr[0];
				for (int j = 0; j < this->size; j++)
				{
					arr[j] = arr[j + 1];
					if (j == size - 1)
						arr[j] = temp;
				}
			}
		}


		//Right Rotation
		void RightRotation(const int& times)
		{
			for (int i = 0; i < times; i++)
			{
				T temp = arr[size - 1];
				for (int j = size - 1; j >= 0; j--)
				{
					arr[j] = arr[j - 1];
					if (j == 0)
						arr[j] = temp;
				}
			}
		}


		//Shifting
		//Left Shift
		void LeftShift(const int& times)
		{
			for (int i = 0; i < times; i++)
				for (int j = 0; j < this->size; j++)
				{
					arr[j] = arr[j + 1];
					if (j == size - 1)
						arr[j] = NULL;
				}
		}


		//Right Shift
		void RightShift(const int& times)
		{
			for (int i = 0; i < times; i++)
			{
				for (int j = size - 1; j >= 0; j--)
				{
					arr[j] = arr[j - 1];
					if (j == 0)
						arr[j] = NULL;
				}
			}
		}


		//Sorting
		//Sorts the array from the specified index
		//If index isn't specidifed, sorts from 0
		void Sort(const int& index = 0)
		{
			for (int i = index; i < size; i++)
				for (int j = i + 1; j < size; j++)
					if (arr[i] > arr[j])
						swap(arr[i], arr[j]);
		}


		//Is Sorted
		//Return true if the array is sorted
		//else returns false
		bool IsSorted()
		{
			for (int i = 0; i < size; i++)
			{
				if (i == size - 1)
					return true;
				if (arr[i] > arr[i + 1])
					return false;
			}
			return true;
		}


		//Merging
		//Merges two arrays also sorts them if the flag is true
		static array_ADT Merg(const array_ADT& obj1, const array_ADT& obj2, bool flag = false)
		{
			//We need a 3rd array to merge these two arrays
			array_ADT obj3((obj1.capacity + obj2.capacity));

			//Copying from 1st array
			for (int i = 0; i < obj1.size; i++)
				obj3.insert(obj1.arr[i]);

			for (int i = 0; i < obj2.size; i++)
				obj3.insert(obj2.arr[i]);


			if (flag == true)
				obj3.Sort();

			return obj3;
		}

		//Destructor
		~array_ADT()
		{
			//cout << "~array_ADT() called" << endl;
			delete[] this->arr;
			this->size = this->capacity = 0;
		}
	};

	// This is a Min-Heap Class
	template <typename T>
	class minHeap
	{
		// Utlitity Functions
		// Heapify
		void heapify(int i)
		{
			int imax = i;
			if (2 * i <= heap_array.size() - 1 && heap_array[2 * i] < heap_array[i])
			{
				imax = (2 * i);
			}
			if ((2 * i) + 1 <= heap_array.size() - 1 && heap_array[(2 * i) + 1] < heap_array[imax])
			{
				imax = (2 * i) + 1;
			}

			if (imax != i)
			{
				swap(heap_array[i], heap_array[imax]);
				heapify(imax);
			}
		}


		// Private Data Members
		vector<T> heap_array;	// Heap Array which is physically stored as an Vector[array] but is logically implemented as a Binary Tree



	public:	// This is where the member goes
		minHeap()
		{
			cout << "heap() called" << endl;
			heap_array.push_back(NULL);
		}


		// Insert
		void Insert(const T key)
		{
			// First I need to push key into the heap_array
			heap_array.push_back(key);

			// Now I need to check whether my heap_array is still a max-heap or not
			// if it is not then make it a max-heap
			int i = heap_array.size() - 1;
			while (i != 1 && heap_array[i] < heap_array[i / 2])
			{
				swap(heap_array[i], heap_array[i / 2]);
				i /= 2;
			}
		}


		// Extract Max
		void ExtractMin()
		{
			if (heap_array.size() > 1)
			{
				T temp = heap_array[heap_array.size() - 1];
				heap_array[1] = temp;	// always root
				heap_array.pop_back();
				heapify(1);
			}
		}

	};

	// This is a Max-Heap Class
	template <typename T>
	class maxHeap
	{
		// Utlitity Functions
		// Heapify
		void heapify(int i)
		{
			int imax = i;
			if (2 * i <= heap_array.size() - 1 && heap_array[2 * i] > heap_array[i])
			{
				imax = (2 * i);
			}
			if ((2 * i) + 1 <= heap_array.size() - 1 && heap_array[(2 * i) + 1] > heap_array[imax])
			{
				imax = (2 * i) + 1;
			}

			if (imax != i)
			{
				swap(heap_array[i], heap_array[imax]);
				heapify(imax);
			}
		}


		// Private Data Members
		vector<T> heap_array;	// Heap Array which is physically stored as an Vector[array] but is logically implemented as a Binary Tree



	public:	// This is where the member goes
		maxHeap()
		{
			cout << "heap() called" << endl;
			heap_array.push_back(NULL);
		}


		// Insert
		void Insert(const T key)
		{
			// First I need to push key into the heap_array
			heap_array.push_back(key);

			// Now I need to check whether my heap_array is still a max-heap or not
			// if it is not then make it a max-heap
			int i = heap_array.size() - 1;
			while (i != 1 && heap_array[i] > heap_array[i / 2])
			{
				swap(heap_array[i], heap_array[i / 2]);
				i /= 2;
			}
		}


		// Extract Max
		void ExtractMax()
		{
			if (heap_array.size() > 1)
			{
				T temp = heap_array[heap_array.size() - 1];
				heap_array[1] = temp;	// always root
				heap_array.pop_back();
				heapify(1);
			}
		}

	};

	//This is a Doubly Linked List Class
	template <typename T>
	class dlist
	{
		//private data members

		//Node Class
		typedef struct node
		{
			node* next;
			node* prev;
			T data;
		}*nodePtr;


		nodePtr head, tail;
		int size;

		//Insertion Operator
		/*friend ostream& operator << (ostream& out, T& obj);*/


		//public data members
	public:

		//Default Constructor
		dlist()
		{
			head = new node;
			tail = new node;
			head->prev = tail->next = nullptr;
			head->next = tail;
			tail->prev = head;
			size = 1;
		}


		//Copy Constructor
		dlist(dlist& obj)
		{
			iterator itr1, itr2;
			//itr1 = this->begin();

			head = new node;
			tail = new node;
			head->next = tail;
			tail->prev = head;
			head->prev = tail->next = nullptr;
			itr2 = obj.begin();
			for (; itr2 != obj.end(); ++itr2)
			{
				insertAtEnd(*(itr2));
			}

		}


		//Iterator Class
		class iterator
		{
			nodePtr curr;


		public:	//public functions of iterator class

			friend class dlist;

			//Default and Overloaded Constructor
			iterator(nodePtr obj = nullptr)
			{
				this->curr = obj;
			}

			//Copy Constructor
			iterator(const iterator& obj)
			{
				this->curr = obj.curr;
			}

			//Operator Overlaoding

			//Pre-Increment Operator
			iterator& operator++()
			{
				this->curr = curr->next;
				return *this;
			}

			//Post-Increment Operator
			iterator& operator++(int data)
			{
				iterator a(this->curr);
				this->curr = curr->next;
				return a;
			}

			//Pre-Decrement Operator
			iterator& operator--()
			{
				this->curr = curr->prev;
				return *this;
			}

			//Post-Decrement
			iterator& operator--(int data)
			{
				iterator a(this->curr);
				this->curr = curr->prev;
				return a;
			}

			//Dereference Operator
			T& operator*()
			{
				return curr->data;
			}


			//Not-Equal Operator
			bool operator!=(const iterator& obj)
			{
				return this->curr != obj.curr ? true : false;
			}



			//Equal Operator
			bool operator==(const iterator& rhs)const
			{
				if (this->curr == rhs.curr)
					return true;
				else return false;
			}

		};


		//Insert
		iterator insert(iterator it, T data)
		{
			//node variable to point to it.curr;
			nodePtr p = it.curr;
			//New Node
			nodePtr t = new node;
			t->data = data;
			t->next = p;
			t->prev = p->prev;
			p->prev->next = t;
			p->prev = t;
			iterator ret(t);
			size++;
			//cout << *(ret);
			return ret;
		}
		iterator insert(iterator it, T&& data)
		{
			//node variable to point to it.curr;
			nodePtr p = it.curr;
			//New Node
			nodePtr t = new node;
			t->data = data;
			t->next = p;
			t->prev = p->prev;
			p->prev->next = t;
			p->prev = t;
			iterator ret(t);
			size++;
			//cout << *(ret);
			return ret;
		}

		//insert at head
		void insertAtHead(T data)
		{
			iterator itr(head->next);
			insert(itr, data);
		}


		//insert at end
		void insertAtEnd(T data)
		{
			iterator itr(tail);
			insert(itr, data);
		}



		//Delete
		iterator Delete(iterator it)
		{
			size--;
			nodePtr p = it.curr;
			iterator ret(p->next);
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
			return ret;
		}

		//delete at start
		void deleteAtStart()
		{
			if (head->next != tail)
			{
				iterator itr(head->next);
				Delete(itr);
			}
		}


		//delete at end
		void deleteAtEnd()
		{
			if (head->next != tail)
			{
				iterator itr(tail);
				itr--;
				Delete(itr);
			}
		}

		//Begin
		iterator begin()
		{
			iterator temp(head->next);
			return temp;
		}


		//End
		iterator end()
		{
			iterator temp(tail);
			return temp;
		}


		//Print
		void print()
		{
			iterator itr;
			for (itr = begin(); itr != end(); itr++)
			{
				cout << *(itr) << endl;
			}
		}


		//is empty
		bool isEmpty()
		{
			iterator itr1, itr2;
			itr1 = begin();
			itr2 = end();

			return itr1 == itr2 ? true : false;
		}


		//Get Size
		int getSize()
		{
			return (size - 1);
		}

		//remove duplicate
		void removeDuplicate()
		{
			iterator itr1, itr2, itr3;
			iterator nullOper = end();
			for (itr1 = begin(); itr1 != end(); itr1++)
			{
				itr3 = itr1;
				for (itr2 = ++itr3; itr2 != end(); itr2++)
				{
					if (*(itr1) == *(itr2))
						itr2 = Delete(itr2);
					if (*(itr2) == *(nullOper))
						break;
				}
			}
		}





		//insert before
		void insertBefore(const T v1, const T v2)
		{
			iterator itr, itr2;
			for (itr = begin(); itr != end(); itr++)
			{
				if (*(itr) == v2)
				{
					itr2 = itr;
					itr2 = insert(itr2, v1);
				}
			}
		}


		//Search
		bool search(T& key)
		{
			iterator itr1;
			itr1 = begin();
			for (; itr1 != end(); itr1++)
			{
				if (*(itr1) == key)
					return true;
			}
			return false;
		}


		//Get Index
		iterator& getIndex(T key)
		{
			iterator itr1, itr2;
			itr1 = begin();
			for (itr1; itr1 != end(); itr1++)
			{
				if (*(itr1) == key)
				{
					itr2 = itr1;
					return itr2;
				}
			}
		}


		//Get Index Of Node
		T& getIndexOfNode(T& node)
		{
			iterator itr1;
			itr1 = begin();
			for (; itr1 != end(); itr1++)
			{
				if (*(itr1) == node)
				{
					return *(itr1);
				}
			}
			return *(itr1);
		}


		//Get Index Of Node (Overloaded Version)
		T& getIndexOfNode(T& node, iterator& itr)
		{
			iterator itr1;
			itr1 = itr;
			for (; itr1 != end(); itr1++)
			{
				if (*(itr1) == node)
				{
					return *(itr1);
				}
			}
			return *(itr1);
		}


		//Operator Overloading
		//Assignment Operator
		dlist& operator = (dlist& obj)
		{
			iterator itr1, itr2;
			itr1 = this->begin();
			itr2 = obj.begin();


			//Check if there is any memeory allocated
			//as we are calling assigment operator
			//to prevent memory leak




			for (; itr2 != obj.end(); ++itr2)
			{
				insertAtEnd(*(itr2));
			}
			return *this;
		}


		//Insertion Operator
		friend ostream& operator << (ostream& out, dlist& obj)
		{
			iterator itr;
			for (itr = obj.begin(); itr != obj.end(); itr++)
			{
				out << *(itr) << endl;
			}
			return out;
		}//insertion operator




		//reverse
		void reverse()
		{
			//
		}




		//Destructor
		~dlist()
		{
			cout << "~dlist() called" << endl;
			while (head->next != tail)
				deleteAtStart();
			delete head;
			delete tail;
		}
	};

	// This is also another Doubly Linked List Class
	template <typename T>
	class doubly_linked_list
	{
		//Definition on Node Structure
		typedef struct node
		{
			T data;	//Data of any type
			node* next;
			node* prev;

			//Constructor
			node(T value, node* next, node* prev) :
				data(value), next(next), prev(prev) {}
		}*nodePtr;

		nodePtr head, tail;	//Head and Tail pointers

	public:	//This is where the member goes
		//Constructor
		//Default Constructor
		doubly_linked_list()
		{
			//cout << "doubky_linked_list() called" << endl;
			head = tail = nullptr;
		}

		//Copy Constructor
		doubly_linked_list(const doubly_linked_list<T>& obj)
		{
			//cout << "doubly_linked_list copy() called" << endl;
			this->head = tail = nullptr;
			nodePtr curr = obj.head;
			while (curr != nullptr)
			{
				this->insertAtEnd(curr->data);
				curr = curr->next;
			}
		}


		//Insert
		//Insert At Start
		void insertAtStart(const T& value)
		{
			//cout << "insertAtHead() called" << endl;
			if (head == nullptr)
			{
				//List is empty
				head = tail = new node(value, tail, head);
			}
			else
			{
				//List has some data
				nodePtr curr = head;
				head = new node(value, head, nullptr);
				curr->prev = head;
			}
		}


		//Insert At End
		void insertAtEnd(const T& value)
		{
			//cout << "insertAtEnd() called" << endl;
			if (head == nullptr)
			{
				//List is empty
				head = tail = new node(value, tail, head);
			}
			else
			{
				//List is not empty
				nodePtr curr = tail;
				tail = new node(value, nullptr, tail);
				curr->next = tail;
			}
		}


		//Delete
		//Delete From Start
		void deleteFromStart()
		{
			if (head != nullptr)
			{
				//Delete only if list is not empty
				nodePtr curr = head;
				head = head->next;
				if (head == nullptr)
					head = tail = nullptr;
				else
					head->prev = nullptr;
				delete curr;
			}
		}

		//Delete From End
		void deleteFromEnd()
		{
			if (head != nullptr)
			{
				//Delete only if list is not empty
				nodePtr curr = tail;
				tail = tail->prev;
				if (tail == nullptr)
					head = tail = nullptr;
				else
					tail->next = nullptr;
				delete curr;
			}
		}


		//Operator Overloading
		//Insertion Operator
		friend ostream& operator << (ostream& out, const doubly_linked_list<T> obj)
		{
			nodePtr curr = obj.head;
			while (curr != nullptr)
			{
				out << curr->data << ", ";
				curr = curr->next;
			}
			out << endl;
			return out;
		}


		//Print
		void Print()
		{
			//cout << "Print() called" << endl;
			nodePtr curr = head;
			while (curr != nullptr)
			{
				cout << curr->data << ", ";
				curr = curr->next;
			}
			cout << endl;
		}


		//Insert Before
		bool insertBefore(const T& v1, const T& v2)
		{
			//cout << "insertBefore() called" << endl;
			if (head == nullptr)
				return 0;
			else
			{
				nodePtr curr = head;
				while (curr != nullptr)
				{
					if (curr->data == v2)
					{
						//Writing custom code for inserting as not using iterators
						nodePtr temp = new node(v1, curr, curr->prev);
						curr->prev->next = temp;
						curr->prev = temp;
						return 1;
					}
					curr = curr->next;
				}
				return 0;
			}
		}


		//Reverse
		void reverse()
		{
			//cout << "reverse() called" << endl;
			nodePtr prev = nullptr, curr = head, next = nullptr;
			while (curr != nullptr)
			{
				next = curr->next;
				curr->next = prev;
				curr->prev = next;
				prev = curr;
				curr = next;
			}
			head = prev;
		}


		//Destructor
		~doubly_linked_list()
		{
			//cout << "~doubly_linked_list() called" << endl;
			while (head != nullptr)
				deleteFromStart();
		}
	};

	//This is a Singly Linked List Class
	//It is implemented by NOT using a dummy node
	template <typename T>
	class slist
	{
		//Private Data members
		//Creating Node Structure
		typedef struct node
		{
			T data;
			node* next;

			//Assiging Data thorugh Constructor
			node(const T& data, node* nextPtr = nullptr)
			{
				this->data = data;
				this->next = nextPtr;
			}

			node()
			{
				this->next = next;
			}
		}*nodePtr;

		//Other Private data members
		nodePtr head, tail;
		int size;


	public:	//This is where the member goes
		//Constructors

		//Default Constructor
		slist()
		{
			this->head = tail = nullptr;
			size = 0;
		};

		//Copy Constructor
		slist(const slist<T>& obj)
		{
			stack<nodePtr> list_nodes;
			this->head = tail = nullptr;

			nodePtr curr = obj.head;
			while (curr != nullptr)
			{
				list_nodes.push(curr);
				curr = curr->next;
			}

			while (!list_nodes.empty())
			{
				this->insertAtHead(list_nodes.top()->data);
				list_nodes.pop();
			}
			this->size = obj.size;

		};

		//INSERT
		//Insert at head
		void insertAtHead(const T& obj)
		{
			if (head == nullptr)
			{
				//List is empty
				//creating new node
				nodePtr temp = new node(obj);
				head = tail = temp;
				size++;
			}
			else
			{
				//List has some data
				//creating new node
				nodePtr temp = new node(obj, head);
				head = temp;
				size++;
			}
		}


		//Insert At Tail
		void insertAtTail(const T& obj)
		{
			if (head == nullptr)
			{
				//List is empty
				head = tail = new node(obj);
			}
			else
			{
				//List has some data
				tail->next = new node(obj);
				tail = tail->next;
			}
			size++;
		}


		//DELETE
		//Delete At Head
		void removeAtHead()
		{
			if (head != nullptr)
			{
				//Call only if list is not empty
				nodePtr temp = head;
				head = head->next;
				delete temp;

				if (head == nullptr)	//if there is only 1 item which is now deleted
					tail = nullptr;

				size--;
			}
		}


		//Delete At Tail
		void removeAtTail()
		{
			if (head == tail)
			{
				//If list has only 1 item
				delete head;
				head = tail = nullptr;
			}
			else if (head != nullptr)
			{
				//Call only if list is not empty
				nodePtr curr = head;
				while (curr->next != tail)
					curr = curr->next;

				tail = curr;
				curr = curr->next;
				delete curr;
				tail->next = nullptr;
			}
			size--;
		}


		//Remove At Key
		void removeAtKey(const T& key)
		{
			if (head != nullptr)
			{
				if (head->data == key)
					removeAtHead();
				else if (tail->data == key)
					removeAtTail();
				else
				{
					nodePtr prev = head, curr = head;

					while (curr != nullptr && curr->data != key)
					{
						prev = curr;
						curr = curr->next;
					}

					//current will be NULL if it has traveresed whole list
					//and didn't find the key
					if (curr != nullptr)
					{
						//If valid data is found
						prev->next = curr->next;
						if (curr == tail)
							tail = prev;
						delete curr;
						size--;
					}
				}
			}
		}


		//Is Empty
		inline bool isEmpty()
		{
			return size == 0 ? 1 : 0;
		}


		//Reverse
		void reverse()
		{
			nodePtr prev = nullptr, curr = head, next = nullptr;

			while (curr != nullptr)
			{
				next = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next;
			}

			head = prev;
		}


		//Print
		void Print()
		{
			//cout << "Print() called" << endl;
			if (head != nullptr)
			{
				nodePtr curr = head;
				while (curr != nullptr)
				{
					cout << curr->data << " -> ";
					curr = curr->next;
				}
				cout << endl;
			}
		}
	};

	// This is a Queue Class
	template<typename T>
	class queue
	{
		//Data Members for Queue
		int size, capacity;
		int front, rear;
		T* arr;

		//Utility Function
		//Next
		int next(const int i)
		{
			return ((i + 1) % capacity);
		}

	public:	//This is where the member goes
		//Constructor
		//Constructor with Default Parameter
		queue(int size = 0)
		{
			cout << "queue() called" << endl;
			if (size > 0)
			{
				this->front = this->rear = this->size = 0;
				this->capacity = size + 1;
				this->arr = new T[capacity + 1];
			}
			else
			{
				this->front = this->rear = this->size = 0;
				this->capacity = 0;
				this->arr = nullptr;
			}
		}

		//Copy Constructor
		queue(const queue<T>& obj)
		{
			cout << "queue copy() called" << endl;
			//Copying Static Data
			this->capacity = obj.capacity;
			this->size = obj.size;
			this->front = obj.front;
			this->rear = obj.rear;

			//Copying Dynamic Data
			//First initializing array
			this->arr = new T[obj.capacity];
			//Now copying values
			for (int i = next(obj.front); i <= obj.size; i = next(i))
			{
				this->arr[i] = obj.arr[i];
				//i = next(i);
			}
		}


		//Operator Overloading
		//Assignment Operator
		queue<T> operator = (const queue<T>& obj)
		{
			//Checking if the caller member already has some allocated data
			if (this->arr)
				delete[] this->arr;

			cout << "assignment() called" << endl;
			//Copying Static Data
			this->capacity = obj.capacity;
			this->size = obj.size;
			this->front = obj.front;
			this->rear = obj.rear;

			//Copying Dynamic Data
			//First initializing array
			this->arr = new T[obj.capacity];
			//Now copying values
			for (int i = next(obj.front); i <= obj.size; i = next(i))
			{
				this->arr[i] = obj.arr[i];
				//i = next(i);
			}

			return *this;
		}

		//Member Functions
		void Enqueue(const T& obj)
		{
			cout << "Enqueue() called" << endl;
			if (size + 1 < capacity)
			{
				//We have space
				rear = next(rear);
				this->arr[rear] = obj;
				size++;
			}
			else if (this->capacity == 0)
			{
				//User didn't specified any size
				this->capacity = 2;
				this->arr = new T[2];	//'0' for dead cell, '1' for item
				arr[1] = obj;
				size = 1;
				front = 0;
				rear = 1;
			}
			else
			{
				//Array needs to grow
				T* temp = new T[capacity * 2];
				//Copying values
				int k = 1, i = next(front); //'k' is loop iterator, 'i' is arr index
				while (k <= size)
				{
					temp[k++] = arr[i];
					i = next(i);
				}
				//reseting front and rear
				front = 0;
				this->capacity *= 2;
				rear = next(size);
				//adding data
				temp[rear] = obj;
				size++;

				delete[] this->arr;
				this->arr = temp;
			}
		}


		//Dequeue
		void Dequeue()
		{

			if (this->Empty())	//return if queue is empty
				return;

			cout << "Dequeue() called" << endl;
			if (size + 1 >= capacity / 2)
			{
				//If size is greater than half of the capacity
				size--;
				front = next(front);
			}
			else
			{
				//Array needs to shrink
				//Creating array half of the size of original array
				T* temp = new T[capacity / 2];
				if (size == 2)
					front++;
				int k = 1, i = next(front);
				//Copying values
				while (k <= size)
				{
					temp[k] = arr[i];
					k++;
					i = next(i);
				}
				//Deleting item
				capacity /= 2;
				front = 0;
				rear = size - 1;
				size--;
				delete[] arr;
				arr = temp;
				if (size == 0)
				{
					if (capacity != 0)	//Check for memory leak before assigning capacity to '0'
						delete[] this->arr;
					this->capacity = 0;
				}
			}
		}


		//Peek
		const T& Peek()
		{
			if (this->Empty())
				return NULL;
			return this->arr[next(front)];
		}


		//Empty
		bool Empty()
		{
			return size == 0 ? 1 : 0;
		}


		//Print
		void Print()
		{
			if (this->Empty())
				return;
			cout << "Print() called" << endl;
			int i = next(front), k = 0;
			while (k++ < size)
			{
				cout << arr[i] << " ";
				i = next(i);
				//k++;
			}
			cout << endl;
		}


		//Destructor
		~queue()
		{
			cout << "~queue() called" << endl;
			delete[]  this->arr;
		}

	};

	// This is a Sparse Matrix Class
	// NOTE: This works for integers only
	class sparse_matrix
	{
		//Node Class
		typedef struct node
		{
			int value;
			int colIndex;
			node* nextInRow;
			int size;
			//Constructor
			node(int value, int colIndex, node* nextPtr) :
				value(value), colIndex(colIndex), nextInRow(nextPtr) {
				size = 0;
			}
		}*nodePtr;

		//Utility Functions
		//Add Node
		void addNode(nodePtr& head, const int& value, int colIndex, int i)
		{
			this->rowList[i]->size++;
			nodePtr curr = head;
			while (curr->nextInRow != nullptr) { curr = curr->nextInRow; }
			nodePtr temp = new node(value, colIndex, nullptr);
			curr->nextInRow = temp;
		}

		//Add Node by pointer
		void addNode(nodePtr& head, const nodePtr& curr, int i)
		{
			this->rowList[i]->size++;
			nodePtr iter = head;
			while (iter->nextInRow != nullptr) { iter = iter->nextInRow; }
			nodePtr temp = new node(curr->value, curr->colIndex, nullptr);
			iter->nextInRow = temp;
		}

		//Add Node by Rows and Cols
		void addNode(const int row, const int col, const int& value, sparse_matrix& obj)
		{
			this->rowList[row]->size++;
			nodePtr curr = obj.rowList[row];
			while (curr->nextInRow != nullptr) { curr = curr->nextInRow; }
			nodePtr temp = new node(value, col, nullptr);
			curr->nextInRow = temp;
		}


		//Add Node only for Read Function
		void addNode(const int value, const int col, nodePtr& curr, int i)
		{
			//This function is specially overloaded for read function
			//Its because by using this we don't have to always go at end 
			//to insert data. We can do it just by passing non zero entries
			//and appending it to each other as data 
			this->rowList[i]->size++;
			if (this->rowList[i]->nextInRow == nullptr)
			{
				//If row has no value
				curr = this->rowList[i];
			}
			curr->nextInRow = new node(value, col, nullptr);
			curr = curr->nextInRow;
		}


		//Delete Node
		void delNode(nodePtr& curr)
		{
			nodePtr temp = curr;
			curr = curr->nextInRow;
			delete temp;
		}

		//Private Data Members of class Sparse Matrix
		int M, N;	//Dimensions
		vector<nodePtr> rowList;


	public:	//This is where the member goes
		//Constructor
		//Constructor with Default Parameters
		sparse_matrix(int M = 0, int N = 0)
		{
			this->M = M;
			this->N = N;
		}

		//Constructor with Parameters
		//Reads data from a given file
		sparse_matrix(string filename)
		{
			//Simply uses read to read from a file
			this->read(filename);
		}

		//Copy Constructor
		sparse_matrix(const sparse_matrix& obj)
		{
			this->M = obj.M;
			this->N = obj.N;


			//This loop will read from obj and copies to this
			nodePtr curr = nullptr;
			for (int i = 0; i < obj.rowList.size(); i++)
			{
				this->rowList.push_back(new node(-1, 0, nullptr));	//Head of row list
				curr = obj.rowList[i]->nextInRow;
				while (curr != nullptr)
				{
					this->addNode(rowList[i], curr, i);
					curr = curr->nextInRow;
				}
			}
		}


		//Operator Overloading
		//ASsignment Operator
		const sparse_matrix& operator = (const sparse_matrix& obj)
		{
			//Condition to check if the caller function already has smoe allocated memory
			if (!this->rowList.empty())
			{
				nodePtr curr = nullptr;
				for (int i = 0; i < this->rowList.size(); i++)
				{
					curr = rowList[i];
					while (curr != nullptr)
						delNode(curr);
				}
				this->rowList.clear();
			}

			this->M = obj.M;
			this->N = obj.N;


			//This loop will read from obj and copies to this
			nodePtr curr = nullptr;
			for (int i = 0; i < obj.rowList.size(); i++)
			{
				this->rowList.push_back(new node(-1, 0, nullptr));	//Head of row list
				curr = obj.rowList[i]->nextInRow;
				while (curr != nullptr)
				{
					this->addNode(rowList[i], curr, i);
					curr = curr->nextInRow;
				}
			}

			return *this;
		}


		//Equal Operator
		bool operator == (const sparse_matrix& obj) const
		{
			//First we need to check for dimensions
			if (this->M == obj.M && this->N == obj.N)
			{
				//Rows and Columns are same
				//Now check for values at same position
				nodePtr curr1 = nullptr, curr2 = nullptr;
				for (int i = 0; i < rowList.size(); i++)
				{
					curr1 = this->rowList[i]->nextInRow;
					curr2 = obj.rowList[i]->nextInRow;

					if (curr1 == nullptr && curr2 != nullptr)
						return 0;
					else if (curr2 == nullptr && curr1 != nullptr)
						return 0;

					while (curr1 != nullptr && curr2 != nullptr)
					{
						if ((curr1->value != curr2->value) || (curr1->colIndex != curr2->colIndex))
							return 0;
						curr1 = curr1->nextInRow;
						curr2 = curr2->nextInRow;
					}

					if (curr1 == nullptr && curr2 != nullptr)
						return 0;
					else if (curr2 == nullptr && curr1 != nullptr)
						return 0;
				}
				return 1;
			}
			else
				return 0;
		}


		//Addition Opeartor
		sparse_matrix operator + (const sparse_matrix& obj)
		{
			//First create a temp matrix
			sparse_matrix temp;
			//Now 3 pointers to iterate
			//tcurr ==> temp
			//curr1 ==> this
			//curr2 ==> obj

			nodePtr tcurr = nullptr, curr1 = nullptr, curr2 = nullptr;
			int counter[6] = { 0 };
			for (int i = 0; i < rowList.size(); i++)
			{
				//First add a new node to temp
				temp.rowList.push_back(new node(-1, 0, nullptr));
				//Now point pointers
				tcurr = temp.rowList[i];
				curr1 = rowList[i];
				curr2 = obj.rowList[i];
				for (int j = 0; j < 6; j++)
					counter[j] = 0;

				if ((curr1->value == -1 && curr1->nextInRow == nullptr) && (curr2->value == -1 && curr2->nextInRow == nullptr))
				{
					//Both rows are NULL
					continue;
				}
				else if (curr1->value == -1 && curr1->nextInRow == nullptr)
				{
					if (counter[3] == 0)
					{
						counter[3] = 1;
						curr2 = curr2->nextInRow;
					}
					//Caller row is NULL
					while (curr2 != nullptr)
					{
						this->addNode(tcurr, curr2, i);
						curr2 = curr2->nextInRow;
					}
				}
				else if (curr2->value == -1 && curr2->nextInRow == nullptr)
				{
					if (counter[4] == 0)
					{
						counter[4] = 1;
						curr1 = curr1->nextInRow;
					}
					//Obj row is NULL
					while (curr1 != nullptr)
					{
						this->addNode(tcurr, curr1, i);
						curr1 = curr1->nextInRow;
					}
				}
				else if (curr1 and curr2)
				{
					//Both rows have data
					int j = curr1->size - 1, k = curr2->size - 1;
					if (curr1->size < curr2->size)
					{
						//If caller list is smaller and obj list is larger
						if (counter[0] == 0)
						{
							counter[0] = 1;
							curr1 = curr1->nextInRow;
							curr2 = curr2->nextInRow;
						}
						//Caller list is smaller
						if (curr1->colIndex == curr2->colIndex)
						{
							while (true)
							{
								if (j >= 0)
								{
									this->addNode(tcurr, (curr1->value + curr2->value), curr1->colIndex, i);
									tcurr = tcurr->nextInRow;
									curr1 = curr1->nextInRow;
									curr2 = curr2->nextInRow;
									j--;
									k--;
								}
								else if (k >= 0)
								{
									this->addNode(tcurr, (curr2->value), curr2->colIndex, i);
									tcurr = tcurr->nextInRow;
									curr2 = curr2->nextInRow;
									k--;
								}
								if (j == -1 and k == -1)
									break;
							}
						}
						else if (curr1->colIndex > curr2->colIndex)
						{
							int l = k - j;
							while (true)
							{
								if (l > 0)
								{
									this->addNode(tcurr, (curr2->value), curr2->colIndex, i);
									tcurr = tcurr->nextInRow;
									curr2 = curr2->nextInRow;
									k--;
									l--;
								}
								else if (k >= 0)
								{
									this->addNode(tcurr, (curr1->value + curr2->value), curr1->colIndex, i);
									tcurr = tcurr->nextInRow;
									curr1 = curr1->nextInRow;
									curr2 = curr2->nextInRow;
									j--;
									k--;
								}
								if (j == -1 and k == -1)
									break;
							}
						}
					}
					else if (curr1->size > curr2->size)
					{
						//If caller list is larger and obj list is greater
						if (counter[1] == 0)
						{
							counter[1] = 1;
							curr1 = curr1->nextInRow;
							curr2 = curr2->nextInRow;
						}
						//Caller list is larger
						if (curr1->colIndex == curr2->colIndex)
						{
							while (true)
							{
								if (k >= 0)
								{
									this->addNode(tcurr, (curr1->value + curr2->value), curr1->colIndex, i);
									tcurr = tcurr->nextInRow;
									curr1 = curr1->nextInRow;
									curr2 = curr2->nextInRow;
									j--;
									k--;
								}
								else if (j >= 0)
								{
									this->addNode(tcurr, (curr1->value), curr1->colIndex, i);
									tcurr = tcurr->nextInRow;
									curr1 = curr1->nextInRow;
									j--;
								}
								if (j == -1 and k == -1)
									break;
							}
						}
						else if (curr1->colIndex < curr2->colIndex)
						{
							int l = j - k;
							while (true)
							{
								if (l > 0)
								{
									this->addNode(tcurr, (curr2->value), curr2->colIndex, i);
									tcurr = tcurr->nextInRow;
									curr2 = curr2->nextInRow;
									j--;
									l--;
								}
								else if (k >= 0)
								{
									if (curr2)
									{
										this->addNode(tcurr, (curr1->value + curr2->value), curr1->colIndex, i);
										tcurr = tcurr->nextInRow;
										curr1 = curr1->nextInRow;
										curr2 = curr2->nextInRow;
										j--;
										k--;
									}
									else
									{
										j--;
										k--;
									}
								}
								if (j == -1 and k == -1)
									break;
							}
						}
					}
					else if (curr1->size == curr2->size)
					{
						//Both lists are equal
						if (counter[5] == 0)
						{
							counter[5] == 1;
							curr1 = curr1->nextInRow;
							curr2 = curr2->nextInRow;
						}

						while (curr1 != nullptr)
						{
							this->addNode(tcurr, (curr1->value + curr2->value), curr1->colIndex, i);
							tcurr = tcurr->nextInRow;
							curr1 = curr1->nextInRow;
							curr2 = curr2->nextInRow;
						}
					}
				}
			}

			temp.N = N;
			temp.M = M;
			return temp;
		}


		// Multiply Operator
		sparse_matrix operator * (const sparse_matrix& obj)
		{
			sparse_matrix temp;
			nodePtr curr1 = nullptr, curr2 = nullptr, tcurr = nullptr;
			int result = 0, tcol = 1, no_of_obj_col_to_be_multiplied = 1;
			int curr1_col_index = 2;
			bool flag = true;
			for (int i = 0; i < this->rowList.size(); i++)
			{
				curr1 = this->rowList[i]->nextInRow;
				temp.rowList.push_back(new node(-1, 0, nullptr));
				tcurr = temp.rowList[i]->nextInRow;
				tcol = 1;

				if (curr1 != nullptr)
				{
					// This row is not NULL
					for (int j = 1; j <= obj.N; j++)		// Traversing obj matrix
					{
						tcol = 1;
						curr1 = this->rowList[i]->nextInRow;
						result = 0;
						curr1_col_index = 2;
						// Traversing Cols
						for (int k = 0; k < obj.M; k++)		// Traversing Rows
						{

							curr2 = obj.rowList[k]->nextInRow;

							if (curr2 == nullptr)
							{
								// It means that obj row which needs to be multipled is NULL
								// and regardless of the this row values
								// result should be zero
								flag = false;
								break;
							}

							no_of_obj_col_to_be_multiplied = 1;
							while (no_of_obj_col_to_be_multiplied < j && curr2 != nullptr)
							{
								if (curr2->colIndex < j)
									curr2 = curr2->nextInRow;
								no_of_obj_col_to_be_multiplied++;
							}

							if (curr2 == nullptr || curr1 == nullptr)
								break;

							else if (curr2->colIndex == j && curr1->colIndex - k == 1)
							{
								// Non zero value is present
								result = result + (curr1->value * curr2->value);
								curr1 = curr1->nextInRow;
							}
							else if (curr2->colIndex < j && curr1->colIndex - k == 1)
							{
								// Non zero value is present
								result = result + (curr1->value * curr2->value);
								curr1 = curr1->nextInRow;
							}
							else if (curr2->colIndex > j && curr1->colIndex - k == 1)
							{
								// Zero value is present
								result = result + 0;
								curr1 = curr1->nextInRow;
							}
						}
						curr1_col_index++;
						//Adding row in temp
						if (flag)
							temp.addNode(result, tcol++, tcurr, i);
					}
				}
				else
				{
					// We should not add value with zero
					// but I am adding just to check my code
					// will remove it later
					// Adding row in temp

					/*result = 0;
					temp.addNode(result, tcol++, tcurr, i);*/
				}
			}
			temp.M = this->M;
			temp.N = obj.N;
			return temp;
		}


		//Insertion Operator
		friend ostream& operator << (ostream& out, const sparse_matrix obj)
		{
			nodePtr curr = nullptr;
			for (int i = 0; i < obj.rowList.size(); i++)
			{
				curr = obj.rowList[i]->nextInRow;
				while (curr != nullptr)
				{
					out << curr->value << ", ";
					curr = curr->nextInRow;
				}
				out << endl;
			}
			return out;
		}

		//Member Functions
		//Read
		void read(string filename)
		{
			//cout << "read() called" << endl;
			ifstream fin(filename);

			//Checking if File is opened or not
			if (fin.is_open())
			{
				int colIndex = 1, i = 0;
				//char buffer[500];
				string buffer;
				char* token = nullptr, * ptr = nullptr;
				char delim[] = " ";
				nodePtr curr = nullptr;
				//This loop will read file till end
				while (!fin.eof())
				{
					//Now we need to read it until '\n'
					getline(fin, buffer, '\n');	//This line will read till endline
					nodePtr head = new node(-1, 0, nullptr);
					rowList.push_back(head);
					//Now we need to tokenize this buffer at [space]
					ptr = strtok_s(&buffer[0], delim, &token);
					colIndex = 1;
					while (ptr)
					{
						if ((int)*ptr - 48 != 0)
							addNode(atoi(ptr), colIndex, curr, i);
						ptr = strtok_s(NULL, delim, &token);
						colIndex++;
					}
					i++;
				}
				this->M = i;	//No. of Rows
				this->N = --colIndex;	//No. of Columns
				fin.close();
			}
			else
			{
				cout << "File not found" << endl;
			}
		}


		//Transpose
		sparse_matrix transpose()
		{
			//cout << "transpose() called" << endl;

			//First we need to create a temp matrix
			sparse_matrix temp;
			//Now we need to push_back temp rows until caller matrix cols
			for (int i = 0; i < this->N; i++)
				temp.rowList.push_back(new node(-1, 0, nullptr));

			//Now we need to add cols of caller matrix to rows of temp
			nodePtr curr = nullptr, tcurr = nullptr;
			int temp_row_index = 0, temp_col_index = 1, j = 1;
			for (int i = 0; i < this->rowList.size(); i++)
			{
				curr = this->rowList[i]->nextInRow;	//Will point curr to next of head

				while (curr != nullptr)
				{
					this->addNode(curr->colIndex - 1, i + 1, curr->value, temp);
					curr = curr->nextInRow;
				}
			}

			temp.M = this->N;
			temp.N = this->M;
			//cout << temp;
			//*this = temp;
			return temp;
		}


		//Print
		void PrintMatrix()
		{
			nodePtr curr = nullptr, prev = nullptr;
			int counter = 1, last_col_index = 1;
			bool flag = true;
			for (int i = 0; i < rowList.size(); i++)
			{
				curr = rowList[i]->nextInRow;
				counter = 1;
				flag = true;

				// If row is NULL
				// Print zero's equal to no. of columns
				if (curr == nullptr)
				{
					int j = this->N;
					while (j >= 1)
					{
						cout << "0, ";
						j--;
					}
				}

				// If row is not NULL
				// Print zero's accordingly
				while (curr != nullptr)
				{
					// If there is no data at first column
					// Print zero's till curr->colIndex - 1;
					if (flag && counter == 1 && curr->colIndex != 1)
					{
						flag = false;
						last_col_index = curr->colIndex;
						while (last_col_index > counter)
						{
							cout << "0, ";
							last_col_index--;
						}
						counter = curr->colIndex;
					}

					if (curr->colIndex > 1 && curr->colIndex != 1)
					{
						// If there is data at first column
						// Print zero's until curr->colIndex - last_col_index
						flag = false;
						last_col_index = curr->colIndex;
						while (last_col_index > counter)
						{
							if (last_col_index - counter != 1)
								cout << "0, ";
							last_col_index--;
						}
						counter = curr->colIndex;
					}

					flag = false;
					cout << curr->value << ", ";
					prev = curr;
					curr = curr->nextInRow;
				}

				if (prev != nullptr && prev->colIndex != this->N)
				{
					// If curr has traversed whole row
					// and colIndex of curr is not equal to N
					// It means that colIndex is smaller than N
					// and we need to print remaning zero's present at last locations
					counter = N;
					last_col_index = prev->colIndex;
					while (last_col_index != counter)
					{
						cout << "0, ";
						last_col_index++;
					}
				}

				cout << endl;
			}
		}


		//Sub Matrix
		bool isSubMatrix(const sparse_matrix& obj)
		{
			//First we need to check for dimensions of sub matrix
			//this -> original matrix, obj -> sub matrix

			if ((obj.M <= this->M) && (obj.N <= this->N))
			{
				int sub_index = 0, check_value = 0;
				nodePtr curr = obj.rowList[sub_index++]->nextInRow;

				//Now check whether the first element even matches or not?
				//if its matches check further otherwise obj is not the sub matrix
				nodePtr curr2 = nullptr;
				for (int i = 0; i < this->rowList.size(); i++)
				{
					curr2 = rowList[i]->nextInRow;
					if (curr == nullptr)
					{
						if (curr2 == nullptr)
						{
							check_value++;
							if (sub_index < obj.rowList.size())
								curr = obj.rowList[sub_index++]->nextInRow;
						}

						else if (curr == nullptr && check_value != 0)
						{
							//It means sub matrix has some NULL row
							//at last position or some in b/w position
							if (curr2->colIndex >= obj.N)
							{
								check_value++;
								if (sub_index < obj.rowList.size())
									curr = obj.rowList[sub_index++]->nextInRow;
								if (check_value == obj.rowList.size())
									return 1;
							}
						}

						else if (curr == nullptr && check_value == 0)
						{
							//It means sub matrix has some NULL row
							//at starting position
							if (curr2->colIndex >= obj.N)
							{
								check_value++;
								if (sub_index < obj.rowList.size())
									curr = obj.rowList[sub_index++]->nextInRow;
							}
						}

						//We need to find row of this which is also NULL
						else if (curr2 != nullptr)
						{
							continue;
						}
					}
					else if (curr)
					{
						if (curr2 != nullptr && (curr->value == curr2->value))
						{
							//If values matches then we need to check for whole row of curr(obj)
							bool flag = true;
							while (curr != nullptr)
							{
								if (curr->value != curr2->value || curr->colIndex != curr2->colIndex)
								{
									if (curr->colIndex + 1 == curr2->colIndex)
									{
										//It means we have a null which can be ignored
										curr = curr->nextInRow;
										curr2 = curr2->nextInRow;
										continue;
									}
									else
									{
										check_value = sub_index = 0;
										curr = obj.rowList[sub_index++]->nextInRow;
										flag = false;
										break;
									}
								}
								curr = curr->nextInRow;
								curr2 = curr2->nextInRow;
							}
							if (flag)
							{
								check_value++;
								if (sub_index < obj.rowList.size())
									curr = obj.rowList[sub_index++]->nextInRow;
							}
							if (check_value == obj.rowList.size())
								return 1;
						}
						else if (curr2 != nullptr && curr->value != curr2->value)
						{
							//It means that we need to travserswe curr2(original matrix row)
							//in order to check whether the match is in some front
							while (curr2 != nullptr)
							{
								if (curr->value == curr2->value)
									break;
								curr2 = curr2->nextInRow;
							}
							if (curr2 != nullptr && curr2->value == curr->value)
							{
								bool flag = true;
								while (curr != nullptr && curr2 != nullptr)
								{
									if (curr->value != curr2->value)
									{
										if (curr->colIndex + 1 == curr2->colIndex)
										{
											//It means we have a null which can be ignored
											curr = curr->nextInRow;
											curr2 = curr2->nextInRow;
											continue;
										}
										else
										{
											check_value = sub_index = 0;
											curr = obj.rowList[sub_index++]->nextInRow;
											flag = false;
											break;
										}
									}
									curr = curr->nextInRow;
									curr2 = curr2->nextInRow;
								}
								if (flag)
								{
									check_value++;
									if (sub_index < obj.rowList.size())
										curr = obj.rowList[sub_index++]->nextInRow;
								}
								if (check_value == obj.rowList.size())
									return 1;
							}
						}
						else if (check_value == obj.rowList.size())
							return 1;
						else
						{
							check_value = 0;
							sub_index = 0;
							curr = obj.rowList[sub_index++]->nextInRow;
						}
					}
				}

				if (check_value == obj.rowList.size())
					return 1;
			}
			return 0;
		}


		//Destructor
		~sparse_matrix()
		{
			//cout << "~sparse_matrix() called" << endl;

			nodePtr curr = nullptr;
			for (int i = 0; i < rowList.size(); i++)
			{
				curr = rowList[i];
				while (curr != nullptr)
					delNode(curr);
			}
			this->rowList.clear();
			M = N = 0;
			curr = nullptr;
		}
	};

	//This is a Stack Class
	template <typename T>
	class stack
	{
		int size, top, capacity;
		T* arr;

	public:
		//Constrcutor
		//Default Constructor
		stack(int size = 0)
		{
			cout << "stack() called" << endl;
			if (size > 0)
			{
				this->capacity = size;
				this->size = 0;
				this->top = -1;
				this->arr = new T[capacity];
			}
			else
			{
				this->size = capacity = 0;
				this->arr = nullptr;
				this->top = -1;
			}
		}


		//Copy Constructor
		stack(const stack<T>& obj)
		{
			cout << "stack copy() called" << endl;
			this->size = obj.size;
			this->capacity = obj.capacity;
			this->top = obj.top;
			//Initialize Values
			this->arr = new T[this->size];
			//copying stack
			for (int i = 0; i < this->size; i++)
				this->arr[i] = obj.arr[i];
		}


		//Operator Overloading
		stack<T> operator =(const stack<T>& obj)
		{
			cout << "assignment operator() called" << endl;
			//checking if caller function already
			//has some allocated memory
			if (this)
				delete[] this->arr;

			//Copying (Assigning)
			this->size = obj.size;
			this->capacity = obj.capacity;
			this->top = obj.top;
			//Initialize Values
			this->arr = new T[this->size];
			//copying stack
			for (int i = 0; i < this->size; i++)
				this->arr[i] = obj.arr[i];

			return *this;
		}


		//Member Functions
		//Push
		void Push(const T& obj)
		{
			//cout << "Push() called" << endl;
			if (this->size < this->capacity)
			{
				this->arr[++top] = obj;
				size++;
			}
			else if (this->capacity == 0)
			{
				this->arr = new T[1];
				arr[++top] = obj;
				size = capacity = 1;
			}
			else
			{
				//Growing
				T* temp = new T[2 * capacity];
				//copying values
				for (int i = 0; i < size; i++)
					temp[i] = arr[i];
				temp[++top] = obj;
				size++;
				capacity *= 2;
				delete[] arr;
				arr = temp;
			}
		}


		//Pop
		void Pop()
		{
			if (this->Empty())
				return;
			else if (this->size > capacity / 2)
			{
				size--;
				top--;
			}
			else
			{
				//Shrinking
				T* temp = new T[capacity / 2];
				//Copying Values
				for (int i = 0; i < size; i++)
					temp[i] = arr[i];
				capacity /= 2;
				size--;
				top--;
				delete[] arr;
				arr = temp;
			}
		}

		//Reverse
		void Reverse()
		{
			cout << "Reverse() called" << endl;
			//Creating a new stack of capacity = this->size
			T* temp = new T[this->size];
			//Copying values
			for (int i = 0, k = size - 1; i < size; i++, k--)
			{
				temp[i] = arr[k];
			}
			this->capacity = size;
			delete[] arr;
			arr = temp;
		}


		//Empty
		bool Empty()
		{
			return size == 0 ? 1 : 0;
		}


		//Full
		bool Full()
		{
			return size == capacity ? 1 : 0;
		}

		//Peek
		T Peek()
		{
			if (this->Empty())
				return NULL;
			return this->arr[top];
		}


		//Print
		void Print()
		{
			if (this->Empty())
				return;
			cout << "Print() called" << endl;
			for (int i = 0; i < size; i++)
				cout << arr[i] << " ";
			cout << endl;
		}


	};

	//This is a BST Class
	template <typename T>
	class bst
	{
		//private data memebrs

		//Node class for BST
		typedef struct node
		{
			T data;
			node* lchild, * rchild;
		}*nodePtr;

		nodePtr root;

	public:	//This is where the function goes

		//Constructor
		//Default Cinstructor
		bst()
		{
			cout << "bst() called" << endl;
			this->root = nullptr;
		}



		//Getters
		//get root
		nodePtr getRoot() { return this->root; }


		//Member Functions

		//Insert
		//Iterative Version
		void insert(T key)
		{
			cout << "insert() called" << endl;
			nodePtr t = this->root;	//for traversal
			nodePtr p = nullptr, n = nullptr;	//'p' for previous and 'n' for new node

			//First Case
			//Only occurs when the tree is empty which means only for the first time
			if (this->root == NULL)
			{
				//create a node and insert into the BST
				n = new node;
				n->data = key;
				n->lchild = n->rchild = nullptr;
				this->root = n;
				return;
			}
			//other cases occurs when the tree is not empty
			while (t != nullptr)
			{
				p = t;
				if (key < t->data)
					t = t->lchild;
				else if (key > t->data)
					t = t->rchild;
				else
					return;
			}

			//after the while loop 't' will be at NULL but 'p' will be pointing
			//to the previous node than 't'.
			//we can insert into 'p'

			//allocating memory for the new node
			n = new node;
			n->data = key;
			n->lchild = n->rchild = nullptr;

			//comparing data with 'p' node
			if (key < p->data)
				p->lchild = n;
			else if (key > p->data)
				p->rchild = n;

		}


		//Insert
		//Recursive Version
		void insertR(T key)
		{
			//this is the wrapper function for insert
			cout << "insertR() called" << endl;
			nodePtr t = this->root;
			insertR(this->root, key);
		}


		//Recursive function for insert
		void insertR(nodePtr& t, T key)
		{
			if (t == nullptr)
			{
				t = new node;
				t->data = key;
				t->lchild = t->rchild = nullptr;
			}
			else
			{
				if (key < t->data)
					insertR(t->lchild, key);
				else if (key > t->data)
					insertR(t->rchild, key);
			}
		}

		//Searching
		nodePtr search(T key)
		{
			//this is the wrapper function for search
			cout << "search() called" << endl;
			nodePtr t = this->root;
			return search(t, key);
		}


		//Recusrsive function for search
		nodePtr search(nodePtr t, T key)
		{
			if (t == nullptr)
				return NULL;
			if (key == t->data)
				return t;
			else if (key < t->data)
				search(t->lchild, key);
			else if (key > t->data)
				search(t->rchild, key);
		}



		//Inorder Printing
		void inorder(nodePtr t)
		{
			if (t)
			{
				//this is a recursive function
				//it prints data of bst in sorted order
				//i.e from left-root-right
				//cout << "inorder() called" << endl;
				inorder(t->lchild);
				cout << t->data << ", " << flush;
				inorder(t->rchild);
			}
		}



		//Deleting a Node
		void remove(T data)
		{
			//This is the wrapper function for remove a node
			remove(this->root, data);
		}



		//Deleting Node
		void remove(nodePtr& r, T d)
		{
			if (r == nullptr)
				return;
			else if (d < r->data)
				remove(r->lchild, d);
			else if (d > r->data)
				remove(r->rchild, d);
			else if (r->lchild && r->rchild)
			{
				//This case is for a node which has both leave nodes
				T temp = findmin(r->rchild);
				remove(r->rchild, temp);
				r->data = temp;
			}
			else if (r->lchild == nullptr && r->rchild == nullptr)
			{
				//This case is for a node which is a leaf node itself
				//i.e it has no left and right child
				delete r;
				r = nullptr;
			}
			else if (r->lchild != nullptr)
			{
				nodePtr t = r;
				r = r->lchild;
				delete t;
			}
			else
			{
				nodePtr t = r;
				r = r->rchild;
				delete t;
			}

		}//remove


		//Finding Minimum
		T findmin(nodePtr r)
		{
			while (r->lchild != nullptr)
				r = r->lchild;
			return r->data;
		}//findmin


		//Height
		int height(nodePtr r)
		{
			if (r == nullptr)
				return -1;
			else
				return (1 + max(height(r->lchild), height(r->rchild)));
		}


		//Maximum Finder
		int max(int x, int y)
		{
			return x < y ? y : x;
		}
	};

	//This is an AVL Class
	template <typename T>
	class avl
	{
		//private data memebrs

		//Node class for AVL
		typedef struct node
		{
			T data;
			node* lchild, * rchild;
			int height;
		}*nodePtr;

		nodePtr root;

	public:	//This is where the function goes

		//Constructor
		//Default Cinstructor
		avl()
		{
			cout << "avl() called" << endl;
			this->root = nullptr;
		}



		//Getters
		//get root
		nodePtr getRoot() { return this->root; }


		//Member Functions

		//Insert
		//Recursive Version
		void insertR(T key)
		{
			//this is the wrapper function for insert
			cout << "insertR() called" << endl;
			insertR(this->root, key);
		}


		//Recursive function for insert
		void insertR(nodePtr& t, T key)
		{
			if (t == nullptr)
			{
				t = new node;
				t->data = key;
				t->lchild = t->rchild = nullptr;
				t->height = -1;
			}
			else
			{
				if (key < t->data)
				{
					insertR(t->lchild, key);
					if (balancedFactor(t) == 2)
					{
						if (key < t->lchild->data)	//outside case "LL rotation", means rotate towards right side
						{
							rotateRight(t);
						}
						else	//inside case "LR rotation", means double rotation, first towards left then towards right
						{
							doubleRotateLeft(t);
						}
					}
				}
				else if (key > t->data)
				{
					insertR(t->rchild, key);
					if (balancedFactor(t) == -2)
					{
						if (key > t->rchild->data)	//outside case "RR rotation", means rotate towards left side
						{
							rotateLeft(t);
						}
						else	//inside case "RL rotation", means double rotation, first towards right then towards left
						{
							doubleRotateRight(t);
						}
					}
				}
			}
			t->height = max(height(t->lchild), height(t->rchild)) + 1;
		}

		//Searching
		bool search(T key)
		{
			//this is the wrapper function for search
			cout << "search() called" << endl;
			nodePtr t = this->root;
			return search(t, key);
		}


		//Recusrsive function for search
		bool search(nodePtr t, T key)
		{
			if (t == nullptr)
				return 0;
			if (key == t->data)
				return 1;
			else if (key < t->data)
				search(t->lchild, key);
			else if (key > t->data)
				search(t->rchild, key);
		}



		//Inorder Printing
		void inorder(nodePtr t)
		{
			if (t)
			{
				//this is a recursive function
				//it prints data of avl in sorted order
				//i.e from left-root-right
				//cout << "inorder() called" << endl;
				inorder(t->lchild);
				cout << t->data << ", " << flush;
				inorder(t->rchild);
			}
		}



		//maximum finder
		int max(int x, int y)
		{
			return x < y ? y : x;
		}


		//Height
		int height(nodePtr t)
		{
			return t == nullptr ? -1 : t->height;

			/*int hl;
			int hr;

			hl = (p && p->lchild) ? p->lchild->height : 0;
			hr = (p && p->rchild) ? p->rchild->height : 0;

			return hl > hr ? hl : hr;*/
		}




		//Deleting a Node
		void remove(T data)
		{
			//This is the wrapper function for remove a node
			remove(this->root, data);
		}



		//Deleting Node
		void remove(nodePtr& r, T d)
		{

			if (r == nullptr)
				return;
			else if (d < r->data)
				remove(r->lchild, d);
			else if (d > r->data)
				remove(r->rchild, d);
			else if (r->lchild && r->rchild)
			{
				//This case is for a node which has both leave nodes
				T temp = findmin(r->rchild);
				remove(r->rchild, temp);
				r->data = temp;
			}
			else if (r->lchild == nullptr && r->rchild == nullptr)
			{
				//This case is for a node which is a leaf node itself
				//i.e it has no left and right child
				delete r;
				r = nullptr;
			}
			else if (r->lchild != nullptr)
			{
				nodePtr t = r;
				r = r->lchild;
				delete t;
			}
			else
			{
				nodePtr t = r;
				r = r->rchild;
				delete t;
			}
			if (r == nullptr)
				return;

			r->height = max(height(r->lchild), height(r->rchild)) + 1;

			//needs to change from here (perform rotations)
			if (balancedFactor(r) == 2)
			{
				if (balancedFactor(r->lchild) == 1 || balancedFactor(r->lchild) == 0)
					rotateRight(r);
				else if (balancedFactor(r->lchild) == -1)
					doubleRotateLeft(r);
			}
			else if (balancedFactor(r) == -2)
			{
				if (balancedFactor(r->rchild) == -1 || balancedFactor(r->rchild) == 0)
					rotateLeft(r);
				else if (balancedFactor(r->rchild) == 1)
					doubleRotateRight(r);
			}

		}//remove


		//Finding Minimum
		T findmin(nodePtr r)
		{
			while (r->lchild != nullptr)
				r = r->lchild;
			return r->data;
		}//findmin



		int balancedFactor(nodePtr t)
		{
			return (height(t->lchild) - height(t->rchild));
		}//balanceFactor

		//Rotations
		//Outside Cases
		//RR Rotation
		void rotateLeft(nodePtr& n)
		{
			cout << "RR rotation() called" << endl;
			nodePtr p = n->rchild;
			n->rchild = p->lchild;
			p->lchild = n;
			n->height = max(height(n->lchild), height(n->rchild)) + 1;
			p->height = max(height(p->rchild), n->height) + 1;
			n = p;
		}


		//LL Rotation
		void rotateRight(nodePtr& n)
		{
			cout << "LL rotation() called" << endl;
			nodePtr p = n->lchild;
			n->lchild = p->rchild;
			p->rchild = n;
			n->height = max(height(n->lchild), height(n->rchild)) + 1;
			p->height = max(height(p->lchild), n->height) + 1;
			n = p;
		}

		//Inside Cases
		//LR Rotation
		void doubleRotateLeft(nodePtr& n)
		{
			cout << "LR rotation() called" << endl;
			rotateLeft(n->lchild);
			rotateRight(n);
		}


		//RL Rotation
		void doubleRotateRight(nodePtr& n)
		{
			cout << "RL rotation() called" << endl;
			rotateRight(n->rchild);
			rotateLeft(n);
		}
	};
}