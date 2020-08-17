//
//  FindHeightBT.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/16/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "FindHeightBT.h"

// Height of BT with zero node = -1, with 1 node = 0 and so on.

int FindHeightBT(BT_Node* root)
{
    if(root == NULL) return -1;
    
    int left_ht  = FindHeightBT(root->left);
    int right_ht = FindHeightBT(root->right);
    
    return ((left_ht > right_ht) ? left_ht+1 : right_ht+1);
}
