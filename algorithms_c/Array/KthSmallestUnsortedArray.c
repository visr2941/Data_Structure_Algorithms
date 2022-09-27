//
//  KthSmallestUnsortedArray.c
//  coding_practice_ds_algo
//
//  Created by Vishal Srivastav on 7/12/20.
//  Copyright © 2020 Vishal Srivastav. All rights reserved.
//

#include "KthSmallestUnsortedArray.h"

/*
 One way of finding the kth smallest element is to
 create a k size Max heap and traverse through the
 given array to fill up the heap. After traversing
 the array, just return the top most element of heap.
 
 Always O(n) complexity.
 
 We can use a randonmized algorithm to find a pivot first
 as quickselect but better approach. Quick sort does have
 O(n^2) in worst case but the modified quick sort approach
 is only O(n) in the worst case.
*/

#define MIN(x, y)  ((x > y) ? (y) : (x))

int heap[1000] = {-1}, heapsize;

int * HeapInit()
{
    heapsize = 0;
    return heap;
}

int GetParentIndex(int child)
{
    return(child-1)/2;
}

void HeapifyDownMax(int * array, int parent, int size)
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
            HeapifyDownMax(array, largest, size);
        }
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

int KthSmallestFixedArray(int* arr, int size, int k)
{
    int ret = 0;
    int* kthArray = (int *) malloc(k*sizeof(int));

    HeapInit();
    
    for (int i = 0; i < size; i++) {
        kthArray[i] = INT_MAX;
    }

    for (int i = 0; i < size; i++) {
        if (i < k) {
            InsertElementInHeapMax(kthArray, arr[i]);
        } else if (kthArray[0] > arr[i]) {
            kthArray[0] = arr[i];
            HeapifyDownMax(kthArray, 0, k);
        }
    }
    
    ret = kthArray[0];
    
    free(kthArray);
    
    return ret;
}

int KthSmallestUnsortedArray(int* arr, int size, int k)
{
    if (size < 5) {
        return KthSmallestFixedArray(arr, size, k);
    }
    
    int pivot = -1, cnt_left = 0, cnt_equal = 0, cnt_right = 0;
    int numGrp = size/5;
    int ret;
    
    int* kthArray = (int *) malloc(numGrp*sizeof(int));
    
    for (int i = 0; i < numGrp; i++) {
        kthArray[i] = KthSmallestFixedArray(arr+i*5, 5, k/numGrp);
    }

    pivot = KthSmallestUnsortedArray(kthArray, numGrp, k/5);
        
    for (int i = 0; i < size; i++) {
        if(arr[i] < pivot) {
            cnt_left++;
        } else if (arr[i] == pivot) {
            cnt_equal++;
        } else {
            cnt_right++;
        }
    }

    int* leftArray = (int *) malloc(cnt_left*sizeof(int));
    int* rightArray = (int *) malloc(cnt_right*sizeof(int));

    // fill up the newly created left and right arrays
    for (int i = 0, j = 0, k = 0; i < size; i++) {
        if(arr[i] < pivot) {
            leftArray[j++] = arr[i];
        } else if(arr[i] > pivot) {
            rightArray[k++] = arr[i];
        }
    }
    
    // check the pivot and based o
    if((k-1) == cnt_left) {
        ret = arr[pivot];
    } else if(k <= cnt_left) {
        ret =  KthSmallestUnsortedArray(leftArray, cnt_left, k);
    } else if(k <= (cnt_left + cnt_equal)) {
        ret = arr[pivot];
    } else {
        ret = KthSmallestUnsortedArray(rightArray, cnt_right, k-cnt_equal-cnt_left);
    }
    
    free(kthArray);
    free(leftArray);
    free(rightArray);
    
    return ret;
}
