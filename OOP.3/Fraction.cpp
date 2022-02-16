#include <iostream>
#include <ostream>

using namespace std;

class Fraction {
private:
	int num; //chislitel
	int den; //znamenatel
	
public:
	
	Fraction(int _num, int _den) {
		if (_den == 0)
			cout << "Denominater can`t be 0!";

			this->num = _num;
			this->den = _den;
	}
	
	
	friend Fraction operator+ (const Fraction& f1, const Fraction& f2);
	
	friend Fraction operator-(const Fraction& f1, const Fraction& f2);

	friend Fraction operator*(const Fraction& f1, const Fraction& f2);

	friend Fraction operator/(const Fraction& f1, const Fraction& f2);
	
	friend bool operator== (const Fraction& f1, const Fraction& f2);

	friend bool operator!= (const Fraction& f1, const Fraction& f2);
	
	friend bool operator> (const Fraction& f1, const Fraction& f2);
	friend bool operator<= (const Fraction& f1, const Fraction& f2);

	friend bool operator< (const Fraction& f1, const Fraction& f2);
	friend bool operator>= (const Fraction& f1, const Fraction& f2);
	
	
	Fraction& operator-();

	int get_fr() const
	{
		
		return num, den;
	}

	void print_fr() const
	{
		cout << num<<" / "<< den << endl;
	}
};

Fraction operator+(const Fraction& f1, const Fraction& f2)
{
	return Fraction(f1.num * f2.den + f2.num * f1.den, f1.den * f2.den);
}

Fraction operator-(const Fraction& f1, const Fraction& f2)
{
	return Fraction(f1.num * f2.den - f2.num * f1.den, f1.den * f2.den);
}

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	return Fraction(f1.num * f2.num, f1.den * f2.den);
}

Fraction operator/(const Fraction& f1, const Fraction& f2)
{
	return Fraction(f1.num * f2.den, f2.num * f1.den);
}

Fraction& Fraction::operator - ()
{
	num = -num;
	den = -den;

	return(*this);
}

bool operator== (const Fraction& f1, const Fraction& f2)
{
	return (f1.num ==f2.num && f1.den == f2.den);
}
bool operator!= (const Fraction& f1, const Fraction& f2)
{
	return !(f1.num == f2.num && f1.den == f2.den);
}

bool operator> (const Fraction& f1, const Fraction& f2)
{
	return (f1.den < f2.den);
}

bool operator>= (const Fraction& f1, const Fraction& f2)
{
	return (f1.den <= f2.den);
}

bool operator< (const Fraction& f1, const Fraction& f2)
{
	return (f1.den > f2.den);
}

bool operator<= (const Fraction& f1, const Fraction& f2)
{
	return (f1.den >= f2.den);
}


int main()
{
	Fraction f1(3, 7);
	Fraction f2(9, 2);

	cout << "MATHEMATICAL BINARY OPERATORS:" << endl;
	
	Fraction f_result = f1 + f2;
	f_result.print_fr();

	Fraction f_result2 = f2 - f1;
	f_result2.print_fr();

	Fraction f_result3 = f1 * f2;
	f_result3.print_fr();

	Fraction f_result4 = f1 / f2;
	f_result4.print_fr();
	
	cout << "UNARY OPERATOR:" << endl;
	
	-f2;
	f2.print_fr();

	cout << "LOGICAL OPERATORS:" << endl;

	if (f1 == f2)
		cout << "fraction 1 = fraction 2" << endl;
	
	if (f1 != f2)
		cout << "fraction 1 != fraction 2" << endl;
	
	if (f1 > f2)
		cout << "fraction 1 > fraction 2" << endl;
	
	if (f1 >= f2)
		cout << "fraction 1 >= fraction 2" << endl;
	
	if (f1 < f2)
		cout << "fraction 1 < fraction 2" << endl;
	
	if (f1 <= f2)
		cout << "fraction 1 <= fraction 2" << endl;

	return 0;
}