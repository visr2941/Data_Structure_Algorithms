//
//  KthSmallestUnionSortedArray.c
//  coding_practice_ds_algo
//
//  Created by Vishal Srivastav on 7/1/20.
//  Copyright © 2020 Vishal Srivastav. All rights reserved.

#include "KthSmallestUnionSortedArray.h"

#define MIN(x, y)  ((x > y) ? (y) : (x))
#define MAX(x, y)  ((x > y) ? (x) : (y))

int KthSmallestUnionSortedArray(int* arr1, int size1, int* arr2, int size2, int k)
{
    if(size1 > size2) return KthSmallestUnionSortedArray(arr2, size2, arr1, size1, k);
    
    // if the smallest array has 0 element, return the (k-1)th element
    // fron the other array
    if (size1 == 0 && size2 > 0) {
        return arr2[k-1];
    }
    
    // get the minimum of the first element of both the arrays
    // if k is 1
    if (k==1) {
        return MIN(arr1[0], arr2[0]);
    };
    
    // get the partition. array with smaller size to have partition after k/2 element
    // and the other array to have at k/2 or k/2+1 based on k even or odd
    int i = MIN(size1, k/2);
    int j = MIN(size2, k%2 == 0 ? k/2 : k/2+1);
    
    // check if you are at correct partition - yes: return the
    // maximum of elements from both array just before the partition
    if (j != size2 && i != size1) {
        if(arr1[i] >= arr2[j-1] && arr2[j] >= arr1[i-1]) {
            return MAX(arr1[i-1], arr2[j-1]);
        }
    }

    // since we are not at correct partition, look for the (k-x)th
    // element in rest of the array
    if (arr1[i-1] > arr2[j-1]) {
        return KthSmallestUnionSortedArray(arr1, i, arr2+j, size2-j, k-j);
    }
    else {
        return KthSmallestUnionSortedArray(arr1+i, size1-i, arr2, j, k-i);
    }
}

