



#include <iostream>
using namespace std;


//Doubly Linked List Class

#ifndef DLIST_H 
#define DLIST_H

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

#endif