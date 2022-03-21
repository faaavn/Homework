#include <iostream>

using namespace std;

class DivisionByZero
{
private:
	string m_message;
public:
	DivisionByZero(string message = "") : m_message(message) {}
	const string& getMessage() const { return m_message; }
};

namespace my
{

	template <typename T>
	double div(T a, T b)
	{
		if (b == 0)
			throw DivisionByZero("Деление на ноль!");

		return a / b;
	}

}

void divFunct()
{
	try
	{
		double result = my::div(10, 0);
		cout << result << endl;
	}
	catch (const DivisionByZero& e)
	{
		cerr << e.getMessage() << endl;
	}
}


int main()
{

	divFunct();
	

	return 0;
}