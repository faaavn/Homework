#include <iostream>

using namespace std;

int initDigit(int* ptr)
{
    cout << "Enter a digit: ";

    cin >> *ptr;

    return *ptr;
}

int theFormula(int a, int b, int f)
{
    cout << "Count by formula: " << "x = (a + b - f / a) + f * a * a - (a + b)"<< endl;
    int x = (a + b - f / a) + f * a * a - (a + b);
    cout << "x=" << x << endl;

    return x;

}



int main()
{ 
    int digit = 0;
    int* ptr;
    ptr = nullptr;
    ptr = &digit;
    
    int a = initDigit(ptr);
    cout << "a= " << a << endl;

    int b = initDigit(ptr);
    cout << "b= " << b << endl;

    int f = initDigit(ptr);
    cout << "f= " << f << endl;
    
    theFormula(a, b, f);

    
    return 0;
}

