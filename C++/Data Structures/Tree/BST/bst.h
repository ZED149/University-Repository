

#pragma once

#include <iostream>
using namespace std;

#ifndef BST_H
#define BST_H


//class for bst
template <typename T>
class bst
{
	//private data memebrs

	//Node class for BST
	typedef struct node
	{
		T data;
		node* lchild, * rchild;
	}* nodePtr;

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
	void insertR(nodePtr &t, T key)
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
			else if (key > t -> data)
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
#endif