//
//  IsArrayMonotonic.c
//  coding_practice_ds_algo
//
//  Created by Vishal Srivastav on 7/17/20.
//  Copyright © 2020 Vishal Srivastav. All rights reserved.
//

#include "IsArrayMonotonic.h"

#define MON_INC_SEQ      (1U)
#define MON_DEC_SEQ      (2U)

/*
 An array is monotonic if it is either monotone increasing or monotone decreasing.

 An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

 Return true if and only if the given array A is monotonic.

 Example 1:

 Input: [1,2,2,3]
 Output: true
 Example 2:

 Input: [6,5,4,4]
 Output: true
 Example 3:

 Input: [1,3,2]
 Output: false
 Example 4:

 Input: [1,2,4,5]
 Output: true
 Example 5:

 Input: [1,1,1]
 Output: true
 
*/

bool IsArrayMonotonic(int* A, int ASize)
{
    unsigned char type_seq = false;
    
    if(A[0] <= A[ASize-1]) {
        type_seq = MON_INC_SEQ;
    } else {
        type_seq = MON_DEC_SEQ;
    }
    
    for (int i = 1; i < ASize; i++) {
        if(A[i-1] > A[i] && type_seq != MON_DEC_SEQ) return false;
        if(A[i-1] < A[i] && type_seq != MON_INC_SEQ) return false;
    }
    
    return true;
}

/*
 // Below is recursive solution for the same

 bool IsArrayMonotonic(int* A, int ASize)
 {
     if(ASize <= 1) return true;
     
     int mid = ASize/2;
     bool result_left = false;
     bool result_right = false;
     
     result_left = isMonotonic(A, mid);
     if (result_left)
     {
         result_right = isMonotonic(A+mid, ASize-mid);
     }

     if(result_left && result_right) {
         if (A[0] == A[mid-1]) {
             if ((A[mid-1] < A[mid] && A[mid] > A[ASize-1]) ||
                (A[mid-1] > A[mid] && A[mid] < A[ASize-1])) {
                 return false;
             }
         } else if (A[0] > A[mid-1]) {
             if ((A[mid-1] >= A[mid] && A[mid] < A[ASize-1]) ||
                (A[mid-1] < A[mid])) {
                 return false;
             }
         } else {
             if ((A[mid-1] <= A[mid] && A[mid] > A[ASize-1]) ||
                (A[mid-1] > A[mid])) {
                 return false;
             }
         }
            
     } else {
         return false;
     }
     
     return true;
 }
 
*/
