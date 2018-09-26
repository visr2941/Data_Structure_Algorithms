#include <stdio.h>

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

/* Function to print an array */
void PrintArray(int arr[], int size)
{
    int i;
    
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    InsertionSort(arr, n);
    printf("Sorted array: \n");
    PrintArray(arr, n);
    return 0;
}


