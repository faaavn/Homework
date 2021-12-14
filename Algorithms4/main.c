#include <stdio.h>
#include <stdlib.h>

int decimalToBinary(int n )
{

    if (n<=0)
        return 0;
    if (n==1)
        return 1;

    return n%2 +10 * (decimalToBinary(n/2));
}
int exponantion1(int a , int b)
{
	if (b == 0)
		return 1;

	if (b == 1)
		return a;

	if (b!=1)
	return a * exponantion1(a, b - 1);
}

int exponantion2(int a, int b)
{
	if (b == 0)
		return 1;

	if (b == 1)
		return a;


	if (b % 2 ==0)
		return  exponantion2(a *a, b/2);

	else
		return  a * exponantion2(a , b - 1);


}

int chessKing(int x, int y)
{


	if (x == 0 && y == 0)
		return 0;

    if (x == 2 && y == 2)
		return 0;

    if (x == 6 && y == 5)
		return 0;

    if (x == 1 && y == 6)
		return 0;

    if (x == 0 && y == 7)
		return 0;

	if (x == 0 ^ y == 0)
		return 1;
	else
		return chessKing(x, y - 1) + chessKing(x - 1, y);
}



int main()
{
    //===============================1st========================
    int n = 0;
    printf ("%s","Write the number in decimal number system: ");
    scanf ("%d", &n);
    printf ("%s","\n Your digit in binary number system: ");
    printf ("%d",decimalToBinary(n));
    //===============================2nd========================
    int a = 0;
    printf ("%s","\n Write your number (A):");
    scanf ("%d", &a);

    int b = 0;
    printf ("%s","\n Write the degree of number (B):");
    scanf ("%d", &b);

    printf ("%s", "\n A to the power of B is equal to (1st approach):");
    printf ("%d",exponantion1(a,b));

    printf ("%s", "\n A to the power of B is equal to (2nd approach):");
    printf ("%d\n",exponantion2(a,b));
    //===============================3rd========================

    const int sizeY = 8;
	const int sizeX = 8;
	int map [sizeY][sizeX];
	for (int y = 0; y <sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			printf ("%8d", chessKing (x,y));
		}
		printf("\n");
	}

    return 0;
}
