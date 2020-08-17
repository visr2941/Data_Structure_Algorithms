//
//  PermutationArray.c
//  coding_practice_ds_algo
//
//  Created by Vishal Srivastav on 7/20/20.
//  Copyright © 2020 Vishal Srivastav. All rights reserved.
//

#include "PermutationArray.h"
#include "PrintArray.h"

static int curr_sel = 0;

static void PermutationArray_Helper(int* arr, int size, int* sel_arr)
{
    if(size == 0) {
        PrintArray(sel_arr, curr_sel);
        return;
    }
    
    int temp;
    for (int i = 0; i < size; i++) {
        // select
        sel_arr[curr_sel++] = arr[i];
        
        temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        
        // explore
        PermutationArray_Helper(arr+1, size-1, sel_arr);
        
        // unselect
        curr_sel--;
        
        temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
    }
}

void PermutationArray(int* nums, int numsSize)
{
    int* select_arr = (int *) malloc(numsSize*sizeof(int));
    
    PermutationArray_Helper(nums, numsSize, select_arr);
    
    free(select_arr);
    
    return;
}
