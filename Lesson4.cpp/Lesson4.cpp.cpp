#include <iostream>

using namespace std;
/*=============================================
                   Задание 1.
===============================================*/

void task1()
{   
    int a,b;
    cout << "Enter first digit:"<< endl;
    cin >> a;
    
    cout << "Enter second digit:"<< endl;
    cin >> b;
    
    if (a + b >= 10 && a + b <= 20)
    {
        cout << "True" << endl;

    }
    else
    {
        cout << "False"<< endl;
    }

}

/*=============================================
                   Задание 2.
===============================================*/

void task2()
{
    int a, b;
    cout << "Enter first digit:" << endl;
    cin >> a;
    
    cout << "Enter second digit:" << endl;
    cin >> b;

    if (a==10 && b==10 || a+b ==10)
    {
        cout << "True" << endl;

    }
    else
    {
        cout << "False"<< endl;
    }
}

/*=============================================
                   Задание 3.
===============================================*/

void task3()
{
    cout << "Odd numbers are:";

    for (int i =1 ; i >= 1 && i <= 50; i=i+1)
        
        if (i %2 != 0)
    {
        cout << i << " ";
     
   
    }

}

/*=============================================
                   Задание 4.
===============================================*/

void task4()
{
    int  i; //prime number
    cout << "Enter a random number:";
    cin >> i;

    if (n% i ==0)  // cовсем запутался с 4ым, несколько решений попробовал, но все не подходят, если этот коментарий остался, то я не успел попытаться еще раз ))
    {
        cout << "Your prime number is:" << i;

    }
    else 
    {
        do 
        {
            cout << "You are wrong!" << endl;
            cout << "Enter different number:";
            cin >> i;
        } while ;

        

    }
   

    







}










int main()
{ 
    task1();
    task2();
    task3();    
    task4();
    
    
    
    return 0;
}

