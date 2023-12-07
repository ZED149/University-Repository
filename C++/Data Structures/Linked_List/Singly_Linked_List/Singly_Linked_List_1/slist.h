

#pragma once




#include <iostream>
#include <stack>
using namespace std;


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
		node(const T &data, node* nextPtr = nullptr)
		{
			this->data = data;
			this->next = nextPtr;
		}

		node()
		{
			this->next = next;
		}
	}* nodePtr;

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
	slist(const slist<T> &obj) 
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
	void insertAtHead(const T &obj)
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