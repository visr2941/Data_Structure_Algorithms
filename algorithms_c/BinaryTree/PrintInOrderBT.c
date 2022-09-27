//
//  PrintInOrderBT.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/17/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "PrintInOrderBT.h"

void PrintInOrderBT(BT_Node* root)
{
    if(root == NULL) return;
    
    PrintInOrderBT(root->left);
    
    printf("%d ", root->data);
    
    PrintInOrderBT(root->right);
}
