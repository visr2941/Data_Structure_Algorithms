#include <stdio.h>

int heap[1000], heapsize;

int * HeapInit()
{
    heap[1000] = {0};
    heapsize = 0;
    return heap;
}

void PrintArray(int * arr, int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int GetParentIndex(int child)
{
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
            Heapify(array, largest, size);
        }
    }
}


void MakeMaxHeap(int * array, int size)
{
    for(int i = (size/2)-1; i >= 0; i=i-1)
    {
        Heapify(array, i, size);
    }
}


void HeapifyUpMax(int * array, int child, int size)
{
    int temp;
    
    int parent = GetParentIndex(child);

    if(parent < 0)
        return;
    else
    {
        if(array[child] > array[parent])
        {
            temp = array[child];
            array[child] = array[parent];
            array[parent] = temp;
            HeapifyUpMax(array, parent, size);
        }
    }
    
}

void InsertElementInHeapMax(int * arr, int element)
{
	arr[heapsize++] = element;
	HeapifyUpMax(arr, heapsize-1, heapsize);
}


void HeapSortMax(int * array, int size)
{
    int temp;

    if(size == 0)
        return;
    else
    {
        temp = array[0];
        array[0] = array[size-1];
        array[size-1] = temp;
        size = size -1;
        Heapify(array, 0, size);
        HeapSortMax(array, size);
    }
}

int SearchElementInHeapMax(int * arr, int data, int index)
{
    if(arr > heap+heapsize-1)
        return 0;
    else if (arr[0] < data)
        return 0;
    else if(arr[0] == data)
        return 1;
    
    int i1 = 2*index+1;
    int i2 = 2*index+2;
    
    if(arr[i1] > data && arr[i2] < data)
        return SearchElementInHeapMax(arr+i1, data, i1);
    else if (arr[i2] > data && arr[i1] < data)
        return SearchElementInHeapMax(arr+i2, data, i2);
    else 
        return (SearchElementInHeapMax(arr+i1-index, data, i1)||SearchElementInHeapMax(arr+i2-index, data, i2));
}


int main()
{
    int * arr = HeapInit();
    //int arr[3] = {5, 12, 3};
    InsertElementInHeapMax(arr, 40);
    InsertElementInHeapMax(arr, 4);
    InsertElementInHeapMax(arr, 14);
    InsertElementInHeapMax(arr, 34);
    //InsertElementInHeapMax(arr, 63);
    InsertElementInHeapMax(arr, 632);
    InsertElementInHeapMax(arr, 630);
    InsertElementInHeapMax(arr, 69);
    InsertElementInHeapMax(arr, -60);
    InsertElementInHeapMax(arr, -32);
    InsertElementInHeapMax(arr, 30);
    PrintArray(arr, heapsize);
    //MakeMaxHeap(arr, 12);
    //PrintArray(arr, 12);
    //HeapSortMax(arr, heapsize);
    PrintArray(arr, heapsize);
    printf("present %d\n", SearchElementInHeapMax(arr, -60, 0));
    return 0;
}