#include <iostream>

using namespace std;

void printMass(int** mass, int row, int col)
{
	for  (int i = 0;  i < row;  i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << mass[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void bubleSort(int** mass, int row,int col)
{
	cout << endl;
	
	for (int k = 0; k < row; k++)
	{

		for (int l = 0; l < col; l++)
		{
			for (int i = 0; i < row; i++)
			{

				for (int j = 0; j < col; j++)
				{

					if (j + 1 == col && i + 1 == row) continue;
					else
						if (j + 1 == col && mass[i][j] > mass[i + 1][0])
							swap(mass[i][j], mass[i + 1][0]);

						else
							if (j + 1 == col) continue;

							else
								if (mass[i][j] > mass[i][j + 1])
									swap(mass[i][j], mass[i][j + 1]);



				}
			}
		}  
	}
}

int function(int x)
{
	return (sqrt(fabs(x)) + 5.0 * pow(x, 3.0));
}

void printDigit(int* digit, int sizeN)
{
	for (int i = 0; i < sizeN; i++)
	{
		cout << digit[i] << " ";
	}
	cout << endl;
}

int invertDigit(int* digit, int sizeN)
{
	int buffer; // временное хранилище
	for (int i = 0; i < sizeN / 2; i++)
	{
		buffer = digit[i];
		digit[i] = digit[sizeN - i - 1];
		digit[sizeN - i - 1] = buffer;
	}
	return buffer;
}

int algorTPK(int* digit, int sizeN)
{
	double y;
	int i;

	for (i = 10; i >= 0; i--)
	{
		y = function(digit[i]);
		if (y > 400.0)
		{
			cout << i << " : too large" << endl;

		}
		else
		{
			cout << i << " : " << y << endl;
		}
	}
	return 0;
}

int main()
{	
	//==============================1st=====================
	int row = 5;
	int col = 3;
	
	int** mass = new int* [row];
	for (int i = 0; i < row; i++)
	{
		mass[i] = new int[col];
		for (int j = 0; j < col; j++)
		{
			mass[i][j] = rand() % 10;
		}
	}
	cout << "Initial array: " << endl;
	printMass(mass, 5,3);
	bubleSort(mass, row, col);
	cout << "Sorted array: " << endl;
	printMass(mass, 5,3);
	
	//==============================2nd=====================
	
	int const sizeN = 11;
	
	int* digit = new int[sizeN];

	cout << "Write 11 digits in the array: " << endl;
	
	for (int i = 0; i < sizeN; i++) // заполняем массив числами пользователя
	{
		cin >> digit[i];
	}

	cout << " Your array is: ";
	
	printDigit(digit, sizeN);

	cout << "Inverted array is: ";
	
	invertDigit(digit, sizeN);     //инвертируем
	
	printDigit(digit, sizeN);
	
	algorTPK(digit, sizeN);        //рассчитываем по формуле 

	return 0;
}

