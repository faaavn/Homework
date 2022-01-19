#include <stdio.h>
#include "Stack.h"
#include "Geek.h"
#define n 6

int matrix[n][n]= {
    {0,1,1,0,0,0},
    {0,0,0,1,1,0},
    {0,1,0,0,0,1},
    {1,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,1,1},
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

int queueLinks[6] = {0};
int matrixLinks [6] = {0};

void matrixCount(int** matrix, const int size)
{
    for (int i =0; i < size; ++i)
    {
        for(int j =0; j < size; ++j){
            if (matrix[i][j]==1);
                if(i!=j) matrixLinks[i]++;
        }
    }
}

void queueCount(int** matrix, int start, const int size)
{
    TwoLinkList* queue = (TwoLinkList*)malloc(sizeof(TwoLinkList));
    initTwoLinkList(queue);
    clearIntArray(visited, size);
    TwoLinkEnqueue(queue,start);
    while(queue->size > 0)
    {
        int indx = TwoLinkDequeue(queue);
        if(visited[indx]) continue;
        visited[indx] = true;
        for (int i =0; i<size; ++i)
        {
            if(get2dInt(matrix, indx, i)==1)
            {
                if(i!= indx)
                    queueLinks[i]++;
                if(!visited[i])
                    TwoLinkEnqueue(queue,i);
            }
        }
    }
    clearIntArray(visited, size);
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
    matrixCount(matrix,6);

    for (int i = 0; i<= 6; i++)
        printf(matrixLinks); //delal cherez Geek.h, no poyavilis` problemi s vivodom
                             //tak ih i ne reshil




    return 0;
}
