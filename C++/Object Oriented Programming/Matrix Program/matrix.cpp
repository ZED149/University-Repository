


#include <iostream>
#include <Windows.h>
#include "matrix.h"
using namespace std;



//Definitions

/******************************************************** Constructors *******************************************************************/


//Constructor with params
matrix::matrix(double **arr, unsigned int rows, unsigned int cols)
{
	this->rows = rows;
	this->cols = cols;

	//allocating memory
	this->arr = new double*[rows];
	for (int i = 0; i < this->rows; i++)
		this->arr[i] = new double[cols];

	//cout << "Constructor with params is called" << endl;
}//constructor with param

//Copy Constructor
matrix::matrix(const matrix &obj)
{
	this->rows = obj.rows;
	this->cols = obj.cols;

	//allocating memory
	this->arr = new double*[rows];
	for (int i = 0; i < rows; i++)
		this->arr[i] = new double[cols];

	//copying with deep value
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			this->arr[i][j] = obj.arr[i][j];
	}//for

	//cout << "Copy Constructor is called" << endl;
}//copy constructor


/******************************************************** Destructors *******************************************************************/
matrix::~matrix()
{
	if (this->arr != nullptr)
	{
		for (int i = 0; i < this->rows; i++)
			delete[] this->arr[i];
		delete[] this->arr;
	}

	this->arr = nullptr;
	this->rows = this->cols = 0;

	//cout << "Destructor is called" << endl;
}


/******************************************************** Member Functions *******************************************************************/

//Order Equal
bool matrix::OrderEqual(const matrix &obj)const
{
	bool flag = true;

	if (this->rows == obj.rows && this->cols == obj.cols)
		flag = true;
	else
		flag = false;

	return flag;
}//order equal

//Tranpose
matrix matrix::tranpose()const
{
	matrix R(NULL, this->cols, this->rows);
	for (int i = 0; i < this->cols; i++)
		for (int j = 0; j < this->rows; j++)
			R.arr[i][j] = this->arr[j][i];

	return R;
}//transpose

//Power
void matrix::power(const int power)
{
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			this->arr[i][j] = pow(this->arr[i][j], power);
}//power


/******************************************************** Overloaded Operators *******************************************************************/

//Insertion Operator '<<'
ostream& operator << (ostream &out, const matrix &obj)
{
	for (int i = 0; i < obj.rows; i++)
	{
		for (int j = 0; j < obj.cols; j++)
			out << obj.arr[i][j] << " ";
		out << endl;
	}//for

	return out;
}//insertion operator

//Extraction Operator '>>'
istream& operator >> (istream &in, matrix &obj)
{
	for (int i = 0; i < obj.rows; i++)
	{
		for (int j = 0; j < obj.cols; j++)
			in >> obj.arr[i][j];
	}//for

	return in;
}//extraction operator

//Assigment Operator '='
matrix& matrix::operator = (const matrix &obj)
{
	//checking if caller obj already has some memory allocated on heap
	if (this->arr)
	{
		for (int i = 0; i < this->rows; i++)
			delete[] this->arr[i];
		delete[] this->arr;
	}

	this->rows = obj.rows;
	this->cols = obj.cols;

	//allocating memory
	this->arr = new double*[this->rows];
	for (int i = 0; i < this->rows; i++)
		this->arr[i] = new double[cols];

	//copying values
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
			this->arr[i][j] = obj.arr[i][j];
	}//for

	cout << "Assigment Operator is called" << endl;

	return *this;

}//assigment operator

//Equal Operator Operator '=='
bool matrix::operator == (const matrix &obj)const
{
	bool flag = true;

	if (this->rows == obj.rows && this->cols == obj.cols)
	{
		for (int i = 0; i < this->rows; i++)
			for (int j = 0; j < this->cols; j++)
				if (this->arr[i][j] != obj.arr[i][j])
					flag = false;
	}
	else
		flag = false;

	return flag;
}//addition operator

//Not Equal Operator '!='
bool matrix::operator != (const matrix &obj)const
{
	return !((*this).operator==(obj));
}//not equal operator

//Addition Operator '+' (Matrix with Matrix i.e (A + A))
matrix matrix::operator + (const matrix &obj)const
{
	if (this->OrderEqual(obj) == 1)
	{
		matrix R(NULL, this->rows, this->cols);

		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
				R.arr[i][j] = this->arr[i][j] + obj.arr[i][j];
		}//for

		return R;
	}
	else
	{
		matrix R;
		cout << "Cant add matrices" << endl;
		return R;
	}
}//addtion operator	(matrix with matrix i.e (A + A))

