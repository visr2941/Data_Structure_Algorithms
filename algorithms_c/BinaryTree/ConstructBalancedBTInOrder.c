//
//  ConstructBalancedBTInOrder.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/19/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "ConstructBalancedBTInOrder.h"

void ConstructBalancedBTInOrder_Helper(int* arr, int i, int j, BT_Node** root)
{
    // base case
    if(i > j) return;

    *root = (BT_Node *) malloc(sizeof(BT_Node));
    int mid = i+(j-i)/2;
    (*root)->data = arr[mid];
    (*root)->left = NULL;
    (*root)->right = NULL;

    ConstructBalancedBTInOrder_Helper(arr, i, mid-1, &(*root)->left);
    ConstructBalancedBTInOrder_Helper(arr, mid+1, j, &(*root)->right);
}

BT_Node* ConstructBalancedBTInOrder(int* arr, int size)
{
    BT_Node* root = NULL;
    
    ConstructBalancedBTInOrder_Helper(arr, 0, size-1, &root);
    
    return root;
}
