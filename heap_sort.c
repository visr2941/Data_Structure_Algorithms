/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void PrintArray(int * arr, int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int GetParentIndex(int child)
{
    if(child%2 == 0)
        return (child/2 -1);
    else
        return(child-1)/2;
}


void HeapifyDown_Max(int * array, int parent, int size)
{
    int temp;
    while(1)
    {
        int i1 = 2*parent + 1;
        int i2 = 2*parent + 2;
        
        if(i1 < size && i2 < size && (array[parent] < array[i1] || array[parent] < array[i2]))
        {
            if(array[i1] > array[i2])
            {
                temp = array[parent];
                array[parent] = array[i1];
                array[i1] = temp;
                parent = i1;
            }
            else
            {
                temp = array[parent];
                array[parent] = array[i2];
                array[i2] = temp;
                parent = i2;
            }
        }
        else if(i1 < size && (array[parent] < array[i1]))
        {
            temp = array[parent];
            array[parent] = array[i1];
            array[i1] = temp;
            parent = i1;
        }
        else
            break;
    }
}


void HeapifyUp_Max(int * array, int child, int size)
{
    int temp, parent;
    while(1)
    {
        if((parent = GetParentIndex(child)) < 0)
            break;
        
        if(array[parent] < array[child])
        {
            temp = array[parent];
            array[parent] = array[child];
            array[child] = temp;
            child = parent;
        }
        else
            break;
    }
}


void MakeHeap_Max(int * array, int size)
{

    for(int i = 0; i < size; i++)
    {
        HeapifyUp_Max(array, i, size);
        int i1 = 2*i + 1;
        int i2 = 2*i + 2;
        HeapifyDown_Max(array, i1, size);
        HeapifyDown_Max(array, i2, size);
    }
}


void HeapSort_Max(int * array, int size)
{
    int temp;
    int sizetemp = size;
    for(int i = 0; i < sizetemp; i++)
    {
        temp = array[0];
        array[0] = array[size-1];
        array[size-1] = temp;
        size = size -1;
        HeapifyDown_Max(array, 0, size);
    }
}


void HeapifyDown_Min(int * array, int parent, int size)
{
    int temp;
    while(1)
    {
        int i1 = 2*parent + 1;
        int i2 = 2*parent + 2;
        
        if(i1 < size && i2 < size && (array[parent] > array[i1] || array[parent] > array[i2]))
        {
            if(array[i1] < array[i2])
            {
                temp = array[parent];
                array[parent] = array[i1];
                array[i1] = temp;
                parent = i1;
            }
            else
            {
                temp = array[parent];
                array[parent] = array[i2];
                array[i2] = temp;
                parent = i2;
            }
        }
        else if(i1 < size && (array[parent] > array[i1]))
        {
            temp = array[parent];
            array[parent] = array[i1];
            array[i1] = temp;
            parent = i1;
        }
        else
            break;
    }
}


void HeapifyUp_Min(int * array, int child, int size)
{
    int temp, parent;
    while(1)
    {
        if((parent = GetParentIndex(child)) < 0)
            break;
        
        if(array[parent] > array[child])
        {
            temp = array[parent];
            array[parent] = array[child];
            array[child] = temp;
            child = parent;
        }
        else
            break;
    }
}


void MakeHeap_Min(int * array, int size)
{

    for(int i = 0; i < size; i++)
    {
        HeapifyUp_Min(array, i, size);
        int i1 = 2*i + 1;
        int i2 = 2*i + 2;
        HeapifyDown_Min(array, i1, size);
        HeapifyDown_Min(array, i2, size);
    }
}

void HeapSort_Min(int * array, int size)
{
    int temp;
    int sizetemp = size;
    for(int i = 0; i < sizetemp; i++)
    {
        temp = array[0];
        array[0] = array[size-1];
        array[size-1] = temp;
        size = size -1;
        HeapifyDown_Min(array, 0, size);
    }
}


int main()
{
    int arr[11] = {5, 12, 64, 1, 37, 90, 91, 97, 32, 87, 23};
    
    PrintArray(arr, 11);
    MakeHeap_Min(arr, 11);
    PrintArray(arr, 11);
    HeapSort_Min(arr, 11);
    PrintArray(arr, 11);
    return 0;
}
