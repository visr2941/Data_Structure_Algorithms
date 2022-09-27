//
//  main.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/12/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "BitManipulationHeader.h"
#include "GeneralProblemsHeader.h"
#include "LinkList.h"
#include "BinaryTree.h"
#include "ArrayHeader.h"
#include "Graph.h"
#include "MergeSortArray.h"

/*
int main()
{
    Graph* graph = CreateGraph(6);
    
    AddEdges(graph, 0, 1);
    AddEdges(graph, 1, 3);
    AddEdges(graph, 1, 2);
    AddEdges(graph, 2, 4);
    AddEdges(graph, 2, 5);
    AddEdges(graph, 3, 4);
    
    PrintAdjcancyList(graph);
    
    printf("\n");
    
    DFS(graph, 0);
    DFS(graph, 1);
    DFS(graph, 2);
    DFS(graph, 3);
    DFS(graph, 4);
    DFS(graph, 5);
    
    return 0;
}
 */

/*
int main()
{
    int arr[] = {1, 3, 4, 2, 3, 5};
    int n = sizeof(arr) / sizeof(int);
    
    PrintArray(arr, n);
    printf("first duplicate number in array %d\n", FirstDuplicateInArray(arr, n));
    return 0;
}
*/

/*
int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(int);
    
    printf("max sum %d\n", MaximumSumSubArray(arr, 8));
    return 0;
}
*/

/*
int main()
{
//    int a[] = {5334,6299,4199,9663,8945,3566,9509,3124,6026,6250,7475,5420,9201,9501,38,5897,4411,6638,9845,161,9563,8854,3731,5564,5331,4294,3275,1972,1521,2377,3701,6462,6778,187,9778,758,550,7510,6225,8691,3666,4622,9722,8011,7247,575,5431,4777,4032,8682,5888,8047,3562,9462,6501,7855,505,4675,6973,493,1374,3227,1244,7364,2298,3244,8627,5102,6375,8653,1820,3857,7195,7830,4461,7821,5037,2918,4279,2791,1500,9858,6915,5156,970,1471,5296,1688,578,7266,4182,1430,4985,5730,7941,3880,607,8776,1348,2974,1094,6733,5177,4975,5421,8190,8255,9112,8651,2797,335,8677,3754,893,1818,8479,5875,1695,8295,7993,7037,8546,7906,4102,7279,1407,2462,4425,2148,2925,3903,5447,5893,3534,3663,8307,8679,8474,1202,3474,2961,1149,7451,4279,7875,5692,6186,8109,7763,7798,2250,2969,7974,9781,7741,4914,5446,1861,8914,2544,5683,8952,6745,4870,1848,7887,6448,7873,128,3281,794,1965,7036,8094,1211,9450,6981,4244,2418,8610,8681,2402,2904,7712,3252,5029,3004,5526,6965,8866,2764,600,631,9075,2631,3411,2737,2328,652,494,6556,9391,4517,8934,8892,4561,9331,1386,4636,9627,5435,9272,110,413,9706,5470,5008,1706,7045,9648,7505,6968,7509,3120,7869,6776,6434,7994,5441,288,492,1617,3274,7019,5575,6664,6056,7069,1996,9581,3103,9266,2554,7471,4251,4320,4749,649,2617,3018,4332,415,2243,1924,69,5902,3602,2925,6542,345,4657,9034,8977,6799,8397,1187,3678,4921,6518,851,6941,6920,259,4503,2637,7438,3893,5042,8552,6661,5043,9555,9095,4123,142,1446,8047,6234,1199,8848,5656,1910,3430,2843,8043,9156,7838,2332,9634,2410,2958,3431,4270,1420,4227,7712,6648,1607,1575,3741,1493,7770,3018,5398,6215,8601,6244,7551,2587,2254,3607,1147,5184,9173,8680,8610,1597,1763,7914,3441,7006,1318,7044,7267,8206,9684,4814,9748,4497,2239};
    int a[] = {1, 2, 3};
    int n = sizeof(a) / sizeof(int);
    int sum = 7; //697439;
    
    PrintArray(a, n);
    
    printf("Minimum length of subarray with sum %d is %d\n", sum, MinimumLengthSubArrayWithSum(a, n, sum));
    
    return 0;
}
*/

