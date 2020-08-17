//
//  RotateArray.c
//  coding_practice_ds_algo
//
//  Created by Vishal Srivastav on 7/16/20.
//  Copyright © 2020 Vishal Srivastav. All rights reserved.
//

#include "RotateArray.h"

void RotateArray(int* nums, int numsSize, int k)
{
    if(numsSize == 1 || k == 0 || k == numsSize) return;
    
    if(k > numsSize) {
        k = k%numsSize;
    }
    
    int* aux_arr = (int *)malloc(k*sizeof(int));
    
    for(int i = 0, j = numsSize-k; i <= k-1 && j <= numsSize-1; i++, j++)
        aux_arr[i] = nums[j];
    
    for(int i = numsSize-k-1, j = numsSize-1; i >= 0 && j >= k; i--, j--)
        nums[j] = nums[i];
    
    for(int i = 0, j = 0; i <= k-1 && j <= k-1; i++, j++)
        nums[j] = aux_arr[i];
}
