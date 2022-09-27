//
//  ConstructFullBTLevelOrder.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/16/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "ConstructFullBTLevelOrder.h"

// every ith node in array will have 2*i+1 and 2*i+2 as the children nodes.
// Approach:
//  1. Create a node
//  2. Create left node recursively until the children node index exceeds the size of the array
//  3. Now, go for creating rigth node recursively until the children node index exceeds the
//     size of the array.

// Implementation without recursion:
//  1. Create a queue Q
//  2. Create the first node from arr[i] with i = 0
//  3. Put this node in Q
//  4. Loop until Q is empty
//      a. Take out the first element of Q and create left node with arr[2*i+1] and right node
//         with arr[2*i+2] and put them in Q (where 2*i+1 and 2*i+2 are within array's range)
//      b. Go back to step 4 until Q is empty.

void ConstructFullBTLevelOrder_Helper(int* arr, int i, int size, BT_Node** root)
{
    if(i >= size) return;
    
    *root = (BT_Node*) malloc(sizeof(BT_Node));
    
    (*root)->data = arr[i];
    (*root)->left = NULL;
    (*root)->right = NULL;
    
    ConstructFullBTLevelOrder_Helper(arr, 2*i+1, size, &(*root)->left);
    ConstructFullBTLevelOrder_Helper(arr, 2*i+2, size, &(*root)->right);
}

BT_Node* ConstructFullBTLevelOrder(int* arr, int size)
{
    BT_Node* root;

    ConstructFullBTLevelOrder_Helper(arr, 0, size, &root);
    
    return root;
}
