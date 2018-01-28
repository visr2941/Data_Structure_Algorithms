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

void merge(int L[], int R[], int n1, int n2, int A[])
{
    int i, j, k;
    
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = 0; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
    
}
 
void mergeSort(int arr[], int n)
{
    if (n < 2)
      return;
    int mid = n/2;
    
    int L[mid], R[n-mid];
    for(int i = 0; i < mid; i++)
        L[i] = arr[i];
    
    for(int i = 0; i < n-mid; i++)
        R[i] = arr[mid+i];    
    
    int sizeL = sizeof(L)/sizeof(L[0]);
    int sizeR = sizeof(R)/sizeof(R[0]);

    mergeSort(L, sizeL);
    mergeSort(R, sizeR);
    
    merge(L, R, sizeL, sizeR, arr);
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