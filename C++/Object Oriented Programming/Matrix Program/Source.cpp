


// assigment3.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "matrix.h"
#include <Windows.h>
#include "menu.h"
using namespace std;


int main()
{
	/*
	char s = '\0';
	int x, y, z, t;
	bool flag = true;
	bool flag1 = true;
	menu p;

	p.print();

	cout << "Enter the number of rows and columns for matrix A\n";
	cin >> x >> y;
	cout << "Enter the number of rows and columns for matrix B\n";
	cin >> z >> t;
	if (x < 0 || y < 0 || z < 0 || t < 0)
		flag1 = false;
	if (flag1 == true)	//enters if rows and cols are +ve
	{
		system("cls");
		do
		{
			cout << "Enter the character to perform specific operation\n";
			cin >> s;
			if (s == 'a')
			{
				matrix A(NULL, x, y);
				matrix B(NULL, z, t);
				cout << "Enter the values of matrix A\n";
				cin >> A;
				cout << "Enter the values of matrix B\n";
				cin >> B;
				cout << "A+B=\n" << A + B;
				cout << "Do you want to use any operation again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("cls");
					p.print();
					flag = true;
				}
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}
			}
			else if (s == 'A')
			{
				int k = 0;
				matrix A(NULL, x, y);
				cout << "Enter the values of matrix A\n";
				cin >> A;
				cout << "Enter the scalar for addition in  matrix\n";
				cin >> k;
				cout << "A+k=\n" << A + k;
				cout << "Do you want to use any operation again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("cls");
					p.print();
					flag = true;
				}
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}
			}
			else if (s == 'S')
			{
				matrix A(NULL, x, y);
				matrix B(NULL, z, t);
				cout << "Enter the values of matrix A\n";
				cin >> A;
				cout << "Enter the values of matrix B\n";
				cin >> B;
				cout << "A-B=\n" << A - B;
				cout << "Do you want to use any operation again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("cls");
					p.print();
					flag = true;
				}
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}
			}
			else if (s == 's')
			{
				int k = 0;
				matrix A(NULL, x, y);
				cout << "Enter the values of matrix A\n";
				cin >> A;
				cout << "Enter the scalar for addition in  matrix\n";
				cin >> k;
				cout << "A-k=\n" << A - k;
				cout << "Do you want to use any operation again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("cls");
					p.print();
					flag = true;
				}
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}

			}
			else if (s == 'M')
			{
				matrix A(NULL, x, y);
				matrix B(NULL, z, t);
				cout << "Enter the values of matrix A\n";
				cin >> A;
				cout << "Enter the values of matrix B\n";
				cin >> B;
				cout << "AXB=\n" << A * B << endl;
				cout << "Do you want to use any operation again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("cls");
					p.print();
					flag = true;
				}
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}
			}
			else if (s == 'm')
			{
				int k = 0;
				matrix A(NULL, x, y);
				cout << "Enter the values of matrix A\n";
				cin >> A;
				cout << "Enter the scalar for addition in  matrix\n";
				cin >> k;
				cout << "A*k=\n" << A * k << endl;
				cout << "Do you want to use any operation again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("cls");
					p.print();
					flag = true;
				}
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}
			}
			else if (s == 'E')
			{
				matrix A(NULL, x, y);
				matrix B(NULL, z, t);
				cout << "Enter the values of matrix A\n";
				cin >> A;
				cout << "Enter the values of matrix B\n";
				cin >> B;
				cout << "(A==B)=" << (A == B) << endl;
				cout << "Do you want to use any operation again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("cls");
					p.print();
					flag = true;
				}
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}
			}
			else if (s == 'e')
			{
				matrix A(NULL, x, y);
				matrix B(NULL, z, t);
				cout << "Enter the values for matrix A" << endl;
				cin >> A;
				cout << "Enter the values for matrix B" << endl;
				cin >> B;
				A = B;
				cout << "A assign B (A=B) is: " << A << endl;
				cout << "Do you want to use any operation again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("cls");
					p.print();
					flag = true;
				}
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}
			}
			else if (s == 'I')
			{
				matrix A(NULL, x, y);
				cout << "Enter the values for matrix A" << endl;
				cin >> A;
				cout << "Matrix A after pre-increment is: " << endl;
				++A;
				cout << A << endl;
				cout << "Do you want to use any operation again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("cls");
					p.print();
					flag = true;
				}
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}
			}
			else if (s == 'i')
			{
				matrix A(NULL, x, y);
				cout << "Enter the values for matrix A" << endl;
				cin >> A;
				cout << "Matrix A after post-increment is: " << endl;
				A--;
				cout << A << endl;
				cout << "Do you want to use any operation again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("cls");
					p.print();
					flag = true;
				}
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}
			}
			else if (s == 'D')
			{
				matrix A(NULL, x, y);
				cout << "Enter the values for matrix A" << endl;
				cin >> A;
				cout << "Matrix A after pre-decrement is: " << endl;
				--A;
				cout << A << endl;
				cout << "Do you want to use any operation again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("cls");
					p.print();
					flag = true;
				}
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}
			}
			else if (s == 'd')
			{
				matrix A(NULL, x, y);
				cout << "Enter the values for matrix A" << endl;
				cin >> A;
				cout << "Matrix A after post-decrement is: " << endl;
				A--;
				cout << A << endl;
				cout << "Do you want to use any operation again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("cls");
					p.print();
					flag = true;
				}
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}
			}
			else if (s == '1')
			{
				matrix A(NULL, x, y);
				matrix B(NULL, z, t);
				cout << "Enter the values for matrix A" << endl;
				cin >> A;
				cout << "Enter the values for matrix B" << endl;
				cin >> B;
				cout << "Answer after A+=B is: " << endl;
				A += B;
				cout << A;
				cout << "Do you want to use any operation again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("cls");
					p.print();
					flag = true;
				}
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}
			}
			else if (s == '2')
			{
				matrix A(NULL, x, y);
				double scalar = 0;
				cout << "Enter the values for matrix A" << endl;
				cin >> A;
				cout << "Enter the value for scalar to be added to A" << endl;
				cin >> scalar;
				cout << "Answer after A+=Scalar is: " << endl;
				cout << (A += scalar);
				cout << "Do you want to use any operation again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("cls");
					p.print();
					flag = true;
				}
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}
			}
			else if (s == '3')
			{
				matrix A(NULL, x, y);
				matrix B(NULL, z, t);
				cout << "Enter the values for matrix A" << endl;
				cin >> A;
				cout << "Enter the values for matrix B" << endl;
				cin >> B;
				cout << "Answer after A-=B is: " << endl;
				cout << (A -= B);
				cout << "Do you want to use any operation again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("cls");
					p.print();
					flag = true;
				}
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}
			}
			else if (s == '4')
			{
				matrix A(NULL, x, y);
				double scalar = 0;
				cout << "Enter the values for matrix A" << endl;
				cin >> A;
				cout << "Enter the value for scalar to be subtracted from A" << endl;
				cin >> scalar;
				cout << "Answer after A-=Scalar is: " << endl;
				cout << (A -= scalar);
				cout << "Do you want to use any operation again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("cls");
					p.print();
					flag = true;
				}
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}
			}
			else if (s == '5')
			{
				matrix A(NULL, x, y);
				matrix B(NULL, z, t);
				cout << "Enter the values for matrix A" << endl;
				cin >> A;
				cout << "Enter the values for matrix B" << endl;
				cin >> B;
				cout << "Answer after A*=B is: " << endl;
				cout << (A *= B);
				cout << "Do you want to use any operation again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("cls");
					p.print();
					flag = true;
				}
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}
			}
			else if (s == '6')
			{
				matrix A(NULL, x, y);
				double scalar = 0;
				cout << "Enter the values for matrix A" << endl;
				cin >> A;
				cout << "Enter the value for scalar to be multiplied to A" << endl;
				cin >> scalar;
				cout << "Answer after A*=Scalar is: " << endl;
				cout << (A *= scalar);
				cout << "Do you want to use any operation again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("cls");
					p.print();
					flag = true;
				}
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}
			}
			else if (s == '7')
			{
				matrix A(NULL, x, y);
				double scalar = 1;
				cout << "Enter the values for matrix A" << endl;
				cin >> A;
				cout << "Enter the value to be divided with A" << endl;
				cin >> scalar;
				cout << "Answer after A/=Scalar is: " << endl;
				cout << (A /= scalar);
				cout << "Do you want to use any operation again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("cls");
					p.print();
					flag = true;
				}
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}
			}
			else if (s == 'n')
			{
				matrix *A = new matrix(NULL, x, y);
				cout << "Enter values for matrix A allocated on heap" << endl;
				cin >> *A;
				cout << "Values for matrix A are: " << endl;
				cout << *A;
				delete A;
				cout << "Do you want to use any operation again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("cls");
					p.print();
					flag = true;
				}
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}
			}
			else if (s == 'N')
			{
				matrix *A = new matrix[2]{ matrix(NULL, x, y), matrix(NULL, z, t) };
				cout << "Enter values for matrix A[0] allocated on heap" << endl;
				cin >> A[0];
				cout << "Enter values for matrix A[1] allocated on heap" << endl;
				cin >> *(A + 1);
				cout << "Matrix A is: " << endl;
				cout << A[0];
				cout << "Matrix B is: " << endl;
				cout << A[1];
				delete[] A;
				cout << "Do you want to use any operation again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("cls");
					p.print();
					flag = true;
				}
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}
			}
			else if (s == 'c')
			{
				matrix A(NULL, x, y);
				cout << "Enter values for matrix A" << endl;
				cin >> A;
				cout << "Enter indexes for Funtion Call operator ()" << endl;
				int i = 0, j = 0;
				cout << "Enter i" << endl;
				cin >> i;
				cout << "Enter j" << endl;
				cin >> j;
				cout << (A(i, j));
				cout << "Do you want to use any operation again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("cls");
					p.print();
					flag = true;
				}
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}
			}
			else if (s == 'T')
			{
				matrix A(NULL, x, y);
				cout << "Enter values for matrix A" << endl;
				cin >> A;
				cout << "Matrix A after transpose is: " << endl;
				A.tranpose();
				cout << A;
				cout << "Do you want to use any operation again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("cls");
					p.print();
					flag = true;
				}
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}
			}
			else if (s == 'P')
			{
				matrix A(NULL, x, y);
				cout << "Enter values for matrix A" << endl;
				cin >> A;
				cout << "Enter value for power of A" << endl;
				int power = 0;
				cin >> power;
				cout << "Matrix A after calculating power is: " << endl;
				A.power(power);
				cout << A;
				cout << "Do you want to use any operation again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
				{
					system("cls");
					p.print();
					flag = true;
				}
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}
			}
			else
			{
				cout << "Invalid Input";
				cout << "Do you want to use any opertion again? [Y/N]" << endl;
				char again;
				cin >> again;
				if (again == 'Y' || again == 'y')
					flag = true;
				else
				{
					cout << "Program is terminating" << endl;
					Sleep(1000);
					flag = false;
				}
			}
		} while (flag == true);

		if (flag == false)
			flag1 = false;
	}
	else
		cout << "Rows or columns cannot be negative\n";



	*/

matrix a(NULL, 2, 3);
cin >> a;
cout << a;
a.tranpose();
cout << a;
system("pause");

	return 0;
}