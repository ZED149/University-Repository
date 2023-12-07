#pragma once




#include <iostream>
using namespace std;


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
			this->capacity = size+1;
			this->arr = new T[capacity+1];
		}
		else
		{
			this->front = this->rear = this->size = 0;
			this->capacity = 0;
			this->arr = nullptr;
		}
	}

	//Copy Constructor
	queue(const queue<T> &obj)
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
		for (int i = next(obj.front); i <= obj.size; i=next(i))
		{
			this->arr[i] = obj.arr[i];
			//i = next(i);
		}
	}


	//Operator Overloading
	//Assignment Operator
	queue<T> operator = (const queue<T> &obj)
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
			rear = size-1;
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