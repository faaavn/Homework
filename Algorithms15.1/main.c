#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int hashFunction(char* k) //metod ymnozhenia
{
    int N = 15;
    double A = 0.618033;
    int h = N *fmod((int)*k * A,1);
    return h;
}

int greedyMoney (int* money,int size, int sum)
{
    if (size==0 || sum ==0)
        return NULL;

    int* result = (int*) calloc(100,sizeof(int));
    result[0] = 0;
    int current;
    int k =1;
    for(int i=0; i <size; ++i)
    {
        current =0;
        while(sum - current >= money[i])
        {
            current+= money[i];
            result[k] = money[i];
            result[0]++;
            k++;
            if(sum == current)
                return result;
        }
        sum-= current;
    }
    printf("%s \n", "Count failed");
    return NULL;
}

void printArr (int *arr)
{
    for (int i =1; i <= arr[0];)
    {
        printf("%d, ", arr[i++]);
    }
    printf("\n");
}
int main()
{
   //===================================1st=============================

    printf("HelloWorld - %d \n", hashFunction("HelloWorld"));
    printf("ABBC - %d \n", hashFunction("ABBC"));
    printf("BBCA - %d \n", hashFunction("BBCA"));


    //==================================2nd=============================

    int money[]={50,10,5,2,1};
    printf("98 - ");
    printArr(greedyMoney(money,5,98));




   return 0;
}
