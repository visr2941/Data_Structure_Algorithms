//
//  PrintLevelOrderBT.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/16/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "PrintLevelOrderBT.h"

// below algorithm for level proder traversal has O(n^2) complexity.
// we can use Queue to make the order level traversal of O(n) time
// complexity (check ConstructBTLevelOrder.c for detailed explaination)

static void PrintLevelOrderBT_Helper(BT_Node* root, int level)
{
    if(root == NULL) return;
    else if(level == 0)
    {
        printf("%d ", root->data);
        return;
    }
    
    PrintLevelOrderBT_Helper(root->left, level-1);
    PrintLevelOrderBT_Helper(root->right, level-1);
}

void PrintLevelOrderBT(BT_Node* root)
{
    int ht = FindHeightBT(root);
    
    for (int i = 0; i <= ht; i++)
        PrintLevelOrderBT_Helper(root, i);
}
