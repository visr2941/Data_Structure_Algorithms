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
        if (left[i] <= right[j])
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
