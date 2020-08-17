//
//  MedianUnionSortedArrays.c
//  coding_practice_ds_algo
//
//  Created by Vishal Srivastav on 7/3/20.
//  Copyright © 2020 Vishal Srivastav. All rights reserved.
//

#include "MedianUnionSortedArrays.h"

// C program to find kth element
// from two sorted arrays of same size
// Run time complexity is O(log(k))


#define MIN(x, y)  ((x > y) ? (y) : (x))
#define MAX(x, y)  ((x > y) ? (x) : (y))

double MedianUnionSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    if(nums1Size > nums2Size) {
        return MedianUnionSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    
    int isEven = (nums1Size+nums2Size)%2 == 0;
    int mid    = (nums1Size+nums2Size+1)/2;
    int min1, max1, min2, max2, part1, part2;
    double result = 0.0;
    
    int low = 0, high = nums1Size;
    
    while (low <= high) {
        part1 = (low+high)/2;
        part2 = mid-part1;
        
        min1 = (part1 == 0) ? INT_MIN : nums1[part1-1];
        max1 = (part1 == nums1Size) ? INT_MAX : nums1[part1];
        
        min2 = (part2 == 0) ? INT_MIN : nums2[part2-1];
        max2 = (part2 == nums2Size) ? INT_MAX : nums2[part2];
        
        if (max2 >= min1 && max1 >= min2) {
            result = (isEven == 1) ? (MAX(min1, min2) + MIN(max1, max2))/2.0 : MAX(min1, min2);
            break;
        } else if (max1 < min2) {
            low = part1+1;
        } else if (max2 < min1) {
            high = part1-1;
        }
    }

    return result;
}

/*
static int KthSmallestUnionSortedArray(int* arr1, int size1, int* arr2, int size2, int k)
{
    if(size1 > size2) return KthSmallestUnionSortedArray(arr2, size2, arr1, size1, k);
    
    // if the smallest array has 0 element, return the (k-1)th element
    // fron the other array
    if(size1 == 0 && size2 > 0) {
        return arr2[k-1];
    }
    
    // get the minimum of the first element of both the arrays
    // if k is 1
    if(k==1) {
        return MIN(arr1[0], arr2[0]);
    };
    
    // get the partition. array with smaller size to have partition after k/2 element
    // and the other array to have at k/2 or k/2+1 based on k even or odd
    int i = MIN(size1, k/2);
    int j = MIN(size2, k%2 == 0 ? k/2 : k/2+1);
    
    // check if you are at correct partition - yes: return the
    // maximum of elements from both array just before the partition
    if(j != size2 && i != size1) {
        if(arr1[i] >= arr2[j-1] && arr2[j] >= arr1[i-1]) {
            return MAX(arr1[i-1], arr2[j-1]);
        }
    }

    // since we are not at correct partition, look for the (k-x)th
    // element in rest of the array
    if(arr1[i-1] > arr2[j-1]) {
        return KthSmallestUnionSortedArray(arr1, i, arr2+j, size2-j, k-j);
    }
    else {
        return KthSmallestUnionSortedArray(arr1+i, size1-i, arr2, j, k-i);
    }
}

double MedianUnionSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int* arr1 = (nums1Size > nums2Size) ? nums2 : nums1;
    int* arr2 = (nums1Size > nums2Size) ? nums1 : nums2;
    int size1 = (nums1Size > nums2Size) ? nums2Size : nums1Size;
    int size2 = (nums1Size > nums2Size) ? nums1Size : nums2Size;
    int isEven = (size1+size2)%2 == 0;
    int mid    = (size1+size2)/2;
        
    if(isEven)
    {
        return (KthSmallestUnionSortedArray(arr1, size1, arr2, size2, mid) + KthSmallestUnionSortedArray(arr1, size1, arr2, size2, mid+1))/2.0;
    }
    else
    {
        return KthSmallestUnionSortedArray(arr1, size1, arr2, size2, mid+1);
    }
}
*/

/*
// below function works only when both the arrays are of same size
double MedianUnionSortedArrays(int* A, int size1, int* B, int size)
{
    if(size1 != size2) return 0.0;
 
    int l1 = size/2, l2 = (size%2 == 0) ? size/2 : size/2 + 1;

    while(l1 != 0)
    {
        if(A[l1] > B[l2-1] && B[l2] > A[l1-1])
        {
            return (MAX(A[l1-1], B[l2-1]) + MIN(A[l1], B[l2]))/2.0;
        }
        
        if(A[l1-1] > B[l2-1])
        {
            B = B + l2;
            size = l1/2;
            l2 = (l1%2 == 0) ? l1/2 : l1/2 + 1;
            l1 = size;
        }
        else
        {
            A = A + l1;
            size = (l2%2 == 0) ? l2/2 : l2/2 + 1;
            l1 = l2/2;
            l2 = size;
        }
    }

    return (A[0] + B[0])/2.0;

//    if(size1 != size2) return 0.0;
//    int l1 = size/2, l2 = (size%2 == 0) ? size/2 : size/2 + 1;
//
//    if(l1 == 0) return (A[0]+B[0])/2.0;
//
//    if(A[l1] > B[l2-1] && B[l2] > A[l1-1])
//    {
//        return (MAX(A[l1-1], B[l2-1]) + MIN(A[l1], B[l2]))/2.0;
//    }
//
//    if(A[l1-1] > B[l2-1])
//    {
//        return MedianUnionSortedArrays(A, B+l2, l1);
//    }
//    else
//    {
//        return MedianUnionSortedArrays(A+l1, B, l2);
//    }
    
}
*/
