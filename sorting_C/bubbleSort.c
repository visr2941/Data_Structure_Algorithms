#include <stdio.h>

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


int main()
{
    int A[] = {12, -11, 10, 9, 7, 3, 11};
	int N = sizeof(A)/sizeof(A[0]);
	
	for(int i = 0; i< N; i++)
	    printf("%d ", A[i]);
    printf("\n");
    bubble_sort(A, N);
	
	for(int i = 0; i< N; i++)
	    printf("%d ", A[i]);
	

    return 0;
}
