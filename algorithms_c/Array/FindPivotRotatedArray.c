//
//  FindPivotRotatedArray.c
//  coding_practice_ds_algo
//
//  Created by Vishal Srivastav on 7/21/20.
//  Copyright © 2020 Vishal Srivastav. All rights reserved.
//

#include "FindPivotRotatedArray.h"

bool CheckForUnequal(int* arr, int i, int j)
{
    for (int k = i; k <= j; k++) {
        if(arr[k] != arr[i]) return true;
    }
    return false;
}

int FindPivotRotatedArray(int* arr, int size)
{
    int piv_ind = -1;
    int low = 0, high = size, mid = 0;
    
    if(size == 1) return 0;
    
    while(low < high) {
        if((high-low) == 2) {
            piv_ind = arr[low] <= arr[high-1] ? low : high-1;
            break;
        }
        
        mid = (low+high)/2;
        
        if(arr[low] < arr[high-1]) {
            piv_ind = low;
            break;
        } else if(arr[mid] < arr[high-1]) {
            high = mid+1;
        } else if (arr[mid] > arr[low]){
            low = mid;
        } else if(arr[mid] == arr[high-1]) {
            if(true == CheckForUnequal(arr, mid, high-1)) {
                low = mid;
            } else {
                high = mid+1;
            }
        } else if (arr[mid] == arr[low]) {
            if(true == CheckForUnequal(arr, low, mid)) {
                high = mid+1;
            } else {
                low = mid;
            }
        }
    }

    return piv_ind;
}
