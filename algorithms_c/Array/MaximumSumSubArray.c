//
//  MaximumSumSubArray.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/20/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "MaximumSumSubArray.h"

/*
 Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

 Example:

 Input: [-2,1,-3,4,-1,2,1,-5,4],
 Output: 6
 Explanation: [4,-1,2,1] has the largest sum = 6.
 
 Method 1 O(n):
    We keep track of maximum sum till (i-1)th element and compare that sum
    after adding to arr[i] and save the maximum of those two in the maximum
    sum till ith element.
 */

int MaximumSumSubArray(int* arr, int size)
{
    int globalMax = arr[0], maxLast = arr[0];
    
    for(int i = 1; i < size; i++)
    {
        if((arr[i] + maxLast) > arr[i])
        {
            maxLast = arr[i] + maxLast;
        }
        else
        {
            maxLast = arr[i];
        }
        
        if(globalMax < maxLast)
        {
            globalMax = maxLast;
        }
    }
    
    return globalMax;
}
