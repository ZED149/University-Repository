
// This file contains the Tree class
// Tree class is the base class for any type of tree


#pragma once


// including libraries and namespaces
#include <iostream>
using namespace std;


template <typename T>
class Tree
{
public:
	// Node class for any of the tree 
	typedef struct Node
	{
		T data;					// data to be stored
		Node* left, *right;		// Left and Right Nodes of this specific Node
	}*NodePtr;
	// Data Members

	// Defifining Root node
	NodePtr root;				// ROOT node of the tree
	string name;				// Name of the tree, just in case if we have multiple trees
	int count;					// size of the tree (Total number of nodes in the tree)
public:
	// Constructors
	
	// Default Constructors with params
	Tree(const std::string name = "NaN", const int count = 0)
	{
#ifdef _DEBUG
		cout << "Tree() called\n";
#endif;
		// initializing private members
		this->name = name;
		this->count = count;

		// initializing Root with null
		this->root = nullptr;
	}

	// Copy Constructor
	Tree(const Tree& obj) = delete;

	// Assignment Operator
	Tree& operator = (const Tree& obj) = delete;

	// Member Functions

	// insert
	virtual void insert(T data) = 0;

	// delete
	virtual void remove(T data) = 0;

	// find
	virtual bool find(const T &data) = 0;

	// get height
	virtual int get_height() = 0;

	// size
	int size()
	{
		return this->count;
	}

	// is empty
	virtual bool is_empty() = 0;

	// Print
	void print(const ostream& out) const
	{
		// prints the tree in a nice format
		this->in_order_print(out, root);
	}

	// Traversal Functions

	// In Order
	static void pre_order_print(const ostream& out, Node* t)
	{
		if (t)
		{
			//this is a recursive function
			//it prints data of tree in sorted order
			//i.e from left-root-right
			//cout << "inorder() called" << endl;
			inorder(t->lchild);
			cout << t->data << ", " << flush;
			inorder(t->rchild);
		}
	}

	// Pre Order
	static void in_order_print(const ostream& out, Node* t)
	{
		if (t)
		{
			//this is a recursive function
			//it prints data of tree in sorted order
			//i.e from left-root-right
			//cout << "inorder() called" << endl;
			in_order_print(out, t->left);
			cout << t->data << ", " << flush;
			in_order_print(out, t->right);
		}
	}
	
	// Post Order
	static void post_order_print(ostream& out, Node* t) {}

	// Destructor
	virtual ~Tree()
	{

	}
};