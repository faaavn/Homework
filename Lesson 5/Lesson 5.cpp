#include <iostream>

using namespace std;

/*===================================================
                 Задание 1.
=====================================================*/


double DistantArr( double arr[], int size)
{
	cout << "The double array:";
	
	for (size_t i = 0; i < size; i++)
	{
		
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}

/*===================================================
				 Задание 2.
=====================================================*/

int changeArray(int array[], int size)
{
	int array1 [10] = { 0,1,1,0,1,0,0,1,1,1 };
	cout <<"The initial array is: " << array1[0] << array1[1] << array1[2] << array1[3] << array1[4] << array1[5] << array1[6] << array1[7] << array1[8] << array1[9] << endl;
	cout << "Changed array is: ";
	
	for (int i = 0; i < 10; i++)
	{
		if (array[i] == 0)
			array[i] = 1;
		else
			array[i] = 0;
		cout << array[i];

	}
	cout << endl;
	return 0;
}

/*===================================================
				 Задание 3.
=====================================================*/

int cicle(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = i * 3 + 1;

		cout << arr[i] << " ";	
	}
	cout << endl;
	return 0;
}

/*===================================================
				 Задание 4.
=====================================================*/

int shiftArray(int arr[], int size)
{
		const int temp = arr[0];

		for (size_t i = 1; i < size; i++)
		{
			arr[i - 1] = arr[i];

			arr[size - 1] = temp;
			cout << arr[i] << " ";
		}
		return 0;
	}


int main()
	{
	const int size = 6;
	double myArr[]{ 10.14141, 12.12121, 13.122 , 14.14314, 15.12313, 13.1311 };
	DistantArr(myArr, size);
	//============================
	
	int mysize1 = 10;
	int myarray1[10] = { 0,1,1,0,1,0,0,1,1,1};
	changeArray(myarray1, mysize1);
	//===============================
	
	const int size2 = 8;
	int array[size2];
	cicle(array, size2);
	//========================
	int const mysize4 = 10;
	int myarr4[mysize4]{ 1,4,8,10,12,16,17,28,33};
	shiftArray(myarr4, mysize4);

	
	return 0;
} 