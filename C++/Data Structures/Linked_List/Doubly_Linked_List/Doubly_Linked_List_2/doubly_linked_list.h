
#pragma once

#include <iostream>
using namespace std;



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
	}* nodePtr;

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
	void insertAtStart(const T &value)
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
	friend ostream& operator << (ostream &out, const doubly_linked_list<T> obj)
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
	bool insertBefore(const T &v1, const T &v2)
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
			curr->next= prev;
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