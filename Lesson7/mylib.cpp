#include <iostream>

using namespace std;

namespace MyLib
{
    void initArray(float arr[], int size)
    {
        arr[size];

    }

    void arrayPrint(float arr[], int size)
    {
        for (int i = 0; i < size; i++)

        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int countElements(int size, float arr[])
    {
        int a = 0;
        int b = 0;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] < 0)
            {
                a++;
            }
            else
                b++;

        }

        cout << "Positive: " << b << endl;
        cout << "Negative: " << a << endl;


        return a, b;
    }

}