#include <iostream>
using namespace std;

class Car {
protected:
	string company;
	string model;

public:
	Car() {
		company = "Audi"; model = "A3";
		cout << "Car: " << company << " " << model << endl;
	}
};

class PassengerCar : virtual public Car {
public:
	PassengerCar() {
		company = "BMW"; model = "x6";
		cout << "Passenger Car: " << company << " " << model << endl;
	}

};

class Bus : virtual public  Car {
public:
	Bus() {
		company = "Volvo"; model = "9700";
		cout << "Bus: " << company << " " << model << endl;
	}

};

class Minivan : public PassengerCar, public Bus {
public:
	Minivan() {
	company = "Volkswagen"; model = "Caravelle";
	cout <<"Minivan: " << company << " " << model << endl;
	}

};

int main_cars()
{
	Minivan* Mptr = new Minivan;

	return 0;
}
