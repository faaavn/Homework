#include <iostream>
#include <cmath>

using namespace std;

class Figure {
protected:
    double S = 0;
    double h = 14;
    double a = 32.5;
    double d = 11.38;
    double b = 38.3;

public:
    Figure() {}
    
    virtual double area() = 0;

};

class Parallelogram : public Figure {

public:
   Parallelogram() { }
   
    
   virtual double area () override {

       S = h * a;
       cout << "The area of the Parallelogram is: " << S << endl;
       return S;
   }

};

class Circle : public Figure {

public:
    Circle() {};
   
    double area() override {

        const double PI = 3.14159265;
        S = (static_cast<int>(d) ^ 2) / 4 * PI;
        cout << "The area of the Circle is: " << S << endl;
        return S;
    }
};

class Rectangle : public Parallelogram {

public:
    Rectangle() {};

    double area() {

        S = b * a;
        cout << "The area of the Rectangle is: " << S << endl;
        return S;
    }
};

class Square : public Parallelogram {

public:
    Square() {};

    double area() {

        S = static_cast <int> (a)^2;
        cout << "The area of the Square is: " << S << endl;
        return S;
    }
};

class Rhombus : public Parallelogram {

public:
    Rhombus() {};
    
    double area() {

        S = h * a;
        cout << "The area of the Rombus is: " << S << endl;
        return S;
    }
};

int main_oop()
{
    Figure* F = new Parallelogram;
    F->area();

    Figure* F1 = new Circle;
    F1->area();

    Figure* F2 = new Rectangle;
    F2->area();

    Figure* F3 = new Square;
    F3->area();

    Figure* F4 = new Rhombus;
    F4->area();

 return 0;
}


