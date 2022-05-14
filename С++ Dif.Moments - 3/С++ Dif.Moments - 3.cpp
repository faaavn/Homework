#include <iostream>
#include <vector>
#include <list>
using namespace std;

void Add (list<double>& L)
{
	double s = 0;
	for (auto it : L)
	{
		s+=it;
	}
	s = s / L.size();
	
	L.push_back(s);
}

class Matrix
{
private:
	int** Matr;
	int m;
	int n;

	void Create()
	{
		Matr = new int* [m];
		for (int i = 0; i < m; i++)
			Matr[i] = new int[n];
	}

public:
	Matrix() : m(5), n(5) { Create(); }
	Matrix(int i) : m(i), n(i) { Create(); }
	Matrix(int i, int j) : m(i), n(j) { Create(); }
	~Matrix()
	
	{
		for (int i = 0; i < m; i++)
			delete[] Matr[i];
		delete[] Matr;
	}
	
	int& Element(int i, int j)
	{
		if (i < m && j < n)
			return Matr[i][j];
		else
			cout << "Error: 1";
	}
	
	void Print()
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout.width(4);
				cout << Matr[i][j];
			}
			cout << endl;
		}
	}
	
	void getMatrixWithoutRowAndCol(int size, int row, int col, int** newMatrix) {
		int offsetRow = 0; 
		int offsetCol = 0; 
		for (int i = 0; i < size - 1; i++) {
			
			if (i == row) {
				offsetRow = 1; 
			}

			offsetCol = 0; 
			for (int j = 0; j < size - 1; j++) {
				
				if (j == col) {
					offsetCol = 1; 
				}

				newMatrix[i][j] = Matr[i + offsetRow][j + offsetCol];
			}
		}
	}
	int matrixDet(int size) {
		int det = 0;
		int degree = 1;
		
		if (size == 1) {
			return Matr[0][0];
		}
		
		else if (size == 2) {
			return Matr[0][0] * Matr[1][1] - Matr[0][1] * Matr[1][0];
		}
		else {
			int** newMatrix = new int* [size - 1];
			for (int i = 0; i < size - 1; i++) {
				newMatrix[i] = new int[size - 1];
			}

			for (int j = 0; j < size; j++) {
				
				getMatrixWithoutRowAndCol(size, 0, j, newMatrix);

				det = det + (degree * Matr[0][j] * matrixDet(size - 1));
				
				degree = -degree;
			}

			for (int i = 0; i < size - 1; i++) {
				delete[] newMatrix[i];
			}
			delete[] newMatrix;
		}
		cout << det << endl;
		
		return det;
	}
	
};

class MyIter
{
public:
	MyIter() {};
	MyIter(int& val) { Ptr = &val; };
	void operator=(int val) { *Ptr = val; }
	auto operator*() { return *Ptr; }
	void operator++() { Ptr++; }
	explicit MyIter(int* __i) : Ptr(__i) { }
	void first()
	{
		index = 0;
	}
	void next()
	{
		index++;
	}
	MyIter& operator+=(const size_t& __n)
	{
		Ptr += __n; return *this;
	}

	MyIter operator+(const size_t& __n) const
	{
		return MyIter(Ptr + __n);
	}

	MyIter& operator-=(const size_t& __n)
	{
		Ptr -= __n; return *this;
	}
	void pushBack(int const& s) {
		int* temp = new int[siz + 1];
		for (int i = 0; i < siz; i++)
			temp[i] = elem[i];
		temp[siz] = s;
		
		this->elem = temp;
		this->siz += 1;
	}
private:
	int siz;            
	int* elem;
	int index;
	int* Ptr;
};

int main()
{
	list<double> L1 = { 3, 8, 10.1, 12.5, 11.44 };
	
	for (auto it : L1)
		cout <<it<< " ";
	cout << endl;

	Add(L1);
	
	for (auto it : L1)
		cout << it << " ";
	cout << endl;
	//---------------------------
	
	Matrix M(5, 5);
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			M.Element(i, j) = i + j;
	}
	
	M.Print();
	M.matrixDet(5);
	//-----------------------
	vector<int> V = { 1, 2 , 3, 4, 5};
	for (MyIter it : V)
	{
		it.pushBack(6);
		cout << *it << " ";
	}
	cout << endl;
	
	return 0;
}


