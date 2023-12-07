

#pragma once

#include <iostream>
using namespace std;

#ifndef AVL_H
#define AVL_H


//class for AVL Tree
template <typename T>
class avl
{
	//private data memebrs

	//Node class for AVL
	typedef struct node
	{
		T data;
		node* lchild, *rchild;
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
	void remove(nodePtr &r, T d)
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
	void rotateLeft(nodePtr &n)
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
	void rotateRight(nodePtr &n)
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
	void doubleRotateLeft(nodePtr &n)
	{
		cout << "LR rotation() called" << endl;
		rotateLeft(n->lchild);
		rotateRight(n);
	}


	//RL Rotation
	void doubleRotateRight(nodePtr &n)
	{
		cout << "RL rotation() called" << endl;
		rotateRight(n->rchild);
		rotateLeft(n);
	}
};
#endif