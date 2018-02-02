#include <stdio.h>



/* this function will find the majority number in the array i.e count
** of that number is more than 50% else it will return -1. This algorithm
** works on the fact that the majority in main array will be definitely a
** majority in either of the half array. So, we check recursively to find
** the majority. Complexity is O(nlogn).
*/
/*int findMajority(int arr[], int start, int end)
{
    int maj, mid = (start + end)/2, i, maj1, maj2, cnt1=0, cnt2=0;
    
    //if array has only one number, that is the majority
    if(start >= end)
        return arr[start];
    else 
    {
        // recursive call to check the majority in 1st half 
        // and then second.
        maj1 = findMajority(arr, start, mid);
        maj2 = findMajority(arr, mid+1, end);

        // scan the array and count the value of maj2 & maj2
        for(i = 0; i <= end; i++)
        {
            if(arr[i]==maj1)
                cnt1++;
            else if(arr[i]==maj2) 
                cnt2++;
        }

        // based on the count, return the majority
        if(cnt2 > cnt1 && cnt2 > (end+1)/2)
            return maj2;
        else if(cnt1 > cnt2 && cnt1 > (end+1)/2)
            return maj1;
        else
            return -1;
    }
    
}*/

/* this function will find the majority element in the array i.e count
** of that eleemnt is more than 50% else it will return -1. This algorithm
** works on the fact that the majority in main array will be definitely a
** majority in either of the half array and to reduce the time complexity,
** we can only choose the half where majority exist, ignoring the other half.
** So, we check recursively to find the majority in one half. Complexity is O(n).
*/
int findMajority(int arr[], int start, int end)
{
    int maj, mid = (start + end)/2, i, maj1, maj2, cnt1=0, cnt2=0, temp1, temp2;
    
    //if array has only one number, that is the majority
    if(start >= end-1)
        if(arr[start]==arr[end])
            return arr[start];
        else 
            return -1;
    else 
    {
        // recursive call to check the majority in 1st half 
        // and if there is no majority then check the next
	// half. If there is a majority, check the count and 
	// if that is not greater than array length divided 
	// by 2, return -1 and check the next half, else that
	// element found in first half is the majority elem.
        maj1 = findMajority(arr, start, mid);
        if(maj1 == -1)
        {
            maj2 = findMajority(arr, mid+1, end);
            for(i = 0; i <= end; i++)
            {
                if(arr[i]==maj2) 
                    cnt2++;
            }

            // based on the count, return the majority
            if(cnt2 > (end+1)/2)
                return maj2;
            else
                return -1; 
        }
        else
        {
            for(i = 0; i <= end; i++)
            {
                if(arr[i]==maj1)
                    cnt1++;
            }

            // based on the count, return the majority
            if(cnt1 > (end+1)/2)
                return maj1;
            else
                return -1;
        }

    }
    
}



int main()
{
    int A[] = {12, 14,12,12,13,14,12, 14, 14};
	int N = sizeof(A)/sizeof(A[0]);
	
	for(int i = 0; i< N; i++)
	    printf("%d ", A[i]);
    printf("\n");
    
    int ans = findMajority(A, 0, N-1);
    
    printf("majority is %d\n", ans);

    return 0;
}
