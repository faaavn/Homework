#include <iostream>
#include <cstdint>

using namespace std;

class Power
{
public:
	Power() = default;
	
	void setPower(const double _x, const double _y)
	{
		x = _x;
		y = _y;
	}

	int calculatePower()
	{
		double total = 0;
		if (y == 0)
			total = 1;
		
		if (y == 1)
			total = x;

		total = pow(x, y);
		
		cout << x <<" to the power of "<< y << " = " << total << endl;
		
		return total;
	}

private:
	double x;
	double y;
};

class RGBA
{
private:

	uint8_t m_red = 0;
	uint8_t m_green = 0;
	uint8_t m_blue = 0;
	uint8_t m_alpha = 250;

public:
	
	RGBA() = default;

	void RGBA_init(int _red, int _green, int _blue, int _alpha) {
		m_red = _red; m_green = _green; m_blue = _blue; m_alpha = _alpha;
	}

	void printRGBA()
	{
		cout << "m_red = " << static_cast<unsigned int>(m_red) << endl;
		cout << "m_green = " << static_cast<unsigned int>(m_green) << endl;
		cout << "m_blue = " << static_cast<unsigned int>(m_blue) << endl;
		cout << "m_alpha = " << static_cast<unsigned int>(m_alpha) << endl;
	}
};

class Stack
{
private:

	int static const size = 10;
	int arr[size];
	int coursor = -1;

public:

	Stack() = default;

	void stackReset() {
		for (int i = 0; i < size; i++)
		{
			arr[i] = NULL;
		}
	}

	bool stackPush(int data){
		
		if (coursor < size)
		{
			arr[++coursor] = data;
			return true;
		}
		else
		{
			cout << "Stack overflow!" << endl;
			return false;
		}

	}

	int stackPop() {
		
		if (coursor != -1)
			return arr[coursor--];
		else
		{
			cout << "Stack is empty!" << endl;
			return -1;
		}
	}

	void stackPrint() {

		cout << "(";
		for (int i =0; i <=coursor ;i++)
		{
			cout << arr[i];	
		}
		cout << ")";
		cout << endl;
	}
};





int main()
{
	Power calc;
	calc.setPower(19.3, 3.5);
	calc.calculatePower();

	RGBA var;
	var.RGBA_init(14, 27, 11, 37);
	var.printRGBA();

	Stack stack;
	stack.stackReset();
	stack.stackPrint();

	stack.stackPush(3);
	stack.stackPush(7);
	stack.stackPush(5);
	stack.stackPrint();

	stack.stackPop();
	stack.stackPrint();

	stack.stackPop();
	stack.stackPop();
	stack.stackPrint();
	

	return 0;
}


