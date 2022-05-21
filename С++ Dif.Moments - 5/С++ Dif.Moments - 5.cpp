#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <list>
using namespace std;

template<typename T>
void print(const T& cont)
{
	const int size = cont.size();
	for_each(cont.begin(), cont.end(),
		[count = 0, &size](const auto& i) mutable
	{
		count++;
		cout << i;
		if (count != size) cout << ", ";
	});
	cout << endl;
}

template<typename it, typename Type>
void UniqueEl (const it& begin,const it& end)
{
	set<Type> elements;
	copy(begin, end, inserter(elements, elements.end()));
	print(elements);
}

void readline()
{
	const auto my_string_compare = [](const string& lhs, const string& rhs) {
			return lhs.size() < rhs.size();
	};

	set<string, decltype(my_string_compare)> sentences(my_string_compare);
	string sent("not empty");
	while (getline(cin, sent) && !sent.empty()) {
			cout << sent << endl;
		typename string::size_type pos_start{}, pos_end{};
		while (pos_start != sent.npos && pos_end != sent.npos) {
			pos_end = sent.find_first_of(".!?", pos_start);
			sentences.insert(sent.substr(pos_start, pos_end - pos_start));
			pos_start = sent.find_first_not_of(" .!?", pos_end);
			}
		}
	sentences.erase(string());
	for (auto& str : sentences){
		cout << str << endl;
	}
}

int main()
{
	vector<string> s{ "one", "three", "two", "four", "six", "five", "seven", "one", "three", "six" };
	cout << "Initial vector:" << endl;
	print(s); 

	cout << endl << "Ordered vector:" << endl;
	UniqueEl<string>(s.begin(), s.end());
	cout << endl;

	list<string> l{ "one", "three", "two", "four", "six", "five", "seven", "eleven", "three", "ten" };
	cout << "Initial list:" << endl;
	print(l);

	cout << endl << "Ordered list:" << endl;
	UniqueEl<string>(l.begin(), l.end());
	cout << endl;
	
	//---------------------------

	readline();

	return 0;
}


