
void InsertionSort(int arr[], int n)
{
    int swapTemp, j;
    for (int i = 1; i < n; i++)
    {
        j = i;      
        
        while(arr[j-1] > arr[j])
        {
            swapTemp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = swapTemp;

            if(!(--j)) break;
        }
    }
}


/* 1. Start from the first elelment as current
** 2. Find the minimum in the rest of array including current
** 3. Replace the current with the minimum found
** 4. Loop for all the n elements of array
*/
void SelectionSort(int arr[], int n)
{
    int min, swapTemp;
    for (int i = 0; i < n-1; i++)
    {
        min = i;
        for(int j = i+1; j < n; j++)
        {
            if(arr[min] > arr[j])
                min = j;
        }
		
        swapTemp = arr[i];
        arr[i] = arr[min];
        arr[min] = swapTemp;
    }
}


/* Compleity O(n^2). */
void bubble_sort(int arr[], int size)
{
    int temp, i, j = 0, flag=0;
    
    /* In each iteration of outer loop, the biggest element of 
    ** the araay is "bubbled" out at the right side corner. In 
    ** the worst codnition when the array is reverse sorted,
    ** it will take N-1 outer loop execution, otherwise the flag
    ** will break the while loop as soon as no swapping is reqd 
    */
    while(j < size-1)
    {
        flag=0;
        
        /* Inner loop to bubble out the largest in the array */
        for(i = 0; i < size-1-j; i++)
            if(arr[i] > arr[i+1])
            {
                /* swapping and setting flag */
                temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
                flag = 1;
            }
        j++;
        
        //break the while loop if no swapping required (sorted)
        if(!flag)
            break;
    }
}

/* bubble sort using recursion */
/*
void bubble_sort(int arr[], int size)
{
    int i = 0, temp, flag=0;
    if(size==0)
        return;
    else
    {
        for(i = 0; i < size-1; i++)
            if(arr[i] > arr[i+1])
            {
                // swapping and setting flag
                temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
                flag = 1;
            }
            
        if(!flag)
            return;
        else
            bubble_sort(arr, size-1);
    }
}
*/


#include<stdlib.h>
#include<stdio.h>

 /* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

/* this function merge two sorted arrays into a single sorted
** array. */
void merge(int left[], int right[], int n1, int n2, int A[])
{
    int i=0, j=0, k=0;
    
    // Merge the temp arrays back into arr[l..r]
    while (i < n1 && j < n2)
    {
        if (left[i] <= R[j])
        {
            A[k] = left[i];
            i++;
        }
        else
        {
            A[k] = right[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of left[], if there are any
    while (i < n1)
    {
        A[k] = left[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of right[], if there are any
    while (j < n2)
    {
        A[k] = right[j];
        j++;
        k++;
    }
    
}

/* this sorting method is a O(nlogn) time complexity sorting
** algorithm. the main array is divided into two equal (unequal)
** halves and those are sorted first and then merged to get a 
** new sorted array. the main function calls itself recursively 
** to sort the divided arrays and then merge to get a single
** sorted array. */
void mergeSort(int arr[], int n)
{
    if (n < 2)
      return;
    int mid = n/2;
    
    // dividing array in two halves and filling them
    int left[mid], right[n-mid];
    for(int i = 0; i < mid; i++)
        left[i] = arr[i];
    
    for(int i = 0; i < n-mid; i++)
        right[i] = arr[mid+i];    

    // calling mergeSort() function recursively to sort
    // the new smaller arrays.
    mergeSort(left, mid);
    mergeSort(right, n-mid);
    
    // after two halves are sorted, merge them to get a
    // single merged sorted array
    merge(left, right, mid, n-mid, arr);
}


/* Driver program to test above functions */
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, arr_size);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
