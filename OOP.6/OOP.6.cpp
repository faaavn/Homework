#include <iostream>
using namespace std;

template< typename CharT, typename Traits >
basic_ostream<CharT, Traits>& endll(basic_ostream<CharT, Traits>& os)
{
	os.put(os.widen('\n'));
	os.put(os.widen('\n'));
	os.flush();

	return os;
}

int main()
{
	int i;
	cout << "Write int: ";
	while (!(cin >> i) || cin.get() != '\n')
	{
		cerr << " You are wrong! It`s not an int. Enter again!" << endl;
		cin.clear();
		cin.sync();
		cout << "Write int: ";
	}
	cout<<endl;
	
	cout << "A" << endll;
	cout << "B";
	
	return 0;
}

