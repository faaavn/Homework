#include <iostream>

using namespace std;

int initArray(int* array, int size1)
{
	for (int i = 0; i < size1; i++)
	{
		array[i] = rand() % 100;
	}
	return 0;
}

void printArray(int* array, int size1)
{
	for (int i = 0; i < size1; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void swapp(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void insertSort(int* array, int size1)
{
	int temp, pos;

	for (int i = 0; i < size1; i++)
	{
		temp = array[i];
		pos = i - 1;
		while (pos >= 0 && array[pos] > temp)
		{
			array[pos + 1] = array[pos];
			pos--;
		}
		array[pos + 1] = temp;
	}
}

int median(int* array, int first, int last)
{
	int result;
	int min, max;
	int middle = array[(first + last)] / 2;
	if (array[first]>array[middle])
	{
		min = array[middle];
		max = array[first];
	}
	else
	{
		min = array[first];
		max = array[middle];
	}
	if (min > array[last]) result = min;
	else if (array[last] > max) result = max;
	else result = array[last];

	if (result == array[first]) return first;
	else if (result == array[middle]) return middle;
	else return last;
}

void improvedFastSort(int* array, int size1, int first,  int last)
{
	if (last - first > 10)
	{
		int i = first;
		int j = last;

		int med = median (array, first, last);
		swapp(&array[med], &array[(first + last) / 2]);

		int x = array[(first + last) / 2];
		do {
			while (array[i] < x) i++;
			while (array[j] < x) j--;

			if (i <= j)
			{
				swapp(&array[i], &array[j]);
				i++;
				j--;


			}
		} while (i <= j);

		improvedFastSort(array,size1, i, last);

		improvedFastSort(array,size1, first, j);
	}
	else
		insertSort(array, size1);
}

void bucketSort(int* array1, int size2)
{
	const int max = 12; //если я напишу что max = size2 выдает ошибку, ответ почему, нигде не нашел, поэтому поменял просто на 12
	const int b = 10;

	int buckets[b][max + 1];

	for (int i = 0; i < b; i++)
	{
		buckets[i][max] = 0;
	}

	for (int digit = 1; digit < 1'000'000'000; digit *= 10)
	{
		for (int i = 0; i < max; i++)
		{
			if (array1[i] % 2 == 0)
			{
				int d = (array1[i] / digit) % b;
				buckets[d][buckets[d][max]++] = array1[i];
				array1[i] = -1;

			}
		}
		int idx = 0;
		for (int i = 0; i < b; i++)
		{
			for (int j = 0; j < buckets[i][max]; j++)
			{
				while (array1[idx] != -1)idx++;
				
				array1[idx] = buckets[i][j];
			}
			buckets[i][max] = 0;
		}
		
	}
}

	int main()
{
	//=========================1st=================

	int size1=20;

	cout << "An initial array is: ";
	
	int* array = new int [size1];
	
	initArray(array, size1);
	
	printArray(array, size1);
	
	improvedFastSort(array,size1, 0, size1 - 1);

	cout << "After quick sort: ";
	printArray(array, size1);


  //============================2nd===================
	
	cout << "2nd array is: ";

	const int size2 = 12;
	int array1[size2]{ 0, 2, 8, 3, 4, 6, 5, 9, 8, 2, 7, 3 };

	printArray(array1, size2);
	
	cout << "2nd array after bucket sort: ";

	bucketSort(array1, size2);
	printArray(array1, size2);
}

