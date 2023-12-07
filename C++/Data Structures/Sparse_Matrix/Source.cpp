//
//
//
//
//#include <iostream>
//#include "sparse_matrix.h"
//using namespace std;
//
//
//
//int main()
//{
//	//{
//	//	sparse_matrix obj;
//	//	obj.read("./readFile.txt");
//	//	cout << obj;
//
//	//	cout << "Test Copy constructor" << endl;
//	//	sparse_matrix obj1 = obj;
//	//	cout << obj1;
//
//
//	//	cout << "Test Assignment Operator" << endl;
//	//	sparse_matrix obj3;
//	//	obj3 = obj;
//	//	cout << obj3;
//	//	sparse_matrix obj4("./readFile_2.txt");
//	//	cout << "Obj 4 is: \n";
//	//	cout << obj4;
//	//	cout << endl;
//
//	//	cout << "Obj3 is: " << endl;
//	//	obj3 = obj4;
//	//	cout << obj3;
//	//	//Checking Equal Operator
//	//	cout << "-------------------------------------------" << endl;
//	//	cout << "obj3 and obj4 are: ";
//	//	if (obj3 == obj4)
//	//		cout << "Equal" << endl;
//	//	else if (!(obj3 == obj4))
//	//		cout << "Not Equal" << endl;
//	//	cout << "--------------------" << endl;
//	//	cout << "Obj3 is: " << endl;
//	//	obj3 = obj;
//	//	cout << obj3;
//
//
//	//	//Checking Equal Operator
//	//	cout << "-------------------------------------------" << endl;
//	//	cout << "obj3 and obj4 are: ";
//	//	if (obj3 == obj4)
//	//		cout << "Equal" << endl;
//	//	else if (!(obj3 == obj4))
//	//		cout << "Not Equal" << endl;
//
//
//
//	//	//Now checking Addition Operator
//	//	cout << "obj3 + obj3 is: " << endl;
//	//	obj3 = obj3 + obj3;
//	//	cout << obj3;
//
//	//	cout << "----------------------------------" << endl;
//	//	cout << "obj3 + obj4 is: " << endl;
//	//	sparse_matrix obj5;
//	//	obj4 = obj4 + obj4;
//	//	cout << obj4;
//
//	//	cout << "--------------------------------" << endl;
//	//	obj5 = obj4;
//	//	cout << "Obj5 is: " << endl;
//	//	cout << obj5;
//	//}
//	///*system("pause");*/
//
//
//	//sparse_matrix obj("./readFile.txt");
//	//cout << "Before Transpose obj is: " << endl;
//	//cout << obj << endl;
//	//cout << "After transpose obj is: " << endl;
//	//obj.transpose();
//	//cout << obj << endl;
//	//cout << "Again Transpose of obj is: " << endl;
//	//obj.transpose();
//	//cout << obj;
//
//
//
//	////Code of sub Matrix
//	//sparse_matrix ori_matrix("./subMatrix_2.txt");
//	//sparse_matrix sub_matrix("./subMatrix.txt");
//
//	////cout << ori_matrix << sub_matrix << endl;
//	//cout << ori_matrix.isSubMatrix(sub_matrix);
//
//
//	////Plus Operator Again Check
//	//sparse_matrix obj("./plus1.txt"), obj1("./plus2.txt");
//
//	///*sparse_matrix obj2 = obj1 + obj;
//	//cout << obj2;*/
//	//cout << (obj + obj1);
//
//
//	////Checking Equal operator
//	//sparse_matrix obj("./SM1.txt"), obj1("./SM2.txt");
//	//cout << (obj == obj1) << endl;
//
//
//	////Checking Multiplay Operator
//	//sparse_matrix obj("./multiplay_1.txt"), obj1("./multiplay_2.txt");
//	//sparse_matrix obj3 = (obj * obj1);
//	//obj3.PrintMatrix();
//
//	sparse_matrix obj("./subMatrix_2.txt");
//	obj.PrintMatrix();
//	cout << endl << endl;
//	obj.transpose();
//	obj.PrintMatrix();
//}
//
//
//
////1 2 3 11
////0 0 1 0
////0 6 10 23
////0 0 1 5