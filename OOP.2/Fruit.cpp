#include <iostream>
using namespace std;

class Fruit {
protected:
	string name;
	string color;
public:
	Fruit() = default;
	string setName(string _name) {
		name = _name;
		return _name;
	}
	string setColor(string _color) {
		color = _color;
		return _color;
	}
};

class Apple : public Fruit {
public:
	Apple() = default;
	string getName(){
		name = "Apple";
		return name;
	}

	string getColor() {
		color = "red";
		return color;
	}

};

class Banana : public Fruit {
public:
	Banana() = default;
	string getName() {
		name = "Banana";
		return name;
	}

	string getColor() {
		color = "yellow";
		return color;
	}
};

class GrannySmith : public Apple {
public:
	GrannySmith() = default;
	string getName() {
		name = "Granny Smith apple";
		return name;
	}

	string getColor() {
		color = "green";
		return color;
	}
};

int main_fr()
{
	Apple a;
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << endl;
	std::cout << "My " << b.getName() << " is " << b.getColor() << endl;
	std::cout << "My " << c.getName() << " is " << c.getColor() << endl;



	return 0;
}
