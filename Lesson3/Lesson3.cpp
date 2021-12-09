#include <iostream>

using namespace std;

int initValue(int *ptr)
{
	
 cout << "Enter a 5 digit value: " << endl;

 cin >> *ptr;


 return *ptr;
}

int printValue(int *ptr)
{
	if (*ptr < 1'000'00 && *ptr  >9999)
	{
		cout << "1st digit is: " << *ptr / 10000 << endl;
		cout << "2nd digit is: " << (*ptr / 1000) % 10 << endl;
		cout << "3rd digit is: " << (*ptr / 100) % 10 << endl;
		cout << "4th digit is: " << (*ptr / 10) % 10 << endl;
		cout << "5th digit is: " << (*ptr / 1) % 10 << endl;
	}
	else
		cout << "You entered the wrong number " << endl;

	return 0;
}


int main()
{
	int value=0;
	int* ptr;
	ptr = nullptr;
	ptr = &value;

	
	
	initValue(ptr);
	printValue(ptr);
	
	
	
	return 0;
}