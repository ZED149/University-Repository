#pragma once



#include <iostream>
using namespace std;


template <typename T>
class array_ADT
{
	//we need 3 variables
	/*
	1. Size => Logical Size (Current size of the array)
	2. Capacity => Physical Size (Total size of the array)
	3. T pointer for any type of data
	*/
	T* arr;
	int size, capacity;

public:

	//Constructor
	//Default Constructor
	array_ADT(int capacity)
	{
		cout << "array_ADT() called" << endl;
		this->size = 0;
		this->capacity = capacity;
		this->arr = new T[capacity];
	}

	//Copy Constructor
	array_ADT(const array_ADT& obj)
	{
		this->size = obj.size;
		this->capacity = obj.capacity;
		this->arr = new T[obj.size];
		for (int i = 0; i < obj.size; i++)
			this->arr[i] = obj.arr[i];

		return *this;
	}

	//Member Functions
	//Print
	void print()
	{
		cout << "print() called" << endl;
		if (size <= capacity)
		{
			for (int i = 0; i < size; i++)
				cout << this->arr[i] << " ";
		}
	}


	//Insert
	void insert(const T &value)
	{
		if (this->size < this->capacity)
		{
			this->arr[size++] = value;
		}
	}


	//Delete
	void Delete(const int index)
	{
		//Delete function will take index as a parameter
		//at which the value needs to be deleted
		if (index < size)
		{
			size--;
			for (int i = index; i < size; i++)
				arr[i] = arr[i + 1];
		}
	}

	//Search
	int search(const T& key)
	{
		static int temp = 0;
		for (int i = 0; i < size; i++)
		{
			if (arr[temp] == key)
				return temp;
			if (arr[i] == key)
			{
				temp = i;
				return i;
			}
		}
		return -1;
	}


	//Binary Search
	int binarySearch(const T& key)
	{
		int low, high, mid = 0;
		low = 0;
		high = this->size - 1;

		while (low <= high)
		{
			mid = (low + high) / 2;
			if (key == arr[mid])
				return mid;
			else if (key < arr[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}

		return -1;
	}


	//Binary Search Recursive Version
	int RBinarySearch(const T& key)
	{
		//This is the wrapper function for recursive binary search
		return RBinarySearch(0, this->size - 1, key);
	}

	int RBinarySearch(int low, int high, const T& key)
	{
		if (low <= high)
		{
			int mid = (low + high) / 2;
			if (key == arr[mid])
				return mid;
			else if (key < arr[mid])
				return RBinarySearch(low, mid - 1, key);
			else
				return RBinarySearch(mid + 1, high, key);
		}
		return -1;
	}


	//Sum Recursive Version
	//Return the sum of total size if 'i' is not specified
	//else return the value from 'i' to size
	int Sum(int i = 0)
	{
		//This is the wrapper fucntion for sum
		if (i >= 0 && i < size)
		{
			return Sum(0, i);
		}
		return 0;
	}

	int Sum(T total, int i)
	{
		if (i < size)
		{	
			return total = Sum(total + arr[i], i + 1);;
		}
		return total;
	}


	//Get
	//Return the value at a specified index
	T Get(int index)
	{
		if (index >= 0 && index < size)
			return arr[index];
		return -1;
	}


	//Set
	//Sets the value at a specified index
	void Set(int index, const T& value)
	{
		if (index >= 0 && index < size)
			arr[index] = value;
	}

	//Max
	//Return the maximum of an array
	T Max()
	{
		T max = arr[0];
		for (int i = 1; i < size; i++)
			if (arr[i] > max)
				max = arr[i];
		return max;
	}


	//Min
	//Return the minimum of an array
	T Min()
	{
		T min = arr[0];
		for (int i = 1; i < size; i++)
			if (arr[i] < min)
				min = arr[i];
		return min;
	}


	//Average
	//Return the average of an array
	T Avg()
	{
		T sum = this->Sum(0, 0);
		return (sum / size);
	}


	//Reverse
	//Reverses an array
	void Reverse()
	{
		int i = 0, j = this->size - 1;
		while (i < j)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}


	//Rotations
	//Left Rotation
	void LeftRotation(const int &times)
	{
		for (int i = 0; i < times; i++)
		{
			T temp = arr[0];
			for (int j = 0; j < this->size; j++)
			{
				arr[j] = arr[j + 1];
				if (j == size - 1)
					arr[j] = temp;
			}
		}
	}


	//Right Rotation
	void RightRotation(const int& times)
	{
		for (int i = 0; i < times; i++)
		{
			T temp = arr[size - 1];
			for (int j = size - 1; j >= 0; j--)
			{
				arr[j] = arr[j - 1];
				if (j == 0)
					arr[j] = temp;
			}
		}
	}


	//Shifting
	//Left Shift
	void LeftShift(const int& times)
	{
		for (int i = 0; i < times; i++)
			for (int j = 0; j < this->size; j++)
			{
				arr[j] = arr[j + 1];
				if (j == size - 1)
					arr[j] = NULL;
			}
	}


	//Right Shift
	void RightShift(const int& times)
	{
		for (int i = 0; i < times; i++)
		{
			for (int j = size - 1; j >= 0; j--)
			{
				arr[j] = arr[j - 1];
				if (j == 0)
					arr[j] = NULL;
			}
		}
	}


	//Sorting
	//Sorts the array from the specified index
	//If index isn't specidifed, sorts from 0
	void Sort(const int &index = 0)
	{
		for (int i = index; i < size; i++)
			for (int j = i + 1; j < size; j++)
				if (arr[i] > arr[j])
					swap(arr[i], arr[j]);
	}


	//Is Sorted
	//Return true if the array is sorted
	//else returns false
	bool IsSorted()
	{
		for (int i = 0; i < size; i++)
		{
			if (i == size - 1)
				return true;
			if (arr[i] > arr[i + 1])
				return false;
		}
		return true;
	}


	 //Merging
	//Merges two arrays also sorts them if the flag is true
	static array_ADT Merg(const array_ADT &obj1, const array_ADT &obj2, bool flag = false)
	{
		//We need a 3rd array to merge these two arrays
		array_ADT obj3((obj1.capacity + obj2.capacity));

		//Copying from 1st array
		for (int i = 0; i < obj1.size; i++)
			obj3.insert(obj1.arr[i]);

		for (int i = 0; i < obj2.size; i++)
			obj3.insert(obj2.arr[i]);


		if (flag == true)
			obj3.Sort();

		return obj3;
	}

	//Destructor
	~array_ADT()
	{
		cout << "~array_ADT() called" << endl;
		delete[] this->arr;
		this->size = this->capacity = 0;
	}
};