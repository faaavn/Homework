#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <windows.h>
#include "Timer.h"
using namespace std;


template <typename T>

void Swap (T* ptr1, T* ptr2)
{
      T swap_ptr = *ptr1;
     *ptr1 = *ptr2;
     *ptr2 = swap_ptr;
}

template <typename C>
void SortPointers(vector<C*>& V)
{
    sort(V.begin(), V.end(),
        [](C* left, C* right)
        {
            return *left < *right;
        });
}

int Count_if_find(const string& search_line, const string& search_elements)
{
	return count_if(search_line.begin(), search_line.end(),
		[&search_elements](const char& c)
		{
			return search_elements.find(c) != string::npos;
		});
}

int Count_if_for(const string& search_line, const string& search_elements)
{
	return count_if(search_line.begin(), search_line.end(), 
		[&search_elements](const char& c){
	
		for (const auto& search_element : search_elements)
		{
			if (c == search_element)
				return true;
		}
		return false;
	});
}

int For_find(const string& search_line, const string& search_elements)
{
	int count = 0;
	
	for (const auto& c : search_line)
	{
		 if (search_elements.find(c) != string::npos)
			count++;
	}
	return count;
}
int For_for(const string& search_line, const string& search_elements)
{
	int count = 0;
	
	for (const auto& c : search_line)
	{
		for (const auto& el : search_elements)
		{
			if (c == el)
				count++;
		}
	}
	return count;
}

int main()
{
	setlocale(LC_ALL, "RU");

	int a = 10;
    int b = 20;

    int* ptrA = &a;
    int* ptrB = &b;

    cout << *ptrA << " " << *ptrB << endl;
    Swap(&ptrA, &ptrB);
    cout << *ptrA << " " << *ptrB << endl;
   //---------------------------------------------
	const int size = 25;
	vector<int*> Vptr;
	Vptr.reserve(size);
	for (int i = 0; i < size; i++)
	{
		int* element = new int(rand() % 100);
		Vptr.push_back(element);
	}

	auto printV = [&Vptr]()
	{
		for (const auto i : Vptr)
		{
			cout << *i << " ";
		}
		cout << endl;
	};

	printV();
	SortPointers<int>(Vptr);
	printV();

	for (auto i : Vptr)
	{
		delete i;
	}
	//---------------------------count_if, find
	string vowels = "АОИЕЁЭЫУЮЯаоиеёэыуюя";
	
	ifstream file("../War and Peace.txt");
	file.seekg(0, ios::end);
	int size3 = file.tellg();
	file.seekg(0);
	string s(size3, ' ');
	file.read(&s[0], size3);
	
	int count;
	RunTimer timer;
	timer.start("Count_if_find");
	count = Count_if_find(s, vowels);
	timer.print();
	cout << count << " Гласных" << endl;

	//---------------------------count_if, for
	timer.start("Count_if_for");
	count = Count_if_find(s, vowels);
	timer.print();
	cout << count << " Гласных" << endl;
	
	//---------------------------for, find
	timer.start("For_find");
	count = Count_if_find(s, vowels);
	timer.print();
	cout << count << " Гласных" << endl;

	//---------------------------for, for
	timer.start("For_for");
	count = Count_if_find(s, vowels);
	timer.print();
	cout << count << " Гласных" << endl;
		return 0;
}

