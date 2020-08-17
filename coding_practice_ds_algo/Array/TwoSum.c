//
//  TwoSum.c
//  coding_practice_ds_algo
//
//  Created by Vishal Srivastav on 7/15/20.
//  Copyright © 2020 Vishal Srivastav. All rights reserved.
//

#include "TwoSum.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* TwoSum(int* nums, int numsSize, int target)
{
    int* arr = NULL;
    bool flag1 = true, flag2 = true;
    
    if(numsSize < 2) {
        return NULL;
    } else if(numsSize == 2) {
        if(target == (nums[0] + nums[1])) {
            arr = (int *) malloc(2*sizeof(int));
            arr[0] = 0;
            arr[1] = 1;
            return arr;
        }
    }
    
    int* aux_arr = (int *) malloc(numsSize*sizeof(int));
    memcpy((void *) aux_arr, (void *) nums, numsSize*sizeof(int));
    
    MergeSortArray(aux_arr, numsSize);
    
    int i = 0, j = numsSize-1, temp;
    
    while(i < j) {
        temp = (aux_arr[i] + aux_arr[j]);
        if (temp > target) {
            j--;
        } else if (temp < target) {
            i++;
        } else {
            arr = (int *) malloc(2*sizeof(int));
            arr[0] = aux_arr[i];
            arr[1] = aux_arr[j];
            break;
        }
    }
    
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == arr[0] && flag1) {
            arr[0] = i;
            flag1 = false;
        }
        else if(nums[i] == arr[1] && flag2) {
            arr[1] = i;
            flag2 = false;
        }
        
        if(!flag1 && !flag2) break;
    }
    
    return arr;
}
