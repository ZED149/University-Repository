

// This file contains the BST class


#pragma once


// including libraries and namespaces
#include <iostream>
#include "tree.h"
#include <fstream>
#include <stdexcept>
#include <string>
#include <Windows.h>
using namespace std;


template <typename T>
class BST : public Tree<T>
{
	// This BST class inherits fromt the Base Tree class

	// Utility / Helper Functions

	// recursive insert
	void insert_R(Tree<T>::NodePtr &t, const T data)
	{
		// This is a recursive function to insert a node of data T in the Tree

#ifdef _DEBUG
		static int _counter = 0;
#endif;

		if (t == nullptr)
		{
			// if node is nullptr, this will always happen for the root Node first
			// For other insertions, the recusive calls will iterate the tree to the node which insertion is going to happen
			 
			
			// initialize the node
			t = new Tree<T>::template Node;
			t->data = data;
			t->left = t->right = nullptr;

			// increasing count to maintain total number of nodes in the tree
			this->count++;
#ifdef _DEBUG
			_counter++;
			cout << _counter << endl;
#endif;
		}
		else
		{
			// if node is not null
			if (data < t->data)
				insert_R(t->left, data);
			else if (data > t->data)
				insert_R(t->right, data);
		}
	}

	//Finding Minimum
	T findmin(Tree<T>::NodePtr r)
	{
		while (r->left != nullptr)
			r = r->left;
		return r->data;
	}//findmin

	// recursive remove
	void remove_R(Tree<T>::NodePtr& t, const T data)
	{
		// This function recusrsively remove the specific node containing data = T

		if (t == nullptr)
			return;
		else if (data < t->data)
			remove_R(t->left, data);
		else if (data > t->data)
			remove_R(t->right, data);
		else if (t->left && t->right)
		{
			//This case is for a node which has both leave nodes
			T temp = findmin(t->right);
			remove_R(t->right, temp);
			t->data = temp;
		}
		else if (t->left == nullptr && t->right == nullptr)
		{
			//This case is for a node which is a leaf node itself
			//i.e it has no left and right child
			delete t;
			t = nullptr;

			// decreasing count to maintain the total number of nodes in the tree
			this->count--;
		}
		else if (t->left != nullptr)
		{
			Tree<T>::template Node* r = t;
			t = t->left;
			delete r;

			// decreasing count to maintain the total number of nodes in the tree
			this->count--;
		}
		else
		{
			Tree<T>::template Node* r = t;
			t = t->right;
			delete r;

			// decreasing count to maintain the total number of nodes in the tree
			this->count--;
		}
	}

	// recursive find
	bool find_R(const Tree<T>::NodePtr& t, const T& data) const
	{
		if (t == nullptr)
			return false;
		if (data == t->data)
			return true;
		else if (data < t->data)
			find_R(t->left, data);
		else if (data > t->data)
			find_R(t->right, data);
	}

	//Maximum Finder
	int my_max(const int &x, const int &y)
	{
		return x < y ? y : x;
	}

	// recursive height
	int height_R(const Tree<T>::NodePtr& t)
	{
		if (t == nullptr)
			return -1;
		else
			return (1 + my_max(height_R(t->left), height_R(t->right)));
	}

	// _destroy_R
	void _destroy_R(Tree<T>::Node* &t)
	{
		if (t)
		{
			_destroy_R(t->left);
			_destroy_R(t->right);
			delete t;
			t = nullptr;
		}
	}

public:
	// Constructor
	
	// Default Constructor
	BST(const string name = "NaN", const int count = 0, const string &filename = "_nan") :
		Tree<T>(name, count)
	{
#ifdef _DEBUG
		cout << "BST() called" << endl;
#endif; // !_DEBUG

		// if filename is not nan, we need to load data from file and insert them into the BST as nodes
		if (strcmp(filename.c_str(), "_nan") != 0)
		{
			// user have specified a file

			// opening the file
			fstream fout;
			fout.open(filename.c_str());
			// checking if the file is opened or not
			if (fout.is_open())
			{
				// if file is opened successfully
				// read its content in a buffer
				string buffer;
				while (!fout.eof())
				{
					getline(fout, buffer, '\n');
					// we need to push each word into the BST as a new node
					this->insert(buffer);				// recusrive insert
					//this->test_insert(buffer);		// iterative insert
				}
			}
			else
			{
				throw std::invalid_argument("Cannot open file. Check filename.");
			}
		}
	}

	// Over-Riding Functions

	// Member Functions
	
	// insert
	virtual void insert(T data)
	{
		// This function is a wrapper function for recursive insert
		this->insert_R(this->root, data);
	}

	// test_insert
	void test_insert(T data)
	{
#ifdef _DEBUG
		static int _counter = 0;
#endif;

		//cout << "insert() called" << endl;
		Tree<T>::template Node* t = this->root;	//for traversal
		Tree<T>::template Node* p = nullptr;
		Tree<T>::template Node* n = nullptr;	//'p' for previous and 'n' for new node

		//First Case
		//Only occurs when the tree is empty which means only for the first time
		if (this->root == NULL)
		{
			//create a node and insert into the BST
			n = new Tree<T>::template Node;
			n->data = data;
			n->left= n->right= nullptr;
			this->root = n;
#ifdef _DEBUG
			_counter++;
			cout << _counter << endl;
#endif;
			return;		
		}
		//other cases occurs when the tree is not empty
		while (t != nullptr)
		{
			p = t;
			if (data < t->data)
				t = t->left;
			else if (data > t->data)
				t = t->right;
			else
				return;
		}

		//after the while loop 't' will be at NULL but 'p' will be pointing
		//to the previous node than 't'.
		//we can insert into 'p'

		//allocating memory for the new node
		n = new Tree<T>::template Node;
		n->data = data;
		n->left= n->right = nullptr;

		//comparing data with 'p' node
		if (data < p->data)
			p->left = n;
		else if (data > p->data)
			p->right = n;

#ifdef _DEBUG
		_counter++;
		cout << _counter << endl;
#endif;
	}

	// remove
	virtual void remove(T data)
	{
		// This function deletes a node from the tree of given data
		// It is also a wrapper function for the recursive delete
		this->remove_R(this->root, data);
	}

	// find
	virtual bool find(const T &data) const
	{
		// This is the wrapper function for the recursive find
		bool flag = this->find_R(this->root, data);
		return flag;
	}

	// get height
	virtual int get_height(Tree<T>::NodePtr t = nullptr) 
	{
		t = this->root;
		// This is the wrapper function for the recursive height function
		int h = height_R(t);
		return h;
	}

	// is empty
	virtual bool is_empty()
	{
		return this->count > 0 ? true : false;
	}

	// Destructor
	virtual ~BST()
	{
		_destroy_R(this->root);
	}
};