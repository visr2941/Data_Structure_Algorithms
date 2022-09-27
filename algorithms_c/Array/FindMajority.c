//
//  FindMajority.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/20/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "FindMajority.h"

/*
 Method 1 O(nlogn) (will change the current array):
    a. Sort the array using MergeSort O(nlogn)
    b. Count the element to find the majaority element if any O(n)
 
 Method 2 O(nlogn) Divide and Conquer:
    a. Divide the array in two halves
        i. if there is an element which is majority in the original array
           it will be majority in either of the halves or both.
    b. Find the majority in the first halves if any otherwise return -1
       and look for majority in other half.
 
 Method 3 - Moore's Voting Algorithm O(n):
    a. Find the candidate for majority element O(n)
        i. Loop through the array
       ii. if count = 0, make the current element as candidate and increase the count.
      iii. if the next element is same as candidate, increase the count, otherwise
           decrease the count and if the count becomes zero, choose the current element
           as candidate and increase the count.
      iii. At the end of loop, if the count is non-zero, we have a candidate for majority
           element.
    b. Count the candidate in the array to find if it's a majority element or not. O(n)
 
*/

static int FindCandidate(int* arr, int size)
{
    int cand = -1;
    int count = 0;
    int index = -1;
    
    for(int i = 0; i < size; i++)
    {
        if(count == 0)
        {
            cand = arr[i];
            index = i;
            count++;
        }
        else {
            if(arr[i] == cand)
                count++;
            else
                count--;
        }
    }
    
    return (count == 0 ? -1 : index);
}

int FindMajority(int* arr, int size)
{
    int cnt = 0;
    int indexCand = FindCandidate(arr, size);
    
    for(int i = 0; i < size; i++)
        if(arr[i] == arr[indexCand])
            cnt++;
    
    if(cnt > size/2) return arr[indexCand];
    
    return -1;
}
