//
//  MinimumLengthSubArrayWithSum.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/20/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "MinimumLengthSubArrayWithSum.h"

/*
 Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s.
 If there isn't one, return 0 instead.

 Example:

 Input: s = 7, nums = [2,3,1,2,4,3]
 Output: 2
 Explanation: the subarray [4,3] has the minimal length under the problem constraint.
 
 */

int MinimumLengthSubArrayWithSum(int* arr, int size, int sum)
{
    int i = 0, j = 0;
    int min_len = INT_MAX;
    int r_sum = 0;
    
    do {
        r_sum += arr[j];
        j++;

        if(j-i > min_len) {
            r_sum -= arr[i];
            i++;
        }
        
        while(r_sum >= sum && i < j) {
            min_len = j-i;
            r_sum -= arr[i];
            i++;
        }
        
        if(min_len == 1) break;
        
    } while (i < j && j < size);
    
    return min_len == INT_MAX ? 0 : min_len;
}
