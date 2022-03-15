#include <iostream>

using namespace std;

class Date
{
private:
	int m_day;
	int m_month;
	int m_year;
public:
	Date(int day, int month, int year) : m_day(day), m_month(month), m_year(year) {}

	const int& getDay() const
	{
		return m_day;
	}

	const int& getMonth() const
	{
		return m_month;
	}

	const int& getYear() const
	{
		return m_year;
	}

	friend ostream& operator<<(ostream& os, const Date& d)
	{
		os << d.m_day << '.' << d.m_month << '.' << d.m_year;

		return os;
	}
};

template <class T>
class _ptr
{
private:
	T* m_ptr;
public:
	_ptr(T* ptr = nullptr) : m_ptr(ptr) {}
	~_ptr() { delete m_ptr; }

	_ptr(_ptr& p)
	{
		m_ptr = p.m_ptr;
		p.m_ptr = nullptr;
	}

	_ptr& operator=(_ptr& p)
	{
		if (&p == this)
			return *this;

		delete m_ptr;
		m_ptr = p.m_ptr;
		p.m_ptr = nullptr;

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }

	bool isNull() const { return m_ptr == nullptr; }
};

const _ptr<Date>& compares_dates(const _ptr<Date>&, const _ptr<Date>&);

const _ptr<Date>& compares_dates(const _ptr<Date>& a, const _ptr<Date>& b)
{
	if (a->getYear() > b->getYear())
		return a;
	else if (a->getYear() < b->getYear())
		return b;
	else
	{
		if (a->getMonth() > b->getMonth())
			return a;
		else if (a->getMonth() < b->getMonth())
			return b;
		else
		{
			if (a->getDay() > b->getDay())
				return a;
			else
				return b;
		}
	}
}

void swap_dates(_ptr<Date>& a, _ptr<Date>& b)
{
	_ptr<Date> temp(a);
	a = b;
	b = temp;
}


void exercise_1() {
	_ptr<Date> today(new Date(14, 03, 2022));

	cout << "Day: " << today->getDay() << endl;
	cout << "Month: " << today->getMonth() <<endl;
	cout << "Year: " << today->getYear() << endl;
	cout << "today: " << *today << endl;

	_ptr<Date> date;

	cout << "today is " << (today.isNull() ? "null\n" : "not null\n");
	cout << "date is " << (date.isNull() ? "null\n" : "not null\n");

	date = today;

	cout << "today is " << (today.isNull() ? "null\n" : "not null\n");
	cout << "date is " << (date.isNull() ? "null\n" : "not null\n");

	cout << "date: " << *date << endl;
};
void exercise_2() {
	_ptr<Date> date1(new Date(9, 03, 2022));
	_ptr<Date> date2(new Date(10, 02, 2022));
	_ptr<Date> date3(new Date(11, 07, 2022));

	cout << *compares_dates(date1, date2) << endl;
	swap_dates(date2, date3);
	cout << *compares_dates(date1, date2) << endl;

};

int main() 
{

	exercise_1();
	exercise_2();

	return 0;
}