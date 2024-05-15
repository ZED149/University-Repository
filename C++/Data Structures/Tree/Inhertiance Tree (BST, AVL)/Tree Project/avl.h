

// This file contains the AVL Tree class


#pragma once


// inlucding libraries and namespaces
#include <iostream>
#include "tree.h"
#include <string>
using namespace std;

template <typename T>
class AVL : public Tree<T>
{
	// This AVL class inherits from the BASE Tree class

	// Utility / Helper Functions

	// Rotation Functions
	// Outside Cases
	// RR Rotation
	void rotateLeft(Tree<T>::NodePtr& n)
	{
#ifdef _DEBUG
		cout << "RR rotation() called" << endl;
#endif; // _DEBUG

		Tree<T>::template NodePtr p = n->right;
		n->right= p->left;
		p->left= n;
		n->height = my_max(height_R(n->left), height_R(n->right)) + 1;
		p->height = my_max(height_R(p->right), n->height) + 1;
		n = p;
	}

	// LL Rotation
	void rotateRight(Tree<T>::NodePtr &n)
	{
#ifdef _DEBUG
		cout << "LL rotation() called" << endl;
#endif; // _DEBUG
			
		Tree<T>::template Node* p = n->left;
		n->left= p->right;
		p->right= n;
		n->height = my_max(height_R(n->left), height_R(n->right)) + 1;
		p->height = my_max(height_R(p->left), n->height) + 1;
		n = p;
	}

	// Inside Cases
	// LR Rotation
	void doubleRotateLeft(Tree<T>::NodePtr &n)
	{
#ifdef _DEBUG
		cout << "LR roation() called" << endl;
#endif;
		
		rotateLeft(n->left);
		rotateRight(n);
	}

	// RL Rotation
	void doubleRotateRight(Tree<T>::NodePtr &n)
	{
#ifdef _DEBUG
		cout << "RL rotation() called" << endl;
#endif;
		
		rotateRight(n->right);
		rotateLeft(n);
	}

	// balanced factor
	int balancedFactor(Tree<T>::NodePtr t)
	{
		return (height_R(t->left) - height_R(t->right));
	}

	// recursive insert
	void insert_R(Tree<T>::NodePtr& t, const T data)
	{
		// This is a recursive function to insert a node of data T in the Tree

		if (t == nullptr)
		{
			t = new Tree<T>::template Node;
			t->data = data;
			t->left = t->right = nullptr;
			t->height = -1;
		}
		else
		{
			if (data < t->data)
			{
				insert_R(t->left, data);
				if (balancedFactor(t) == 2)
				{
					if (data < t->left->data)	//outside case "LL rotation", means rotate towards right side
					{
						rotateRight(t);
					}
					else	//inside case "LR rotation", means double rotation, first towards left then towards right
					{
						doubleRotateLeft(t);
					}
				}
			}
			else if (data > t->data)
			{
				insert_R(t->right, data);
				if (balancedFactor(t) == -2)
				{
					if (data > t->right->data)	//outside case "RR rotation", means rotate towards left side
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
		t->height = my_max(height_R(t->left), height_R(t->right)) + 1;
	}

	// recursive height
	int height_R(const Tree<T>::NodePtr& t)
	{
		if (t == nullptr)
			return -1;
		else
			return (1 + my_max(height_R(t->left), height_R(t->right)));
	}

	//Maximum Finder
	int my_max(const int& x, const int& y)
	{
		return x < y ? y : x;
	}

	// recursive remove
	void remove_R(Tree<T>::NodePtr& r, const T data)
	{
		if (r == nullptr)
			return;
		else if (data < r->data)
			remove_R(r->left, data);
		else if (data > r->data)
			remove_R(r->right, data);
		else if (r->left && r->right)
		{
			//This case is for a node which has both leave nodes
			T temp = findmin(r->right);
			remove_R(r->right, temp);
			r->data = temp;
		}
		else if (r->left == nullptr && r->right == nullptr)
		{
			//This case is for a node which is a leaf node itself
			//i.e it has no left and right child
			delete r;
			r = nullptr;
		}
		else if (r->left != nullptr)
		{
			Tree<T>::template Node* t = r;
			r = r->left;
			delete t;
		}
		else
		{
			Tree<T>::template Node* t = r;
			r = r->right;
			delete t;
		}
		if (r == nullptr)
			return;

		r->height = my_max(height_R(r->left), height_R(r->right)) + 1;

		//needs to change from here (perform rotations)
		if (balancedFactor(r) == 2)
		{
			if (balancedFactor(r->left) == 1 || balancedFactor(r->left) == 0)
				rotateRight(r);
			else if (balancedFactor(r->left) == -1)
				doubleRotateLeft(r);
		}
		else if (balancedFactor(r) == -2)
		{
			if (balancedFactor(r->right) == -1 || balancedFactor(r->right) == 0)
				rotateLeft(r);
			else if (balancedFactor(r->right) == 1)
				doubleRotateRight(r);
		}
	}

	//Finding Minimum
	T findmin(Tree<T>::NodePtr r)
	{
		while (r->left != nullptr)
			r = r->left;
		return r->data;
	}//findmin

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

	// _destroy_R
	void _destroy_R(Tree<T>::Node*& t)
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
	AVL(const string name = "NaN", const int count = 0, const string& filename = "_nan") :
		Tree<T>(name, count)
	{
#ifdef _DEBUG
		cout << "AVL() called" << endl;
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
					this->insert(buffer);
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

	// remove
	virtual void remove(T data)
	{
		// This function deletes a node from the tree of given data
		// It is also a wrapper function for the recursive delete
		this->remove_R(this->root, data);
	}

	// find
	virtual bool find(const T& data) const
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
	virtual ~AVL()
	{
		_destroy_R(this->root);
	}
};