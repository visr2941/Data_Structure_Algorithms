#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "backtracking.h"


/*****************************************************************************************
 ************************** Local Functions **********************************************
******************************************************************************************/

static void printSubsetHelper( char * arr, char * chosen, int ind, int size );
static void InsertAndArrageElement(char * inputArr, char ts, int pos, int size);
static void RemoveAndArrageElement(char * inputArr, int pos, int size);
static void PrintArrayElement(char * ipArr, int size);

static void PrintAllBinaryHelper(char * str, int digit);
static void PrintPermutationHelper(char * str, char * ts, int size, int * used);


/******************************************************************************************/


/*****************************************************************************************
 ************************** Global Functions Definitions *********************************
******************************************************************************************/

void PrintSubset(char * MainArr, int size)
{
    char arrMod[size];
    for(int i = 0; i < size; i++)
        arrMod[i] = MainArr[i];
        
    int * chosen = (int *) malloc(n*sizeof(int));
    printSubsetHelper(arrMod, size, chosen, 0);
    
}

void PrintAllBinary(int digit)
{
    char str[digit+1];
    str[digit] = '\0';
    PrintAllBinaryHelper(str, digit, 0);
}

void PrintPermutation(char * str, int size)
{
    char ts[size];
    int used[size];
    for(int i = 0; i < size; i++) used[i] = 0;
    PrintPermutationHelper(str, ts, size, used);
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

void printSubsetHelper(int * arr, int size, int * chosen, int cnt)
{
    //base condition
    if(size==0) {
        PrintArrayElement(chosen, cnt);
        return;
    }
    
    //choose
    chosen[cnt] = arr[0];
    
    //Explore rest of the array
    printSubsetHelper(arr+1, size-1, chosen, ++cnt);
    
    //Unchoose (by --cnt) and explore rest of the array
    printSubsetHelper(arr+1, size-1, chosen, --cnt);
}


static void PrintAllBinaryHelper(char * str, int digit, int cnt)
{
    if(digit == 0)
        printf("%s\n", str);
    else
    {
        str[cnt] = '0';
        PrintAllBinaryHelper(str, digit-1, cnt+1);
        str[cnt] = '1';
        PrintAllBinaryHelper(str, digit-1, cnt+1);
    }
}

static void PrintPermutationHelper(char * str, char * ts, int size, int * used)
{
    static int chCnt = 0;

    if(size==chCnt)
    {
        ts[chCnt] = 0;
        printf("%s\n", ts);
    }
    else 
    {
        for(int i = 0; i < size; i++)
        {
            if(used[i]==0) {
                //choose
                ts[chCnt++] = str[i];
                used[i] = 1;
                
                //explore
                PrintPermutationHelper(str, ts, size, used);
                
                //un-choose
                used[i] = 0;
                chCnt--;
            }
        }
    }
}

