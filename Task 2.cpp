#include <iostream>
using namespace std;


short int A = 100;
int B = 50;
long long C = 1'000'345'678;
char D = 'a';
bool E = true;
float F = 218.05f;
double G = 113.3;


enum symbolsToPlay { x, o, X, O,};


int main()
{
	cout << short int(A) << endl;
	
	cout << int(B) << endl;
	
	cout << long long (C) << endl;
	
	cout << char (D) << endl;
	
	cout << bool (E) << endl;
	
	cout << float (F) << endl;
	
	cout << double (G) << endl;
	
	symbolsToPlay tics [2] = { x, X };
	
	symbolsToPlay tacs [2] = { o, O };
	
	
	cout << "Symbols to play for tics:" << tics[0] << ',' << tics[1] << endl;
	
	cout << "Symbols to play for tacs:" << tacs[0] << ',' << tacs[1] << endl;
	
	return 0;

}


