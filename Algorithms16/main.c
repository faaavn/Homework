#include <stdio.h>
#include <stdlib.h>
#include "Geek.h"

int caesarCipher(char *data, int key, int encrypt)
{
    if (data==NULL)
        return NULL;

    const int length = strlen(data);

    if(length == NULL)
        return NULL;

    char* out = (char*)malloc(sizeof(char)+length);

    for(int i =0; i < length; i++)
    {
        out[i]= data[i] + ((encrypt) ? (char) key : (char) -key);
    }
    out[length] = 0;
    return out;
}

int swapCode (char *data, int key , int encrypt)
{
    if (data==NULL)
        return NULL;

    int l = strlen(data);

    const int length = key * (1+((l-1)/key));

    char* out = (char*)malloc(sizeof(char)+length);
    if(encrypt == 0) key = length/key;
    int idx = 0;
    for(int i=0; i < key; i++)
    {
        for(int j=i; j < length; j+=key)
            out[idx++]= (*(data+j)) ? *(data + j) : (char) ' x ';
    }
    out[length] = 0;
    return out;
}



int main()
{
    //==================================1st===================
    char* msg = "thanksforthecourse";
    printf("msg \t\t- %s \n",msg);
    char* encrypt = caesarCipher(msg,5,1);
    printf("encrypt\t\t- %s \n",encrypt);
    char* decrypt = caesarCipher(encrypt,5,0);
    printf("decrypt\t\t- %s \n",decrypt);

    //==================================2nd===================

    char* msg1 = "swapCode";
    printf("msg2 \t\t- %s \n",msg1);
    char* encrypt1 = swapCode(msg1,5,1);
    printf("encrypt2 \t- %s \n",encrypt1);
    char* decrypt1 = swapCode(encrypt1,5,0);
    printf("decrypt2 \t- %s \n",decrypt1);

    return 0;
}
