#include <stdio.h>
#include "Stack.h"
#define n 6
#define n1 6

int matrix[n][n]= {
    {0,1,1,0,0,0},
    {0,0,0,1,1,0},
    {0,1,0,0,0,1},
    {1,0,0,0,0,0},
    {0,0,0,0,0,1},
    {0,0,0,0,1,0},
};
int visited[n]={0};

void depthTrail(int st) //current peak
{
    int r;              //next peak
    printf("%d",st);
    visited[st]=1;
    push(st);
    for (r=0; r < n; ++r)
    {
       if(matrix[st][r]== 1 && !visited[r])
       {
          depthTrail(r);
       }
    }
}

int matrix1[n1][n1]= {
    {0,1,1,1,0,0},
    {0,0,0,0,1,0},
    {0,0,0,0,0,1},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
};
int visited1[n1]={0};
int connections[n1]={0};

void matrixSearch(int st1)// ne yspel
{
    int nxt; //next peak
    int rib; //connection(rib)

    printf("%d",rib);

    connections[rib]=0;

    visited1[st1] = 1;

    for (nxt=0; nxt < n1; ++nxt)
    {
       if(matrix[st1][nxt]== 1 && !visited[nxt] && !connections[rib])
       {
          matrixSearch(rib);
       }
    }

}


int main()
{
  //===============================1st========================
  printf("In stack : ");
  depthTrail(2);
  printf("\n");
  printf("Out stack: ");
  int count = cursor;

  for (int i = 0; i <= count; ++i)
    {
        printf("%d", pop());
    }
    printf("\n");
  //===============================2nd========================
    matrixSearch(0);


    return 0;
}
