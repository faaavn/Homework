#include <iostream>

using namespace std;


class OffTheField
{
	int cur_pos_x;
	int cur_pos_y;
	int new_pos_x;
	int new_pos_y;
	string m_message;
public:
	OffTheField(int c_x, int c_y, int n_x, int n_y) :
		cur_pos_x(c_x), cur_pos_y(c_y), new_pos_x(n_x), new_pos_y(n_y), m_message("")
	{
		if (new_pos_x > 10 || new_pos_x < 1)
		{
			m_message += "Error with coord X. Robot is out of the field!\n";
			m_message += '[' + to_string(cur_pos_x) + ';' + to_string(cur_pos_y) + "] => [" +
				to_string(new_pos_x) + ';' + to_string(new_pos_y) + "]\n";
		}
		if (new_pos_y > 10 || new_pos_y < 1)
		{
			m_message += "Error with coord Y. Robot is out of the field!\n";
			m_message += '[' + to_string(cur_pos_x) + ';' + to_string(cur_pos_y) + "] => [" +
				to_string(new_pos_x) + ';' + to_string(new_pos_y) + "]\n";
		}
	}

	const string& getInfo() const
	{
		return m_message;
	}
};

class IllegalCommand
{
private:
	int cur_pos_x;
	int cur_pos_y;
	int new_pos_x;
	int new_pos_y;
	string m_message;
public:
	IllegalCommand(int c_x, int c_y, int n_x, int n_y) :
		cur_pos_x(c_x), cur_pos_y(c_y), new_pos_x(n_x), new_pos_y(n_y), m_message("")
	{
		if (abs(cur_pos_x - new_pos_x) > 1)
		{
			m_message += "Error with coord X. Step it too long!\n";
			m_message += '[' + to_string(cur_pos_x) + ';' + to_string(cur_pos_y) + "] => [" +
				to_string(new_pos_x) + ';' + to_string(new_pos_y) + "]\n";
		}

		if (abs(cur_pos_y - new_pos_y) > 1)
		{
			m_message += "Error with coord Y. Step it too long!\n";
			m_message += '[' + to_string(cur_pos_x) + ';' + to_string(cur_pos_y) + "] => [" +
				to_string(new_pos_x) + ';' + to_string(new_pos_y) + "]\n";
		}

		if (cur_pos_x == new_pos_x && cur_pos_y == new_pos_y)
		{
			m_message += "Error with coord X and Y. You cant step there!\n";
			m_message += '[' + to_string(cur_pos_x) + ';' + to_string(cur_pos_y) + "] => [" +
				to_string(new_pos_x) + ';' + to_string(new_pos_y) + "]\n";
		}
	}

	const string& getInfo() const
	{
		return m_message;
	}
};

class Robot
{
private:
	int pos_x;
	int pos_y;
public:
	Robot(int x = 5, int y = 5) : pos_x(x), pos_y(y)
	{
		cout << "Начальная позиция робота: [" << pos_x << ';' << pos_y << ']' << endl;
	}

	void move(int x, int y)
	{
		if (abs(pos_x - x) > 1 || abs(pos_y - y) > 1 || (pos_x == x && pos_y == y))
			throw IllegalCommand(pos_x, pos_y, x, y);
		if (x > 10 || x < 1 || y > 10 || y < 1)
			throw OffTheField(pos_x, pos_y, x, y);

		cout << "Робот шагнул [" << pos_x << ';' << pos_y << "] => [" << x << ';' << y << ']' << endl;

		pos_x = x;
		pos_y = y;
	}
};

void exercise_3()
{
	int x = 0, y = 0;
	Robot r;

	while (true)
	{
		cin >> x >> y;

		if (x == 0 && y == 0)
			break;

		try
		{
			r.move(x, y);
		}
		catch (const IllegalCommand& e)
		{
			cerr << e.getInfo() << endl;
		}
		catch (const OffTheField& e)
		{
			cerr << e.getInfo() << endl;
		}
	}
}

int main()
{

}