//Addition Operator '+' (Matrix with Scalar i.e (A + Constant))
matrix matrix::operator + (const double scalar)
{
	//creating a new matrix of this->rows and this->cols
	double **temp = new double*[this->rows];
	for (int i = 0; i < this->rows; i++)
		temp[i] = new double[this->cols];

	//initializing **temp with the scalar value
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			temp[i][j] = scalar;

	//adding scalar into matrix
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			this->arr[i][j] = this->arr[i][j] + temp[i][j];

	//deallcating memory of temp
	for (int i = 0; i < this->rows; i++)
		delete[] temp[i];
	delete[] temp;

	return *this;
}////addtion operator	(matrix with scalar i.e (A + Constant))

//Multiplication Operator '*' (Matrix with Scalar i.e (A * Constant))
matrix matrix::operator * (const double scalar)const
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
			this->arr[i][j] = this->arr[i][j] * scalar;
	}//for

	return *this;
}//multiplication operator (matrix with scalar i.e (A * Constant))

//Multiplication Operator '*' (Matrix with Matrix i.e (A * A))
matrix matrix::operator * (const matrix &obj)const
{
	matrix R(NULL, this->rows, this->cols);

	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			for (int k = 0; k < this->rows; k++)
				R.arr[i][j] = this->arr[i][k] * obj.arr[k][j];
		}//for
	}//for

	return R;
}//matrix operator	(matrix with matrix i.e (A * A))

//Subtraction Operator '-' (Matrix with Matrix i.e (A - A))
matrix matrix::operator - (const matrix &obj)const
{
	if (this->operator==(obj))
	{
		matrix R(NULL, this->rows, this->cols);

		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
				R.arr[i][j] = this->arr[i][j] - obj.arr[i][j];
		}//for

		return R;
	}
	else
	{
		matrix R;
		cout << "Cant Subtract Matrices" << endl;
		return R;
	}
}//subtraction operator (matrix with matrix i.e (A - A))

//Subtraction Operator '-' (Matrix with Scalar i.e (A - Constant))
matrix matrix::operator - (const double scalar)
{
	//creating a new matrix of this->rows and this->cols
	double **temp = new double*[this->rows];
	for (int i = 0; i < this->rows; i++)
		temp[i] = new double[this->cols];

	//initializing **temp with the scalar value
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			temp[i][j] = scalar;

	//subtracting scalar into matrix
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			this->arr[i][j] = this->arr[i][j] - temp[i][j];

	//deallcating memory of temp
	for (int i = 0; i < this->rows; i++)
		delete[] temp[i];
	delete[] temp;

	return *this;
}//subtraction operator (matrix with scalar i.e (A - Constant))

//Increment Operator '++'
//* Pre-Increment Operator	'++A'
matrix matrix::operator ++ ()
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
			this->arr[i][j] = this->arr[i][j] + 1;
	}//for

	return *this;
}//pre increment

//* Post-Increment	'A++'
matrix matrix::operator ++ (const int dummy)
{
	matrix temp = *this;

	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
			this->arr[i][j] = this->arr[i][j] + 1;
	}//for

	return temp;
}//post increment

//Decrement Operator '--'
//* Pre-Decrement Operator	'--A;
matrix matrix::operator -- ()
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
			this->arr[i][j] = this->arr[i][j] - 1;
	}//for

	return *this;
}//pre decrement operator

//* Post Decrement Operator	'A--'
matrix matrix::operator -- (const int dummy)
{
	matrix temp = *this;

	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
			this->arr[i][j] = this->arr[i][j] - 1;
	}//for

	return temp;
}//post decrement operator

//Addition and Equal Operator	'+='	(Matrix with Scalar i.e (A += Constant))
matrix matrix::operator += (const double scalar)
{
	//creating a new matrix of this->rows and this->cols
	double **temp = new double*[this->rows];
	for (int i = 0; i < this->rows; i++)
		temp[i] = new double[this->cols];

	//initializing **temp with the scalar value
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			temp[i][j] = scalar;

	//adding scalar into matrix
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			this->arr[i][j] = this->arr[i][j] + temp[i][j];

	//deallcating memory of temp
	for (int i = 0; i < this->rows; i++)
		delete[] temp[i];
	delete[] temp;

	return *this;
}//addition and equal operator	(matrix with scalar i.e (A += Constant))

