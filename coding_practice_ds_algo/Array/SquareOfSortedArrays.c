//
//  SquareOfSortedArrays.c
//  coding_practice_ds_algo
//
//  Created by Vishal Srivastav on 7/17/20.
//  Copyright © 2020 Vishal Srivastav. All rights reserved.
//

#include "SquareOfSortedArrays.h"

/*
Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted
non-decreasing order.

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/*
 Solution:
 Let's take example with negative and positive numbers, like:

 [-4, -2, 0, 1, 3]
 Since we need to put squeres in result array, we can consider that all numbers are positive (since: -4**2 = 4**2 = 16).
 Now our array looks like it sorted from middle to outside on both sides:

 [4, 2, 0, 1, 3]
 Now, we can have two pointers l to left most element, r to most right element.
 Create res result array same size as A.
 Move from right to left in res and past max(abs(A[l]), abs(A[r])), move correspondingly l++ or r--.
 */
void SquareOfSortedArrays(int* A, int ASize)
{
    if(ASize == 0) return;
    
    int temp;
    int* ret_arr = (int *) malloc(ASize*sizeof(int));
    
    for(int i = ASize-1, j = 0, k = ASize-1; i >= 0 && j < ASize && k >= 0; i--) {
        temp = MAX(abs(A[j]), abs(A[k]));
        if(temp == abs(A[j])) {
            j++;
        }
        else {
            k--;
        }
        ret_arr[i] = temp*temp;
    }
    
    memcpy(A, ret_arr, ASize*sizeof(int));
}

/*
void SquareOfSortedArrays(int* A, int ASize)
{
    if(ASize == 0) return;
        
    int pivot = 0, low, high, temp;
    int past = INT_MAX;
    
    for (int i = 0; i < ASize; i++) {
        if(A[i] >= 0 && past < 0) {
            pivot = i;
        }
        past = A[i];
        A[i] = A[i]*A[i];
    }
    
    high = pivot-1;
    low = 0;
    
    while(low < high) {
        temp = A[high];
        A[high] = A[low];
        A[low] = temp;
        low++;
        high--;
    }
    
    if(pivot != 0) {
        MergeArray(A, pivot, A+pivot, ASize-pivot);
    }    
}
*/