/*
int main()
{
    int a[] = {1, 2, 3, 6};
    int b[] = {4, 6, 8, 10};
    int n = sizeof(a) / sizeof(int);
    
    printf("Median %d\n", MedianOfSortedArraysSameSize(a, b, n));
    
    return 0;
}
*/

/*
int main()
{
    int a[] = {4, 7, 4, 4, 7, 4, 4, 9, 4, 3};
    int size = (sizeof(a))/sizeof(a[0]);
    
    PrintArray(a, size);
    int majElem = FindMajority(a, size);
    
    if(majElem != -1)
        printf("Majority element is %d\n", majElem);
    else
        printf("There is no majority element in this array\n");

    return 0;
}
*/

/*
int main()
{
    int in[] = { 1, 2, 3, 4, 5, 6 };
    int pre[] = { 4, 2, 1, 3, 6, 5 };
    
    int size = sizeof(in)/sizeof(in[0]);
    
    printf("Below is the pre-order array:\n");
    PrintArray(pre, size);
    printf("Below is the in-order array:\n");
    PrintArray(in, size);
    
    BT_Node* root = ConstructUniqueBTPreInOrder(in, pre, size);
    
    int ht = FindHeightBT(root);
    
    printf("Height of created binary tree is %d\n", ht);
    
    printf("Inorder traversal of the binaary tree:\n");
    PrintInOrderBT(root);
    printf("\n");
    
    printf("Level order traversal of the binaary tree:\n");
    PrintLevelOrderBT(root);
    printf("\n");
    
    printf("Pre order traversal of the binaary tree:\n");
    PrintPreOrderBT(root);
    printf("\n");
    
    return 0;
}
*/

/*
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    printf("Below is the array:\n");
    PrintArray(arr, size);
    
    BT_Node* root = ConstructBalancedBTInOrder(arr, size);
    
    int ht = FindHeightBT(root);
    
    printf("Height of created binary tree is %d\n", ht);
    
    printf("Inorder traversal of the binaary tree:\n");
    PrintInOrderBT(root);
    printf("\n");
    
    printf("Level order traversal of the binaary tree:\n");
    PrintLevelOrderBT(root);
    printf("\n");
    
    printf("Pre order traversal of the binaary tree:\n");
    PrintPreOrderBT(root);
    printf("\n");
    
    return 0;
}
*/

/*
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    printf("Below is the array:\n");
    PrintArray(arr, size);
    
    BT_Node* root = ConstructFullBTLevelOrder(arr, size);
    
    int ht = FindHeightBT(root);
    
    printf("Height of created binary tree is %d\n", ht);
    
    printf("Level order traversal of the binaary tree:\n");
    PrintLevelOrderBT(root);
    
    printf("Inorder traversal of the binaary tree:\n");
    PrintInOrderBT(root);
    
    return 0;
}
*/

/*
int main()
{
    Node* head1 = CreateList(25);
    head1 = InsertAtFront(head1, 17);
    head1 = InsertAtFront(head1, 15);
    head1 = InsertAtFront(head1, 11);
    head1 = InsertAtFront(head1, 15);
    head1 = InsertAtFront(head1, 17);
    head1 = InsertAtFront(head1, 25);
    
    PrintList(head1);
    
    head1 = RemoveDuplicate(head1);
    PrintList(head1);
    
    head1 = MergeSort(head1);
    PrintList(head1);
    
    head1 = RemoveDuplicate(head1);
    PrintList(head1);

    return 0;
}
*/

