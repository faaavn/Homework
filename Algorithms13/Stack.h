#ifndef Stack_h
#define Stack_h
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
#endif Stack_h















