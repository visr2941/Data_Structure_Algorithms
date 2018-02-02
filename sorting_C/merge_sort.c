/* C program for Merge Sort */
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

void merge(int left[], int right[], int n1, int n2, int A[])
{
    int i=0, j=0, k=0;
    
    /* Merge the temp arrays back into arr[l..r]*/
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
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        A[k] = left[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        A[k] = right[j];
        j++;
        k++;
    }
    
}
 
void mergeSort(int arr[], int n)
{
    if (n < 2)
      return;
    int mid = n/2;
    
    int left[mid], right[n-mid];
    for(int i = 0; i < mid; i++)
        left[i] = arr[i];
    
    for(int i = 0; i < n-mid; i++)
        right[i] = arr[mid+i];    


    mergeSort(left, mid);
    mergeSort(right, n-mid);
    
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
