

#include <iostream>
using namespace std;
#include "sparse_matrix.h"



int main()
{
    sparse_matrix mat1("./mat1.txt"); //parameterized constructor
    sparse_matrix mat3("./mat0.txt");
    sparse_matrix mat4("./mat4.txt");
    sparse_matrix mat5("./mat0.txt");
    sparse_matrix mat6("./mat0.txt");
    sparse_matrix mat7("./mat0.txt");
    sparse_matrix mat8("./mat8.txt");
    sparse_matrix mat9("./mat9.txt");
    sparse_matrix mat10("./mat10.txt");
    sparse_matrix mat11("./mat11.txt");
    sparse_matrix mat12("./mat12.txt");

    cout << "Parameterized Constructor mat1:\n";
    mat1.PrintMatrix();
    cout << endl
        << endl;

    sparse_matrix mat2(mat1); //copy constructor
    cout << "Copy Constructor mat2:\n";
    mat2.PrintMatrix();
    cout << endl
        << endl;

    mat3 = mat2;
    cout << "Assignment operator mat3:\n";
    mat3.PrintMatrix();
    cout << endl
        << endl;

    cout << boolalpha;
    cout << "mat3 is equal to mat2: " << (mat3 == mat2) << endl
        << endl;

    //cout << boolalpha;
    cout << "mat3 is equal to mat8: " << (mat3 == mat8) << endl
        << endl;

    mat5 = mat4 + mat1;
    cout << "Sum of mat4 and mat1:\n";
    mat5.PrintMatrix();
    cout << endl
        << endl;

    mat6 = mat9.transpose();
    cout << "Transpose of mat9:\n";
    mat6.PrintMatrix();
    cout << endl
        << endl;

    mat7 = mat9 * mat10;
    cout << " Product of mat9 and mat10:\n";
    mat7.PrintMatrix();
    cout << endl
        << endl;

    cout << boolalpha;
    cout << "mat8 is in mat9: " << mat9.isSubMatrix(mat8) << endl
        << endl;

    cout << boolalpha;
    cout << "mat11 is in mat9: " << mat9.isSubMatrix(mat11) << endl
        << endl;

    cout << boolalpha;
    cout << "mat12 is in mat9: " << mat9.isSubMatrix(mat12) << endl
        << endl;
}
