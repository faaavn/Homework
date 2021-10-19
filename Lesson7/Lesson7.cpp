#include <iostream>
#include "mylib.h"
#include <fstream>

#define Check(b) (0 <= a && a < b)

#define ARRAY_SIZE 10

#define SwapINT(b) (array[j] > array[j + 1])

using namespace std;


void task2()
{
    int a, b;
    cout << "Enter 1st digit: ";
    cin >> a;
    cout << "Enter 2nd digit: ";
    cin >> b;
    if Check(a, b)
    {
        cout << "True"<<endl;
    }
    else
        cout << "False" << endl;

}

void task3()
{
    int array [ARRAY_SIZE]; 
    
    cout << "Enter 10 digits of the array: ";
    
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cin >> array[i];

    }
    
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (SwapINT(b))
            {
                int b = array[j];
                array[j] = array[j + 1];
                array[j + 1] = b;



            }



        }




    }

    cout << "The sorted array is: ";
    
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << array[i] << " ";
    }
    
    cout << endl;
}

void task4()
{
    #pragma pack(push, 1)
    struct Employee
    {
        long id;
        unsigned short age;
        double salary;
    };
    #pragma pack(pop)

    Employee * pEmployee = new Employee;
    
    
    
    pEmployee->id = 1222865;
    pEmployee->age = 28;
    pEmployee->salary = 38'700.05;
    
    cout << "First employee id: " << pEmployee->id << endl;
    cout << "First employee age: " << pEmployee->age << endl;
    cout << "First employee salary: " << pEmployee->salary << endl;
    
    cout << "The size Employee struct is: " << sizeof(pEmployee) << " bytes" << endl;
         
    ofstream fout("Employee.txt");
     
    fout << "First employee id: " << pEmployee->id << endl;
    fout << "First employee age: " << pEmployee->age << endl;
    fout << "First employee salary: " << pEmployee->salary << endl;

    fout.close();
    
    delete pEmployee;

}

int main()
{ 
    cout << "The initial array is: ";
    const int size = 10;
    float arr[size]{ 1.01f,2.232f,3.12f,4.11f,-5.12f,-1.13f,-2.144f,-3.22f,-4.44f,-5.66f };
    
    MyLib::initArray(arr,size);
    MyLib::arrayPrint(arr,size);
    MyLib::countElements(size, arr); //1 и 5 задания вместе
     
    task2();                        // 2ое задание

    task3();                       // 3ье задание 
 
    task4();                      // 4ое задание
    
    return 0;
}

