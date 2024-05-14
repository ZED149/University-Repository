

// This file contains the BST class


#pragma once


// including libraries and namespaces
#include <iostream>
#include "tree.h"
using namespace std;


template <typename T>
class BST : public Tree<T>
{
	// This BST class inherits fromt the Base Tree class

	// Utility / Helper Functions

	// recursive insert
	void insert_R(Tree<T>::NodePtr &t, T data)
	{
		if (t == nullptr)
		{
			// initialize the node
			t = new Tree<T>::template Node;
			t->data = data;
			t->left = t->right = nullptr;
		}
		else
		{
			int a = 1;
			cout << a << endl;
		}
	}

public:
	// Constructor
	
	// Default Constructor
	BST(const string name = "NaN", const int count = 0):
		Tree<T>(name, count)
	{
#ifdef _DEBUG
		cout << "BST() called" << endl;
#endif; // !_DEBUG
	}

	// Over-Riding Functions

	// Member Functions
	
	// insert
	virtual void insert(T data)
	{
		// This function is a wrapper function for recursive insert
		this->insert_R(this->root, data);
	}

	// remove
	virtual void remove(T data)
	{}

	// find
	virtual bool find(const T &data)
	{
		return true;
	}

	// get height
	virtual int get_height()
	{
		return 1;
	}

	// is empty
	virtual bool is_empty()
	{
		return true;
	}

	// Destructor
	virtual ~BST()
	{

	}
};