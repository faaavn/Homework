#include <stdio.h>
#include <stdlib.h>



typedef struct {
    int pr;
    int dat;
} Node;

#define SZ 10
Node* arr[SZ];
int tail;
int items;

void init() 
{
    tail = 0;
    items = 0;
    for (int i = 0; i < SZ; i++)
    {
        arr[i] = NULL;
    }
}

void insert(int pr, int dat)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;

    if (items < SZ)
    {
        arr[tail++] = node;
        items++;
    }
    else
    {
        printf ("%s \n", "Queue is full!");
    }
}

Node* rem()
{
    if (items==0)
    {
        printf ("%s \n", "Queue is empty");
        return NULL;
    }
    int max = arr[0]->pr;
    int idx = 0;
    for (int i = 0; i < items; i++)
    {
        if (arr[i]->pr > max)
        {
            max = arr[i]->pr;
            idx = i;
        }
    }
    Node* tmp = arr[idx];

    while (idx<items)
    {
        arr[idx] = arr[idx + 1];
        idx++;
    }
    items--;
    tail--;
    return tmp;
}

void printQueue()
{
    printf("[ ");
    for (int i =0; i < SZ; ++i)
    {
        if  (arr[i]==NULL)
            printf("[*,*]");
        else
        printf("[%d, %d]", arr[i]->pr, arr[i]->dat);
    }
    printf(" ]\n");
}

#define T char
#define SIZE 1000
#define true 1 == 1
#define false 1 != 1

int cursor = -1;
T Stack[SIZE];
typedef int boolean;



boolean push(T data)
{
    if (cursor < SIZE)
    {
        Stack[++cursor] = data;
        return true;
    }
    else
    {
         printf ("%s \n", "Stack overflow!");
        return false;
    }
}

T pop()
{
    if (cursor !=-1)
    {
        return Stack[cursor--];
    }
    else
    {
         printf ("%s \n", "Stack is empty!");

        return -1;
    }
}

void decimalToBinary(int a)
{
    while (a >=1)
    {
        push(a % 2);
        a /= 2;
    }
}


int main()
{
    //=========================1st===========
    int n = 12;
    decimalToBinary(n);
    int count = cursor;
    printf("%d : ", n);
    for (int i = 0; i <= count; ++i)
    {
        printf("%d", pop());
    }
    printf(" \n");

    //=========================2nd===========
    init();
    insert(1,11);
    insert(2,13);
    insert(1,98);
    insert(2,23);
    insert(4,44);
    insert(1,43);
    insert(1,12);
    insert(8,11);
    insert(9,22);
    insert(7,43);
    printQueue();
    for (int i = 0; i < 5;i++)
    {
        Node* n =rem();
        printf("pr=%d, dat=%d \n", n->pr, n->dat);
    }
    printQueue();
  return 0;
}