/*
int main()
{
    Node* head1 = CreateList(25);
    head1 = InsertAtFront(head1, 17);
    head1 = InsertAtFront(head1, 15);
    head1 = InsertAtFront(head1, 11);
    head1 = InsertAtFront(head1, 15);
    head1 = InsertAtFront(head1, 17);
    //head1 = InsertAtFront(head1, 25);
    
    PrintList(head1);
    
    head1 = MergeSort(head1);
    
    PrintList(head1);

    return 0;
}
*/

/*
int main()
{
    Node* head1 = CreateList(25);
    head1 = InsertAtFront(head1, 17);
    head1 = InsertAtFront(head1, 15);
    head1 = InsertAtFront(head1, 11);
    head1 = InsertAtFront(head1, 15);
    head1 = InsertAtFront(head1, 17);
    head1 = InsertAtFront(head1, 25);
    
    PrintList(head1);
    
    printf("Link list is palindrome Yes(1)/No(0): %d\n", IsPalindromeLinkList(head1));

    return 0;
}
*/

/*
int main()
{
    Node* head1 = CreateList(25);
    head1 = InsertAtFront(head1, 17);
    head1 = InsertAtFront(head1, 15);
    head1 = InsertAtFront(head1, 11);
    head1 = InsertAtFront(head1, 6);
    head1 = InsertAtFront(head1, 4);
    head1 = InsertAtFront(head1, 2);
    
    PrintList(head1);
    
    Node* head2 = ReverseLinkList(head1);
    
    PrintList(head2);
    
    Node* head3 = ReverseLinkListRecursive(head2);
    
    PrintList(head3);

    return 0;
}
*/

/*
int main()
{
    Node* head1 = CreateList(25);
    head1 = InsertAtFront(head1, 17);
    head1 = InsertAtFront(head1, 15);
    head1 = InsertAtFront(head1, 11);
    head1 = InsertAtFront(head1, 6);
    head1 = InsertAtFront(head1, 4);
    head1 = InsertAtFront(head1, 2);
    
    PrintList(head1);
    
    Node* head2 = CreateList(215);
    head2 = InsertAtFront(head2, 117);
    head2 = InsertAtFront(head2, 9);
    head2 = InsertAtFront(head2, 3);
    head2 = InsertAtFront(head2, 2);
    head2 = InsertAtFront(head2, 1);
    head2 = InsertAtFront(head2, 0);
    
    PrintList(head2);
    
    Node* head3 = MergeSortedList(head1, head2);
    
    PrintList(head3);
    
    return 0;
}
*/

/*
int main()
{
    Node* head = CreateList(3);
    head = InsertAtFront(head, 7);
    head = InsertAtFront(head, 5);
    head = InsertAtFront(head, 4);
    head = InsertAtFront(head, 6);
    head = InsertAtFront(head, 7);
    head = InsertAtFront(head, 7);
    
    PrintList(head);
    
    head = DeleteSingleOccurence(head, 3);
    
    PrintList(head);
    
    head = DeleteSingleOccurence(head, 7);
    
    PrintList(head);
    
    return 0;
}
*/
/*
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
*/

/*
int main()
{
    uint32 num1 = 10;
    
    printf("%u => %u\n", num1, ReverseDigits(num1));
    
    return 0;
}
*/

/*
int main()
{
    uint32 num1 = 10, num2 = 6;
    
    printf("%u^%u = %f\n", num1, num2, CalculatePower(10.0, num2));
    
    return 0;
}
*/

/*
int main()
{
    uint32 num1 = 11, num2 = 6;
    
    printf("%u * %u = %llu\n", num1, num2, MultiplyUsingBitManipulation(num1, num2));
    
    return 0;
}
*/

/*
int main()
{
    uint32 num = 6;
    
    printf("%d %d\n", num, ClosestIntSameBitCount(num));
    
    return 0;
}
*/

/*
int main()
{
    uint64 num = 0x00723F54;
    
    printf("%x %x\n", num, SwapBits(num, 2, 3));
    
    return 0;
}
*/

/*
int main()
{
    uint8 num = 0x54;
    
    printf("%x %x\n", num, ReverseBits(num));
    
    return 0;
}
*/

