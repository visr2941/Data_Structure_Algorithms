//
//  FirstDuplicateInArray.c
//  practice_programming
//
//  Created by Vishal Srivastav on 2/13/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "FirstDuplicateInArray.h"

/*
    Given an array A that contains only number in the range from 1 to A.length, find the first duplicate number
    for which the 2nd occurence has the minimal index. In other words, if there are more than 1 duplicated numbers,
    return the number for which the 2nd occurence has a smaller index than the 2nd occurence of the number does.
    If there are no such element, return -1.
*/

/*
    Solution:
    1. Time Complexity O(n), Space Complexity O(n)
       Create a hash table of size A.length and loop through the array and update the Hash[val] to 1 (if it's 0)
       where val = A[i]. If it's already 1, return the index => that's the answer.
 
    2. Time Complexity O(n), Space Complexity O(1)
       Loop through the array and update the array => change A[val-1] to -A[val-1] where val = A[i] (if A[val-1] > 0).
       If A[val-1] is already negative, return the index => that's the answer.
*/

int FirstDuplicateInArray(int* arr, int size)
{
    int val;
    for (int i = 0; i < size; i++)
    {
        val = abs(arr[i]);
                
        if(arr[val-1] > 0)
        {
            arr[val-1] = 0 - arr[val-1];
        }
        // since array has only number between 1 to A.length
        else // checking for -ve
        {
            return val;
        }
    }
    
    return -1;
}
