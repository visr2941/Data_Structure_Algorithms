#include <stdio.h>

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

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
    printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    SelectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
