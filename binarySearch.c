#include <stdio.h>
#include <malloc.h>

/* function to search an element in a sorted array*/
int BinarySearch(int arr[], int start, int end, int data)
{
    int mid=(start+end)/2;
    
    // the array index should in range, otherwise return -1
    if(start>end)
        return -1;
    /* if the middle element of the array is smaller than the
    ** value being searched, start looking in the right half 
    ** and if the it's larger, look into the left half until 
    ** the value is found or the start & end criterion fails
    */
    else if(data > arr[mid])
        BinarySearch(arr, mid+1, end, data);
    else if (data < arr[mid])
        BinarySearch(arr, 0, mid-1, data);
    else
        return mid;
}

/* binary search without recursion */
/*
int BinarySearch(int arr[], int size, int data)
{
    int start=0, end=size-1, mid=0;
    
    while(start <= end)
    {
        mid = (start+end)/2;
        if(data > arr[mid])
            start = mid+1;
        else if (data < arr[mid])
            end = mid-1;
        else 
            return mid;
    }
    return -1;
}
*/

int main()
{
    int A[] = {2, 5, 6, 8, 9, 10};
	int N = sizeof(A)/sizeof(A[0]);
	int data = 0;
	
	int index = BinarySearch(A, 0, N-1, data);
	
	if (index != -1)
	    printf("Element found at index %d", index);
	else
		printf("Element not found in the array");
	

    return 0;
}