/*
int main(int argc, const char * argv[])
{
    int arr[] = {12, 11, 13, 6, 5, 7, -3};//, 14, -32, 25, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    PrintArray(arr, arr_size);
 
    MergeSortArray(arr, arr_size);
 
    printf("\nSorted array is \n");
    PrintArray(arr, arr_size);
    return 0;
}
*/

/*
int main()
{
    int A[] = { 1, 6, 7, 11, 15, 17, 21, 25, 29 };
    int B[] = { 12, 24, 28, 32, 34, 36, 38, 39, 42};
    int k = 4;
    
    int result = KthLargestElementSortedArray(A, B, 9, k);
    
    printf("Kth (%d) largest element is %d\n", k, result);
    
    return 0;
}
 */

/*
int main()
{
    int A[] = {1, 3};
    int B[] = {2};
    PrintArray(A, sizeof(A)/sizeof(int));
    PrintArray(B, sizeof(B)/sizeof(int));
    
    double result = MedianUnionSortedArrays(A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int));
    
    printf("Median of union of sorted arrays is %f\n", result);
    
    return 0;
}
*/

/*
int main()
{
    int A[] = {20, 5, 8, 14, 55, 4, 32, 1, 6, 9, 2};
    PrintArray(A, sizeof(A)/sizeof(int));
    int k = 7;
    
    int result = KthSmallestUnsortedArray(A, sizeof(A)/sizeof(int), k);
    
    printf("kth [%d] element of arrays is %d\n", k, result);
    
    return 0;
}
*/

/*
int main()
{
    int A[] = {1,1,1,3,3,2,2,2};
    PrintArray(A, sizeof(A)/sizeof(int));
    int retSize;
    
    int* result = FindMajorityBy3(A, sizeof(A)/sizeof(int), &retSize);
    
    printf("Below is/are the majority element(s) whose count is greater than n/3\n");
    PrintArray(result, retSize);
    
    return 0;
}
*/

/*
int main()
{
    int a[] = {4, 1, 2, 3, 5};
    int n = sizeof(a) / sizeof(int);
    int sum = 7; //697439;
    
    PrintArray(a, n);
    int* res = TwoSum(a, n, sum);
    
    if(res != NULL) {
        printf("Indexes of arrays having sum %d are i=%d, j=%d\n", sum, res[0], res[1]);
    }
    
    return 0;
}
*/

/*
int main()
{
    int a[] = {1,2,3,4,5,6};
    int n = sizeof(a) / sizeof(int);
    int k = 1; //697439;
    
    PrintArray(a, n);
    RotateArray(a, n, k);
    PrintArray(a, n);

    return 0;
}
*/

/*
int main()
{
    int a[] = {1,2,3,4,5,6};
    int n = sizeof(a) / sizeof(int);
    
    PrintArray(a, n);
    
    bool x = IsArrayMonotonic(a, n);
    
    printf("Given array is monotonic (yes[1]/no[0]): %d\n", x);

    return 0;
}
*/

/*
int main()
{
    int a[] = {-10, -3, 0, 1, 2, 6};
    int n = sizeof(a) / sizeof(int);
    
    PrintArray(a, n);
    
    SquareOfSortedArrays(a, n);
    
    PrintArray(a, n);

    return 0;
}
*/

/*
int main()
{
    int a[] = {2, -1, 4};
    int n = sizeof(a) / sizeof(int);
    
    printf("Original Array: ");
    PrintArray(a, n);

    printf("Below are all the permutations:\n");
    PermutationArray(a, n);
    
    return 0;
}
*/

int main()
{
    int a[] = {1,2,0,1,1,1};
    int n = sizeof(a) / sizeof(int);
    int target = 0;
    
    printf("Original Array: ");
    PrintArray(a, n);

    printf("%d is present in array %d (true 1, false 0)\n", target, SearchInRotatedArray(a, n, target));
    
    return 0;
}
