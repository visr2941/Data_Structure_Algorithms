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


void Heapify(int * array, int parent, int size)
{
    int temp, largest = parent;
    
    int i1 = 2*parent+1;
    int i2 = 2*parent+2;
    

    if(i1 >= size && i2 >= size)
        return;
    else if(i1 < size)
    {
        if(i2 < size && (array[i2] > array[parent]) && (array[i2] > array[i1]))
            largest = i2;
        else if (array[i1] > array[parent])
            largest = i1;

        if(largest != parent)
        {
            temp = array[largest];
            array[largest] = array[parent];
            array[parent] = temp;
        }
        else
            largest++;
    }
    else 
        largest++;

    Heapify(array, largest, size);
}


void MakeMaxHeap(int * array, int size)
{
    for(int i = (size/2)-1; i >= 0; i=i-1)
    {
        Heapify(array, i, size);
    }
}


void HeapSortMax(int * array, int size)
{
    int temp;
    int sizetemp = size;
    for(int i = 0; i < sizetemp; i++)
    {
        temp = array[0];
        array[0] = array[size-1];
        array[size-1] = temp;
        size = size -1;
        Heapify(array, 0, size);
    }
}


int main()
{
    int arr[12] = {5, 12, 64, 1, 37, 90, 23, 80, 34, 56, 24, -12};
    //int arr[3] = {5, 12, 3};
    PrintArray(arr, 12);
    MakeMaxHeap(arr, 12);
    PrintArray(arr, 12);
    HeapSortMax(arr, 12);
    PrintArray(arr, 12);
    return 0;
}
