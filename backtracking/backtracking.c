#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "backtracking.h"


/*****************************************************************************************
 ************************** Local Functions **********************************************
******************************************************************************************/

static void printSubsetHelper( char * arr, char * chosen, int size );
static void InsertAndArrageElement(char * inputArr, char ts, int pos, int size);
static void RemoveAndArrageElement(char * inputArr, int pos, int size);
static void PrintArrayElement(char * ipArr, int size);

static void PrintAllBinaryHelper(char * str, int digit);
static void PrintPermutationHelper(char * str, char * ts, int ind, int size); 


/******************************************************************************************/


/*****************************************************************************************
 ************************** Global Functions Definitions *********************************
******************************************************************************************/

void PrintSubset(char * MainArr, int size)
{
    char arrMod[size];
    char chosenNew[size];
    
    for(int i = 0; i < size; i++)
        arrMod[i] = MainArr[i];
        
    printSubsetHelper(arrMod, chosenNew, 0, size);
    
}

void PrintAllBinary(int digit)
{
    char str[digit+1];
    str[digit] = '\0';
    PrintAllBinaryHelper(str, digit);
}

void PrintPermutation(char * str, int size)
{
    char ts[size+1];
    PrintPermutationHelper(str, ts, size);
}



/*****************************************************************************************
 ************************** Local Functions Definitions **********************************
******************************************************************************************/

static void PrintArrayElement(char * ipArr, int size)
{
    printf("{");
    for (int i = 0; i < size; i++)
    {
        printf("%c, ", ipArr[i]);
        //printf("ipArr[%d] %c, size %d\n", i, ipArr[i], size);
    }
    if(size==0)
        printf("}\n");
    else
        printf("\b\b}\n");
}


static void printSubsetHelper( char * arr, char * chosen, int ind, int size )
{    
    
    static int chsCnt = 0;
    
    if (ind==size)
    {
        PrintArrayElement(chosen, chsCnt);
    }
    else
    {
        printSubsetHelper(arr, chosen, ind+1, size);
        
        chosen[chsCnt++] = arr[ind];

        printSubsetHelper(arr, chosen, ind+1, size);

        chsCnt--;
    }

}



static void PrintAllBinaryHelper(char * str, int digit)
{
    static int cnt = digit;
    
    if(digit == 0)
        printf("%s\n", str);
    else
    {
        str[cnt-digit] = '0';    
        PrintAllBinaryHelper(str, digit-1);
        str[cnt-digit] = '1';    
        PrintAllBinaryHelper(str, digit-1);   
    }
}

static void RemoveAndArrageElement(char * inputArr, int pos, int size)
{
    int temp = pos;
    bool flag;
    
    while(temp < size)
    {
        //printf("check\n");
        inputArr[temp] = inputArr[temp+1];
        temp++;
        flag = 1;
    }
    if(flag)
        inputArr[temp] = 0;
}

static void InsertAndArrageElement(char * inputArr, char ts, int pos, int size)
{
    int temp = size;
    bool flag;
    
    while(temp > pos)
    {
        inputArr[temp] = inputArr[temp-1];
        temp--;
        flag = 1;
    }
    
    inputArr[temp] = ts;    
}


static void PrintPermutationHelper(char * str, char * ts, int size)
{
    static int chCnt = 0;

    if(size==0)
    {
        printf("%s\n", ts);
    }
    else 
    {
        for(int i = 0; i < size; i++)
        {
            //choose
            ts[chCnt++] = str[i];
            RemoveAndArrageElement(str, i, size);
            
            //explore
            PrintPermutationHelper(str, ts, size-1);
            
            //un-choose
            InsertAndArrageElement(str, ts[--chCnt], i, size);
            RemoveAndArrageElement(ts, chCnt, size);
        }
    }
}

