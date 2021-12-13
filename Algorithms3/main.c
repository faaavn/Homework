#include <stdbool.h>


bool checkIfPrime(int a)
{

    if (a > 1)
    {
        for (int i = 2; i < a; i++)
            if (a % i == 0)
                return false;

        return true;
    }
    else
        return false;
}


    int main()
{
    int a;

    printf("Input a number: ");

    scanf("%d", &a);

    switch (checkIfPrime(a))
    {
       case 1: printf("Your digit is prime!");
       break;
       case 0: printf("Your digit is NOT prime!");
       break;
    }

    return 0;
}