//Addition and Equal Operator	'+='	(Matrix with Matrix i.e (A += A))
matrix matrix::operator += (const matrix &obj)
{
	if (this->OrderEqual(obj))
	{
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
				this->arr[i][j] = this->arr[i][j] + obj.arr[i][j];
		}//for

		return *this;
	}
	else
	{
		cout << "Can't Add because size is of matrices is not same" << endl;
		return *this;
	}
}//addition and equal operator (matrix with matrix i.e (A += A))

//Subtraction and Equal Operator	'-='	(Matrix with Scalar i.e (A -= Constant))
matrix matrix::operator -= (const double scalar)
{
	//creating a new matrix of this->rows and this->cols
	double **temp = new double*[this->rows];
	for (int i = 0; i < this->rows; i++)
		temp[i] = new double[this->cols];

	//initializing **temp with the scalar value
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			temp[i][j] = scalar;

	//subtracting scalar into matrix
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			this->arr[i][j] = this->arr[i][j] - temp[i][j];

	//deallcating memory of temp
	for (int i = 0; i < this->rows; i++)
		delete[] temp[i];
	delete[] temp;

	return *this;
}//subtraction and equal operator (matrix with scalar i.e (A - Constant))

//Subtraction and Equal Operator	'-='	(Matrix with Matrix i.e (A -= A))
matrix matrix::operator -= (const matrix &obj)
{
	if (this->operator==(obj))
	{
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
				this->arr[i][j] = this->arr[i][j] - obj.arr[i][j];
		}//for

		return *this;
	}
	else
	{
		cout << "Can't Subtract because size is of matrices is not same" << endl;
		return *this;
	}
}

//Multiplication and Equal Operator '*=' (Matrix with Scalar i.e (A *= Constant))
matrix matrix::operator *= (const double scalar)
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
			this->arr[i][j] = this->arr[i][j] * scalar;
	}//for

	return *this;
}//multiplication and equal operator '*=' (matrix with scalar i.e (A *= Constant))

//Multiplication and Equal Operator '*=' (Matrix with Matrix i.e (A *= A))
matrix matrix::operator *= (const matrix &obj)
{
	matrix R(NULL, this->rows, this->cols);

	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			for (int k = 0; k < this->rows; k++)
				R.arr[i][j] = this->arr[i][k] * obj.arr[k][j];
		}//for
	}//for

	return R;
}//multiplication and equal operator '*=' (matrix with matrix i.e (A *= A))

//Divide and Equal Operator '/=' (Matrix with Scalar i.e (A/=Scalar))
matrix matrix::operator /= (const double scalar)
{
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			this->arr[i][j] = this->arr[i][j] / scalar;

	return *this;
}

//New Operator without value 'new'
void* matrix::operator new (const size_t size)
{
	cout << "Size of matrix bytes is: " << size << endl;
	void *p = malloc(size);
	return p;
}//new operator without value

//New Operator with value 'new'
void * matrix::operator new (const size_t size, int value)
{
	cout << "New operator with value and size is " << size << endl;
	void *p = malloc(size);
	//or
	//p = malloc(size);
	if (p != nullptr)
	{
		//we have to de-reference and give our pointer some type
		//as we can't assign some value to void pointer
		*static_cast<double *>(p) = value;
	}
	return p;
}//new operator with value

//Delete Operator 'delete'
void matrix::operator delete (void * p)
{
	cout << "Overloaded delete operator is called" << endl;
	free(p);
}//delete operator

//New [] Operator without value 'new[]'
void* matrix::operator new [](size_t size)
{
	void *p = malloc(size);
	return p;
}//new [] operator without value

//New [] Operator with value 'new[]'
void * matrix::operator new [](size_t size, const int value)
{
	void *p = malloc(size);
	if (p != nullptr)
		*static_cast<int *>(p) = value;
	return p;
}//new [] operator with value

//Delete Operator 'delete[]'
void matrix::operator delete [](void * p)
{
	free(p);
}//delete [] operator

//Invoke Operator '()'
double matrix::operator () (const int i, const int j)
{
	if (i <= this->rows && j <= this->cols)
		return this->arr[i][j];
	else
	{
		cout << "Invalid values for Invoke Operator" << endl;
		return 0;
	}
}//invoke operator