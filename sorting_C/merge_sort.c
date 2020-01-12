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
 void merge(int arr[], int n1, int n2, int n3)
 {
     int i=n1, j=n2+1, k=0;

     int size = n3-n1+1;
     int* res = (int *) malloc(size*sizeof(int));
     
     // Merge the temp arrays back into arr[l..r]
     while (i <= n2 && j <= n3)
     {
         if (arr[i] >= arr[j])
         {
             res[k] = arr[j];
             j++;
         }
         else
         {
             res[k] = arr[i];
             i++;
         }
         k++;
     }
  
     // Copy the remaining elements of left[], if there are any
     while (i <= n2)
     {
         res[k] = arr[i];
         i++;
         k++;
     }
     
     // Copy the remaining elements of right[], if there are any
     while (j <= n3)
     {
         res[k] = arr[j];
         j++;
         k++;
     }
     
     i = n1;
     j = 0;
     
     // copy the sorted array back to the main array
     while(i<=n3)
     {
         arr[i] = res[j];
         i++;
         j++;
     }
 }

 /* this sorting method is a O(nlogn) time complexity sorting
 ** algorithm. the main array is divided into two equal (unequal)
 ** halves and those are sorted first and then merged to get a
 ** new sorted array. the main function calls itself recursively
 ** to sort the divided arrays and then merge to get a single
 ** sorted array. */
 void mergeSort(int arr[], int l, int m)
 {
     if (l >= m)
       return;

     int mid = l + (m-l)/2;

     // calling mergeSort() function recursively to sort
     // the new smaller arrays.
     mergeSort(arr, l, mid);
     mergeSort(arr, mid+1, m);
     
     // after two halves are sorted, merge them to get a
     // single merged sorted array
     merge(arr, l, mid, m);
 }

/* Driver program to test above functions */
int main(int argc, const char * argv[])
{
    int arr[] = {12, 11, 13, 6, 5, 7, -3, 14, -32, 25, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size-1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
