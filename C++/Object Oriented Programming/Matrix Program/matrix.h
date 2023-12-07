
#pragma once





class matrix
{
	double **arr;
	int rows, cols;

	//Overloaded Stream Operatros

	//Insertion Operator
	friend std::ostream& operator << (std::ostream &out, const matrix &obj);

	//Extraction Operator
	friend std::istream& operator >> (std::istream &in, matrix &obj);

public:

	/******************************************************** Constructors *******************************************************************/

	//Constructor with params
	matrix(double **arr = nullptr, unsigned int rows = 0, unsigned int cols = 0);

	//Copy Constructor
	matrix(const matrix &obj);

	/******************************************************** Destructors *******************************************************************/
	~matrix();

	/******************************************************** Member Functions *******************************************************************/
	bool OrderEqual(const matrix &obj)const;
	matrix tranpose()const;
	void power(const int power);

	/******************************************************** Overloaded Operators *******************************************************************/

	//Assigment Operator '='
	matrix& operator = (const matrix &obj);

	//Equal Operator '=='
	bool operator == (const matrix &obj)const;

	//Not Equal Operator '!='
	bool operator != (const matrix &obj)const;

	//Addition Operator	'+'	(Matrix with Matrix i.e (A + A))
	matrix operator + (const matrix &obj)const;

	//Addition Operator '+' (Matrix with Scalar i.e (A + Constant))
	matrix operator + (const double scalar);

	//Multiplication Operator '*' (Matrix with Scalar i.e (A * Constant))
	matrix operator * (const double scalar)const;

	//Multiplication Operator '*' (Matrix with Matrix i.e (A * A))
	matrix operator * (const matrix &obj)const;

	//Subtraction Operator	'-'	(Matrix with Matrix i.e (A - A))
	matrix operator - (const matrix &obj)const;

	//Subtraction Operator '-' (Matrix with Scalar i.e (A - Constant))
	matrix operator - (const double scalar);

	//Increment Operator '++'
	//* Pre-Increment Operator '++A'
	matrix operator ++ ();

	//* Post Increment Operator 'A++'
	matrix operator ++(const int dummy);

	//Decrement Operator '--'
	//* Pre-Decrement Operator '--A'
	matrix operator -- ();

	//Pre-Decrement Operator 'A++'
	matrix operator --(const int dummy);

	//Addition and Equal Operator '+='	(Matrix with Scalar i.e (A += Constant))
	matrix operator += (const double scalar);

	//Addition and Equal Operator	'+='	(Matrix with Matrix i.e (A += A))
	matrix operator +=(const matrix &obj);

	//Subtraction and Equal Operator	'-+' (Matrix with Scalar i.e (A -= Constant))
	matrix operator -= (const double scalar);

	//Subtraction and Equal Operator	'-+' (Matrix with Matrix i.e (A -= A))
	matrix operator -= (const matrix &obj);

	//Multiplication and Equal Operator '*=' (Matrix with Scalar i.e (A *= Constant))
	matrix operator *= (const double scalar);

	//Multiplication and Equal Operator '*=' (Matrix with Matrix i.e (A *= A))
	matrix operator *= (const matrix &obj);

	//Divide and Equal Operator '/=' (Matrix with Scalar i.e (A/=Scalar))
	matrix operator /= (const double scalar);

	//New Operator without value 'new'
	void * operator new (const size_t size);

	//New Operator with value 'new'
	void * operator new (const size_t size, const int value);

	//Delete Operator 'delete'
	void operator delete (void * p);

	//New [] Operator without value
	void * operator new[](size_t size);

	//New [] Operator with value
	void * operator new[](size_t size, const int value);

	//Delete [] Operator
	void operator delete[](void * p);

	//Invoke Operator '()'
	double operator () (const int i, const int j);
};