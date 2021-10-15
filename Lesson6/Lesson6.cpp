#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*=====================
        Task 1.
========================*/


int movingArray()
{
	int* ptrArr;
	int n;
	cout << "Enter size of your array:";
	cin >> n;

	if (n > 0)
	{
		ptrArr = new (nothrow) int[n];
		int temp = 1;

		if (ptrArr != nullptr)
		{
			cout << "Initialized array is: ";

			for (size_t i = 0; i <n ; i++)
			{
				ptrArr[i] = temp;
				cout << ptrArr[i] << " ";
				temp *= 2;
			}

			cout << endl;

			delete[] ptrArr;
			ptrArr = nullptr;
		}

		else
		{
			std::cout << "Error! Can not allocate memory!";
		}
	}
	return 0;
}


/*=====================
		Task 2.
========================*/

int matrix4x4()
{
	cout << "Random matrix 4 x 4 :" << endl;
	
	const size_t a = 4;
	
	int** arr = new int* [a];
	
	for (size_t i = 0; i < a; i++) 
	{
		arr[i] = new int[a];
	}
	
	for (size_t i = 0; i < a; i++)
	{
		for (size_t j = 0; j < a; j++)
		{
			arr[i][j] = rand() % 50;
		}
	}

	for (size_t i = 0; i < a; i++)
	{
		for (size_t j = 0; j < a; j++)
		{

			cout << arr [i][j] << " ";

		}

		cout << endl;
	}
	delete[] arr; 
	arr = nullptr;

	return 0;
}     


/*=====================
		Task 3.
========================*/

int createFileName()
{
	cout << "Name 1st txt file: ";
	string name1;
	cin >> name1;
    
	name1 += ".txt";
	
	ofstream file1(name1.c_str());

		if (file1.is_open())
		{
			file1 << "fnatic have announced the signing of Owen smooya Butterfield.";
			file1.close();
		}

		else
		{
			cout << "Error. Can not open file."; 
		}
    

		cout << "Name 2nd txt file: ";
		string name2;
		cin >> name2;

		name2 += ".txt";

		ofstream file2(name2.c_str());

		if (file2.is_open())
		{
			file2 << "fnatic now have a British core for the first time in the organization's CS history.";
			file2.close();
		}

		else
		{
			cout << "Error. Can not open file.";
		}

	return 0;
}


/*=====================
		Task 4.
========================*/









int main()
{
	movingArray();
	
	matrix4x4();

	createFileName();


 	return 0;
}
