#include <iostream>
using namespace std;

class Person {

protected:
	string name;
	int gender;
	unsigned int age;
	double weight;

public:
	Person() = default;
	
	string setName(const string _name) {
		name = _name;
		cout << " Name: " << _name << endl;
		return _name;
	}

	int setGender(int gender){
		if (gender == 0)
		cout << " Gender: Woman" << endl;
		
		
		if (gender == 1)
		cout << " Gender: Man" << endl;
		
			return 0;
	}
	
	int setAge(const unsigned int _age) {
		age = _age;
		cout << " Age: " << _age << endl;
		return _age;
	}

	double setWeight(const double _weight) {
		weight = _weight;
		cout << " Weight: " << _weight << endl;
		return _weight;
	}
};

class Student : public Person {

private:
	unsigned int learnYear;
	static int studCount;
public:
	
	Student();

	int setAgeLearn(const unsigned int _ly) {
		learnYear = _ly;
		cout << "The learning year: " << _ly << endl;
		return _ly;
	}

	void nextYear() {
		learnYear++;
	}
};

int Student::studCount = 1;
Student::Student() {cout << "The quantity of students: " << studCount++ << endl; };


int main()
{
	Student st1;
	st1.setName("Paul");
	st1.setGender(1);
	st1.setAge(18);
	st1.setWeight(75.5);
	st1.setAgeLearn(1);

	cout << endl;
	
	Student st2;
	st2.setName("Kristina");
	st2.setGender(0);
	st2.setAge(20);
	st2.setWeight(60.2);
	st2.setAgeLearn(3);

	cout << endl;

	Student st3;
	st3.setName("Max");
	st3.setGender(1);
	st3.setAge(22);
	st3.setWeight(80.8);
	st3.setAgeLearn(5);


	return 0;
}


