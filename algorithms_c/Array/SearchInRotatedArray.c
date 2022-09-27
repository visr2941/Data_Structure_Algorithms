//
//  SearchInRotatedArray.c
//  coding_practice_ds_algo
//
//  Created by Vishal Srivastav on 7/21/20.
//  Copyright © 2020 Vishal Srivastav. All rights reserved.
//

#include "SearchInRotatedArray.h"

bool search_helper(int* arr, int size, int target)
{
    if(size == 0) return false;
    if(size == 1 && arr[0] != target) return false;
    
    int mid = size/2;
    
    if(arr[mid] == target) return true;
    else if(target > arr[mid]) return search_helper(arr+mid, size-mid, target);
    else return search_helper(arr, mid, target);
}

bool SearchInRotatedArray(int* nums, int numsSize, int target)
{
    if(numsSize == 0) return false;

    int piv_index = FindPivotRotatedArray(nums, numsSize);
    
    if(nums[piv_index] <= target && nums[numsSize-1] >= target) {
        return search_helper(nums+piv_index, numsSize-piv_index, target);
    }
    
    return search_helper(nums, piv_index, target);
}
