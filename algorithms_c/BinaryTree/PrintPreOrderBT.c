//
//  PrintPreOrderBT.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/19/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "PrintPreOrderBT.h"

void PrintPreOrderBT(BT_Node* root)
{
    // base condition
    if(root == NULL) return;
    
    printf("%d ", root->data);
    
    PrintPreOrderBT(root->left);
    PrintPreOrderBT(root->right);
}
