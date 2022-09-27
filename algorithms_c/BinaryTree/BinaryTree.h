//
//  BinaryTree.h
//  practice_programming
//
//  Created by Vishal Srivastav on 1/16/20.
//  Copyright © 2020 interview. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct BT_Node {
    struct BT_Node* left;
    struct BT_Node* right;
    
    int data;
};

typedef struct BT_Node BT_Node;

#include "ConstructFullBTLevelOrder.h"
#include "PrintLevelOrderBT.h"
#include "FindHeightBT.h"
#include "PrintLevelOrderBT.h"
#include "PrintInOrderBT.h"
#include "ConstructBalancedBTInOrder.h"
#include "PrintPreOrderBT.h"
#include "ConstructUniqueBTPreInOrder.h"

#endif /* BinaryTree_h */
