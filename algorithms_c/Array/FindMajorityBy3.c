//
//  FindMajorityBy3.c
//  coding_practice_ds_algo
//
//  Created by Vishal Srivastav on 7/14/20.
//  Copyright © 2020 Vishal Srivastav. All rights reserved.
//

#include "FindMajorityBy3.h"

int* FindMajorityBy3(int* nums, int numsSize, int* returnSize)
{
    if(numsSize < 2) {
        *returnSize = numsSize;
        return nums;
    }
    
    int cand1 = INT_MIN, cand2 = INT_MIN, cnt1 = 0, cnt2 = 0;
    int* arr = NULL;
    int size = numsSize/3;
    
    for(int i = 0; i < numsSize; i++) {
        if (cand1 == nums[i]) {
            cnt1++;
        } else if (cand2 == nums[i]) {
            cnt2++;
        } else if (cnt1 == 0) {
            cnt1++;
            cand1 = nums[i];
        } else if (cnt2 == 0) {
            cnt2++;
            cand2 = nums[i];
        }
        else {
            cnt1--;
            cnt2--;
        }
    }
    
    cnt1 = 0;
    cnt2 = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (cand1 == nums[i]) {
            cnt1++;
        }
        else if (cand2 == nums[i]) {
            cnt2++;
        }
    }
            
    if(cnt1 > size && cnt2 > size) {
        *returnSize = 2;
    } else if (cnt1 > size) {
        *returnSize = 1;
    } else if (cnt2 > size) {
        *returnSize = 1;
        cand1 = cand2;
    }
    else {
        *returnSize = 0;
    }
    
    if(*returnSize == 2) {
        arr = (int *) malloc(2*sizeof(int));
        arr[0] = cand1;
        arr[1] = cand2;
    } else if(*returnSize == 1) {
        arr = (int *) malloc(sizeof(int));
        arr[0] = cand1;
    }
    
    return arr;
}

