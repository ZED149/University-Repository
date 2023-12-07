#pragma once



#pragma once

#include <iostream>
#include <Windows.h>
using namespace std;


class menu
{
public:
	void print();
};



//defintion
void::menu::print()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);	//violet
	cout << "Menu is: " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//white
	cout << "For Addition of matrix to matrix i.e (M+M), press A" << endl;
	cout << "For Addition of matrix to scalar i.e (M+Scalar), press a" << endl;
	cout << "For Subtraction of matrix to matrix i.e (M-M), press S" << endl;
	cout << "For Subtraction of matrix to scalar i.e (M-Scalar), press s" << endl;
	cout << "For Multiplication of matrix to matrix i.e (M*M), press M" << endl;
	cout << "For Multiplication of matrix to scalar i.e (M*Scalar), press m" << endl;
	cout << "For Equlivalent Operator i.e (M==m), press E" << endl;
	cout << "For Assignment Operator i.e (M=m), press e" << endl;
	cout << "For Pre-Increment Operator i.e (++M), press I" << endl;
	cout << "For Post-Increment Operator i.e (M++), press i" << endl;
	cout << "For Pre-Decrement Operator i.e (--M), press D" << endl;
	cout << "For Post-Decrement Operator i.e (M--), press d" << endl;
	cout << "For Add Equal Operator i.e matrix to matrix (M+=M), press 1" << endl;
	cout << "For Add Equal Operator i.e matrix to scalar (M+=Scalar), press 2" << endl;
	cout << "For Subtraction Equal Operator i.e matrix to matrix (M-=M), press 3" << endl;
	cout << "For Subtraction Equal Operator i.e matrix to matrix (M-=Scalar), press 4" << endl;
	cout << "For Multiplay Equal Operator i.e matrix to matrix (M*=M), press 5" << endl;
	cout << "For Multiplay Equal Operator i.e matrix to scalar (M*=Scalar), press 6" << endl;
	cout << "For Divide Equal Operator i.e matrix to scalar (M/=Scalar), press 7" << endl;
	cout << "For new Operator i.e matrix *a=new matrix, press n" << endl;
	cout << "For new[] Operator i.e matrix *a=new matrix[2], press N" << endl;
	cout << "For Function Call Operator i.e A(i,j), press C" << endl;
	cout << "For Tranpose Function, press T" << endl;
	cout << "For Power Function, press P" << endl;
}//print