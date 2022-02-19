#include <iostream>
#include <string>
#include <cassert>
#include <vector>
using namespace std;

class ArrayInt
{
private:
    int m_length;
    int* m_data;
public:
    ArrayInt(): m_length(0), m_data (nullptr){}

    ArrayInt(int length) : m_length(length)
    {
        assert(length >= 0);
        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }
    ~ArrayInt() {
        delete[] m_data;
    }
    void erase()
    {
        delete[] m_data;
        m_length = 0;
        m_data = nullptr;
    }

    int& operator[](int index)
    {
        return m_data[index];
    }

    void resize(int newLength)
    {
        if (newLength <= 0)
        {
            erase();
            return;
        }
        int* newData = new int[newLength] {0};
        int CopyElements = 0;
        if (newLength > m_length) CopyElements = m_length;
        else CopyElements = newLength;
        for (size_t i = 0; i < CopyElements; i++)
        {
            newData[i] = m_data[i];
        }
        delete[]m_data;
        m_data = newData;
        m_length = newLength;
    }
    void at(int index, int data)
    {
        if (index >= 0 && index < m_length)
            m_data[index] = data;
    }
    void push_back(int value)
    {
        int* newData = new int[m_length+ 1] {0};
        int CopyElements = m_length;
        for (size_t i = 0; i < CopyElements; i++)
        {
            newData[i] = m_data[i];
        }
        newData[m_length] = value;
        delete[]m_data;
        m_data = newData;
        m_length++;
    }
    void pop_back(int value)                        //delete last element
    {
        int* newData = new int[m_length - 1]{ 0 };
        int CopyElements = m_length -1;
        for (size_t i = 0; i < CopyElements; i++)
        {
            newData[i] = m_data[i];
        }
        newData[m_length] = value;
        delete[]m_data;
        m_data = newData;
        m_length--;
    }

    void pop_front(int value, int newLength)                      //delete first element 
    {                                           
        int* newData = new int[m_length - 1]{ 0 };              //tak i ne ponyal, chem otlichaetsa ot pop_back
       
    }

    void printArray(int* arr)
    {
        for (int i = 0; i < m_length; i++)
        {
         
                cout << arr[i]<< " ";
            
        }
        cout << endl;
    }

    void insertSort(int* array)
    {
        int temp, pos;

        for (int i = 0; i < m_length; i++)
        {
            temp = array[i];
            pos = i - 1;
            while (pos >= 0 && array[pos] > temp)
            {
                array[pos + 1] = array[pos];
                pos--;
            }
            array[pos + 1] = temp;
        }
    }
};


int main()
{
    vector<int>Digit{ 1,4,5,6,8,8,9,12,14,33,45,68 };
    int index = 0;

    for (size_t i = 1; i < Digit.size(); i++)
    {
        for (size_t j = 0; j < Digit.size(); j++)
        {
            
            Digit[j + 1];
            
            if (Digit[j].size() != Digit[i - 1].size())
            {
                index++;
            }

        }
        
            
    }

    cout << index << endl; //tozhe zaputal`sa s zadaniem, takay zadumka bila




    return 0;
}


