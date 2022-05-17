#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <numeric>


using namespace std; 



template<typename Print>
void printV(vector<Print>& v)
{
	ostream_iterator<Print> it_o = { cout, " | " };
	copy(v.begin(), v.end(), it_o);
	cout << endl;
}

template<typename InsertV>
void insert_sorted(vector<InsertV>& v, InsertV n)
{	
	v.push_back(n);
	sort(v.begin(), v.end());
	cout << "After insert " << n << " and sorted: " << endl;
	printV(v);
}

void generateAnalogSignal(vector<double>& v)
{
	generate(v.begin(), v.end(), [n = 0]() mutable
	{
		return sin(n++ * (2 * M_PI / 100)) * 10;
	});
}

double calcuError(vector<double>& aVec, vector<int>& bVec)
{
	return inner_product(aVec.begin(), aVec.end(), bVec.begin(), 0.0,
		plus<double>{},
		[](double a, int b)
		{
			return pow(a - b, 2);
		});
}

int main()
{
	vector<int> v = { 1, 4 , 8 , 9 ,15, 22, 48, 77 , 100 };
	printV(v);
	insert_sorted(v, 26);
	cout << endl;
	vector<double> v1 = { 3.3, 11.2, 44.8, 55.0};
	printV(v1);
	insert_sorted(v1, 41.5);
	cout << endl;
	
	//----------------------------------
	const int N = 100;
	vector<double> a(N);
	vector<int> b(N);
	generateAnalogSignal(a);
	cout << "Analog signal: " << endl;
	printV(a);
	cout << endl;
	copy(a.begin(), a.end(), b.begin());
	cout << "Numeric signal: " << endl;
	printV(b);
	cout << "Error: " << calcuError(a, b) << endl;
	
	return 0;
}

