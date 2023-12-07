
#pragma once



#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class sparse_matrix
{
	//Node Class
	typedef struct node
	{
		int value;
		int colIndex;
		node* nextInRow;
		int size;
		//Constructor
		node(int value, int colIndex, node* nextPtr) :
			value(value), colIndex(colIndex), nextInRow(nextPtr) {size = 0;}
	}* nodePtr;

	//Utility Functions
	//Add Node
	void addNode(nodePtr &head, const int &value, int colIndex, int i)
	{
		this->rowList[i]->size++;
		nodePtr curr = head;
		while (curr->nextInRow != nullptr) {curr = curr->nextInRow; }
		nodePtr temp = new node(value, colIndex, nullptr);
		curr->nextInRow = temp;
	}

	//Add Node by pointer
	void addNode(nodePtr &head, const nodePtr& curr, int i)
	{
		this->rowList[i]->size++;
		nodePtr iter = head;
		while (iter->nextInRow != nullptr) { iter = iter->nextInRow; }
		nodePtr temp = new node(curr->value, curr->colIndex, nullptr);
		iter->nextInRow = temp;
	}

	//Add Node by Rows and Cols
	void addNode(const int row, const int col, const int &value, sparse_matrix &obj)
	{
		this->rowList[row]->size++;
		nodePtr curr = obj.rowList[row];
		while (curr->nextInRow != nullptr) { curr = curr->nextInRow; }
		nodePtr temp = new node(value, col, nullptr);
		curr->nextInRow = temp;
	}


	//Add Node only for Read Function
	void addNode(const int value, const int col, nodePtr &curr, int i)
	{
		//This function is specially overloaded for read function
		//Its because by using this we don't have to always go at end 
		//to insert data. We can do it just by passing non zero entries
		//and appending it to each other as data 
		this->rowList[i]->size++;
		if (this->rowList[i]->nextInRow == nullptr)
		{
			//If row has no value
			curr = this->rowList[i];
		}
		curr->nextInRow = new node(value, col, nullptr);
		curr = curr->nextInRow;
	}


	//Delete Node
	void delNode(nodePtr &curr)
	{
		nodePtr temp = curr;
		curr = curr->nextInRow;
		delete temp;
	}

	//Private Data Members of class Sparse Matrix
	int M, N;	//Dimensions
	vector<nodePtr> rowList;


public:	//This is where the member goes
	//Constructor
	//Constructor with Default Parameters
	sparse_matrix(int M = 0, int N = 0)
	{
		this->M = M;
		this->N = N;
	}

	//Constructor with Parameters
	//Reads data from a given file
	sparse_matrix(string filename)
	{
		//Simply uses read to read from a file
		this->read(filename);
	}

	//Copy Constructor
	sparse_matrix(const sparse_matrix& obj)
	{
		this->M = obj.M;
		this->N = obj.N;


		//This loop will read from obj and copies to this
		nodePtr curr = nullptr;
		for (int i = 0; i < obj.rowList.size(); i++)
		{
			this->rowList.push_back(new node(-1, 0, nullptr));	//Head of row list
			curr = obj.rowList[i]->nextInRow;
			while (curr != nullptr)
			{
				this->addNode(rowList[i], curr, i);
				curr = curr->nextInRow;
			}
		}
	}


	//Operator Overloading
	//ASsignment Operator
	const sparse_matrix& operator = (const sparse_matrix& obj)
	{
		//Condition to check if the caller function already has smoe allocated memory
		if (!this->rowList.empty())
		{
			nodePtr curr = nullptr;
			for (int i = 0; i < this->rowList.size(); i++)
			{
				curr = rowList[i];
				while (curr != nullptr)
					delNode(curr);
			}
			this->rowList.clear();
		}

		this->M = obj.M;
		this->N = obj.N;


		//This loop will read from obj and copies to this
		nodePtr curr = nullptr;
		for (int i = 0; i < obj.rowList.size(); i++)
		{
			this->rowList.push_back(new node(-1, 0, nullptr));	//Head of row list
			curr = obj.rowList[i]->nextInRow;
			while (curr != nullptr)
			{
				this->addNode(rowList[i], curr, i);
				curr = curr->nextInRow;
			}
		}

		return *this;
	}


	//Equal Operator
	bool operator == (const sparse_matrix& obj) const
	{
		//First we need to check for dimensions
		if (this->M == obj.M && this->N == obj.N)
		{
			//Rows and Columns are same
			//Now check for values at same position
			nodePtr curr1 = nullptr, curr2 = nullptr;
			for (int i = 0; i < rowList.size(); i++)
			{
				curr1 = this->rowList[i]->nextInRow;
				curr2 = obj.rowList[i]->nextInRow;
				
				if (curr1 == nullptr && curr2 != nullptr)
					return 0;
				else if (curr2 == nullptr && curr1 != nullptr)
					return 0;

				while (curr1 != nullptr && curr2 != nullptr)
				{
					if ((curr1->value != curr2->value) || (curr1->colIndex != curr2->colIndex))
						return 0;
					curr1 = curr1->nextInRow;
					curr2 = curr2->nextInRow;
				}

				if (curr1 == nullptr && curr2 != nullptr)
					return 0;
				else if (curr2 == nullptr && curr1 != nullptr)
					return 0;
			}
			return 1;
		}
		else
			return 0;
	}


	//Addition Opeartor
	sparse_matrix operator + (const sparse_matrix& obj)
	{
		//First create a temp matrix
		sparse_matrix temp;
		//Now 3 pointers to iterate
		//tcurr ==> temp
		//curr1 ==> this
		//curr2 ==> obj

		nodePtr tcurr = nullptr, curr1 = nullptr, curr2 = nullptr;
		int counter[6] = { 0 };
		for (int i = 0; i < rowList.size(); i++)
		{
			//First add a new node to temp
			temp.rowList.push_back(new node(-1, 0, nullptr));
			//Now point pointers
			tcurr = temp.rowList[i];
			curr1 = rowList[i];
			curr2 = obj.rowList[i];
			for (int j = 0; j < 6; j++)
				counter[j] = 0;

			if ((curr1->value == -1 && curr1->nextInRow == nullptr) && (curr2->value == -1 && curr2->nextInRow == nullptr))
			{
				//Both rows are NULL
				continue;
			}
			else if (curr1->value == -1 && curr1->nextInRow == nullptr)
			{
				if (counter[3] == 0)
				{
					counter[3] = 1;
					curr2 = curr2->nextInRow;
				}
				//Caller row is NULL
				while (curr2 != nullptr)
				{
					this->addNode(tcurr, curr2, i);
					curr2 = curr2->nextInRow;
				}
			}
			else if (curr2->value == -1 && curr2->nextInRow == nullptr)
			{
				if (counter[4] == 0)
				{
					counter[4] = 1;
					curr1 = curr1->nextInRow;
				}
				//Obj row is NULL
				while (curr1 != nullptr)
				{
					this->addNode(tcurr, curr1, i);
					curr1 = curr1->nextInRow;
				}
			}
			else if (curr1 and curr2)
			{
				//Both rows have data
				int j = curr1->size - 1,  k = curr2->size - 1;
				if (curr1->size < curr2->size)
				{
					//If caller list is smaller and obj list is larger
					if (counter[0] == 0)
					{
						counter[0] = 1;
						curr1 = curr1->nextInRow;
						curr2 = curr2->nextInRow;
					}
					//Caller list is smaller
					if (curr1->colIndex == curr2->colIndex)
					{
						while (true)
						{
							if (j >= 0)
							{
								this->addNode(tcurr, (curr1->value + curr2->value), curr1->colIndex, i);
								tcurr = tcurr->nextInRow;
								curr1 = curr1->nextInRow;
								curr2 = curr2->nextInRow;
								j--;
								k--;
							}
							else if (k >= 0)
							{
								this->addNode(tcurr, (curr2->value), curr2->colIndex, i);
								tcurr = tcurr->nextInRow;
								curr2 = curr2->nextInRow;
								k--;
							}
							if (j == -1 and k == -1)
								break;
						}
					}
					else if (curr1->colIndex > curr2->colIndex)
					{
						int l = k - j;
						while (true)
						{
							if (l > 0)
							{
								this->addNode(tcurr, (curr2->value), curr2->colIndex, i);
								tcurr = tcurr->nextInRow;
								curr2 = curr2->nextInRow;
								k--;
								l--;
							}
							else if (k >= 0)
							{
								this->addNode(tcurr, (curr1->value + curr2->value), curr1->colIndex, i);
								tcurr = tcurr->nextInRow;
								curr1 = curr1->nextInRow;
								curr2 = curr2->nextInRow;
								j--;
								k--;
							}
							if (j == -1 and k == -1)
								break;
						}
					}
				}
				else if (curr1->size > curr2->size)
				{
					//If caller list is larger and obj list is greater
					if (counter[1] == 0)
					{
						counter[1] = 1;
						curr1 = curr1->nextInRow;
						curr2 = curr2->nextInRow;
					}
					//Caller list is larger
					if (curr1->colIndex == curr2->colIndex)
					{
						while (true)
						{
							if (k >= 0)
							{
								this->addNode(tcurr, (curr1->value + curr2->value), curr1->colIndex, i);
								tcurr = tcurr->nextInRow;
								curr1 = curr1->nextInRow;
								curr2 = curr2->nextInRow;
								j--;
								k--;
							}
							else if (j >= 0)
							{
								this->addNode(tcurr, (curr1->value), curr1->colIndex, i);
								tcurr = tcurr->nextInRow;
								curr1 = curr1->nextInRow;
								j--;
							}
							if (j == -1 and k == -1)
								break;
						}
					}
					else if (curr1->colIndex < curr2->colIndex)
					{
						int l = j - k;
						while (true)
						{
							if (l > 0)
							{
								this->addNode(tcurr, (curr2->value), curr2->colIndex, i);
								tcurr = tcurr->nextInRow;
								curr2 = curr2->nextInRow;
								j--;
								l--;
							}
							else if (k >= 0)
							{
								if (curr2)
								{
									this->addNode(tcurr, (curr1->value + curr2->value), curr1->colIndex, i);
									tcurr = tcurr->nextInRow;
									curr1 = curr1->nextInRow;
									curr2 = curr2->nextInRow;
									j--;
									k--;
								}
								else
								{
									j--;
									k--;
								}
							}
							if (j == -1 and k == -1)
								break;
						}
					}
				}
				else if (curr1->size == curr2->size)
				{
				//Both lists are equal
					if (counter[5] == 0)
					{
						counter[5] == 1;
						curr1 = curr1->nextInRow;
						curr2 = curr2->nextInRow;
					}

					while (curr1 != nullptr)
					{
						this->addNode(tcurr, (curr1->value + curr2->value), curr1->colIndex, i);
						tcurr = tcurr->nextInRow;
						curr1 = curr1->nextInRow;
						curr2 = curr2->nextInRow;
					}
				}
			}
		}
		
		temp.N = N;
		temp.M = M;
		return temp;
	}


	// Multiply Operator
	sparse_matrix operator * (const sparse_matrix& obj)
	{
		sparse_matrix temp;
		nodePtr curr1 = nullptr, curr2 = nullptr, tcurr = nullptr;
		int result = 0, tcol = 1, no_of_obj_col_to_be_multiplied = 1;
		int curr1_col_index = 2;
		bool flag = true;
		for (int i = 0; i < this->rowList.size(); i++)
		{
			curr1 = this->rowList[i]->nextInRow;
			temp.rowList.push_back(new node(-1, 0, nullptr));
			tcurr = temp.rowList[i]->nextInRow;
			tcol = 1;
			
			if (curr1 != nullptr)
			{
				// This row is not NULL
				for (int j = 1; j <= obj.N; j++)		// Traversing obj matrix
				{
					tcol = 1;
					curr1 = this->rowList[i]->nextInRow;
					result = 0;
					curr1_col_index = 2;
					// Traversing Cols
					for (int k = 0; k < obj.M; k++)		// Traversing Rows
					{

						curr2 = obj.rowList[k]->nextInRow;

						if (curr2 == nullptr)
						{
							// It means that obj row which needs to be multipled is NULL
							// and regardless of the this row values
							// result should be zero
							flag = false;
							break;
						}

						no_of_obj_col_to_be_multiplied = 1;
						while (no_of_obj_col_to_be_multiplied < j && curr2 != nullptr)
						{
							if (curr2->colIndex < j)
								curr2 = curr2->nextInRow;
							no_of_obj_col_to_be_multiplied++;
						}

						if (curr2 == nullptr || curr1 == nullptr)
							break;
						
						else if (curr2->colIndex == j && curr1->colIndex - k == 1)
						{
							// Non zero value is present
							result = result + (curr1->value * curr2->value);
							curr1 = curr1->nextInRow;
						}
						else if (curr2->colIndex < j && curr1->colIndex - k == 1)
						{
							// Non zero value is present
							result = result + (curr1->value * curr2->value);
							curr1 = curr1->nextInRow;
						}
						else if (curr2->colIndex > j && curr1->colIndex - k == 1)
						{
							// Zero value is present
							result = result + 0;
							curr1 = curr1->nextInRow;
						}
					}
					curr1_col_index++;
					//Adding row in temp
					if(flag)
						temp.addNode(result, tcol++, tcurr, i);
				}
			}
			else
			{
				// We should not add value with zero
				// but I am adding just to check my code
				// will remove it later
				// Adding row in temp

				/*result = 0;
				temp.addNode(result, tcol++, tcurr, i);*/
			}
		}
		temp.M = this->M;
		temp.N = obj.N;
		return temp;
	}


	//Insertion Operator
	friend ostream& operator << (ostream& out, const sparse_matrix obj)
	{
		nodePtr curr = nullptr;
		for (int i = 0; i < obj.rowList.size(); i++)
		{
			curr = obj.rowList[i]->nextInRow;
			while (curr != nullptr)
			{
				out << curr->value << ", ";
				curr = curr->nextInRow;
			}
			out << endl;
		}
		return out;
	}
	
	//Member Functions
	//Read
	void read(string filename)
	{
		//cout << "read() called" << endl;
		ifstream fin(filename);

		//Checking if File is opened or not
		if (fin.is_open())
		{
			int colIndex = 1, i = 0;
			//char buffer[500];
			string buffer;
			char* token = nullptr, *ptr = nullptr;
			char delim[] = " ";
			nodePtr curr = nullptr;
			//This loop will read file till end
			while (!fin.eof())
			{
				//Now we need to read it until '\n'
				getline(fin,buffer,'\n');	//This line will read till endline
				nodePtr head = new node(-1,0,nullptr);
				rowList.push_back(head);
				//Now we need to tokenize this buffer at [space]
				ptr = strtok_s(&buffer[0], delim, &token);
				colIndex = 1;
				while (ptr)
				{
					if ((int)*ptr - 48 != 0)
						addNode(atoi(ptr), colIndex, curr, i);
					ptr = strtok_s(NULL, delim, &token);
					colIndex++;
				}
				i++;
			}
			this->M = i;	//No. of Rows
			this->N = --colIndex;	//No. of Columns
			fin.close();
		}
		else
		{
			cout << "File not found" << endl;
		}
	}


	//Transpose
	sparse_matrix transpose()
	{
		//cout << "transpose() called" << endl;

		//First we need to create a temp matrix
		sparse_matrix temp;
		//Now we need to push_back temp rows until caller matrix cols
		for (int i = 0; i < this->N; i++)
			temp.rowList.push_back(new node(-1, 0, nullptr));

		//Now we need to add cols of caller matrix to rows of temp
		nodePtr curr = nullptr, tcurr = nullptr;
		int temp_row_index = 0, temp_col_index = 1, j = 1;
		for (int i = 0; i < this->rowList.size(); i++)
		{
			curr = this->rowList[i]->nextInRow;	//Will point curr to next of head

			while (curr != nullptr)
			{
				this->addNode(curr->colIndex - 1, i + 1, curr->value, temp);
				curr = curr->nextInRow;
			}
		}

		temp.M = this->N;
		temp.N = this->M;
		//cout << temp;
		//*this = temp;
		return temp;
	}


	//Print
	void PrintMatrix()
	{
		nodePtr curr = nullptr, prev = nullptr;
		int counter = 1, last_col_index = 1;
		bool flag = true;
		for (int i = 0; i < rowList.size(); i++)
		{
			curr = rowList[i]->nextInRow;
			counter = 1;
			flag = true;

			// If row is NULL
			// Print zero's equal to no. of columns
			if (curr == nullptr)
			{
				int j = this->N;
				while (j >= 1)
				{
					cout << "0, ";
					j--;
				}
			}

			// If row is not NULL
			// Print zero's accordingly
			while (curr != nullptr)
			{
				// If there is no data at first column
				// Print zero's till curr->colIndex - 1;
				if (flag && counter == 1 && curr->colIndex != 1)
				{
					flag = false;
					last_col_index = curr->colIndex;
					while (last_col_index > counter)
					{
						cout << "0, ";
						last_col_index--;
					}
					counter = curr->colIndex;
				}

				if (curr->colIndex > 1 && curr->colIndex != 1)
				{
					// If there is data at first column
					// Print zero's until curr->colIndex - last_col_index
					flag = false;
					last_col_index = curr->colIndex;
					while (last_col_index > counter)
					{
						if(last_col_index - counter != 1)
							cout << "0, ";
						last_col_index--;
					}
					counter = curr->colIndex;
				}
				
				flag = false;
				cout << curr->value << ", ";
				prev = curr;
				curr = curr->nextInRow;
			}

			if (prev != nullptr && prev->colIndex != this->N)
			{
				// If curr has traversed whole row
				// and colIndex of curr is not equal to N
				// It means that colIndex is smaller than N
				// and we need to print remaning zero's present at last locations
				counter = N;
				last_col_index = prev->colIndex;
				while (last_col_index != counter)
				{
					cout << "0, ";
					last_col_index++;
				}
			}

			cout << endl;
		}
	}


	//Sub Matrix
	bool isSubMatrix(const sparse_matrix& obj)
	{
		//First we need to check for dimensions of sub matrix
		//this -> original matrix, obj -> sub matrix

		if ((obj.M <= this->M) && (obj.N <= this->N))
		{
			int sub_index = 0, check_value = 0;
			nodePtr curr = obj.rowList[sub_index++]->nextInRow;

			//Now check whether the first element even matches or not?
			//if its matches check further otherwise obj is not the sub matrix
			nodePtr curr2 = nullptr;
			for (int i = 0; i < this->rowList.size(); i++)
			{
				curr2 = rowList[i]->nextInRow;
				if (curr == nullptr)
				{
					if (curr2 == nullptr)
					{
						check_value++;
						if (sub_index < obj.rowList.size())
							curr = obj.rowList[sub_index++]->nextInRow;
					}

					else if (curr == nullptr && check_value != 0)
					{
						//It means sub matrix has some NULL row
						//at last position or some in b/w position
						if (curr2->colIndex >= obj.N)
						{
							check_value++;
							if (sub_index < obj.rowList.size())
								curr = obj.rowList[sub_index++]->nextInRow;
							if (check_value == obj.rowList.size())
								return 1;
						}
					}

					else if (curr == nullptr && check_value == 0)
					{
						//It means sub matrix has some NULL row
						//at starting position
						if (curr2->colIndex >= obj.N)
						{
							check_value++;
							if (sub_index < obj.rowList.size())
								curr = obj.rowList[sub_index++]->nextInRow;
						}
					}

					//We need to find row of this which is also NULL
					else if (curr2 != nullptr)
					{
						continue;
					}
				}
				else if (curr)
				{
					if (curr2 != nullptr && (curr->value == curr2->value))
					{
						//If values matches then we need to check for whole row of curr(obj)
						bool flag = true;
						while (curr != nullptr)
						{
							if (curr->value != curr2->value || curr->colIndex != curr2->colIndex)
							{
								if (curr->colIndex + 1 == curr2->colIndex)
								{
									//It means we have a null which can be ignored
									curr = curr->nextInRow;
									curr2 = curr2->nextInRow;
									continue;
								}
								else
								{
									check_value = sub_index = 0;
									curr = obj.rowList[sub_index++]->nextInRow;
									flag = false;
									break;
								}
							}
							curr = curr->nextInRow;
							curr2 = curr2->nextInRow;
						}
						if (flag)
						{
							check_value++;
							if (sub_index < obj.rowList.size())
								curr = obj.rowList[sub_index++]->nextInRow;
						}
						if (check_value == obj.rowList.size())
							return 1;
					}
					else if (curr2 != nullptr && curr->value != curr2->value)
					{
						//It means that we need to travserswe curr2(original matrix row)
						//in order to check whether the match is in some front
						while (curr2 != nullptr)
						{
							if (curr->value == curr2->value)
								break;
							curr2 = curr2->nextInRow;
						}
						if (curr2 != nullptr && curr2->value == curr->value)
						{
							bool flag = true;
							while (curr != nullptr && curr2!= nullptr)
							{
								if (curr->value != curr2->value)
								{
									if (curr->colIndex + 1 == curr2->colIndex)
									{
										//It means we have a null which can be ignored
										curr = curr->nextInRow;
										curr2 = curr2->nextInRow;
										continue;
									}
									else
									{
										check_value = sub_index = 0;
										curr = obj.rowList[sub_index++]->nextInRow;
										flag = false;
										break;
									}
								}
								curr = curr->nextInRow;
								curr2 = curr2->nextInRow;
							}
							if (flag)
							{
								check_value++;
								if (sub_index < obj.rowList.size())
									curr = obj.rowList[sub_index++]->nextInRow;
							}
							if (check_value == obj.rowList.size())
								return 1;
						}
					}
					else if (check_value == obj.rowList.size())
						return 1;
					else
					{
						check_value = 0;
						sub_index = 0;
						curr = obj.rowList[sub_index++]->nextInRow;
					}
				}
			}

			if (check_value == obj.rowList.size())
				return 1;
		}
		return 0;
	}


	//Destructor
	~sparse_matrix()
	{
		//cout << "~sparse_matrix() called" << endl;

		nodePtr curr = nullptr;
		for (int i = 0; i < rowList.size(); i++)
		{
			curr = rowList[i];
			while (curr != nullptr)
				delNode(curr);
		}
		this->rowList.clear();
		M = N = 0;
		curr = nullptr;
	}
};