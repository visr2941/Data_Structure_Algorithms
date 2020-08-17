//
//  ConstructUniqueBTPreInOrder.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/19/20.
//  Copyright © 2020 interview. All rights reserved.
//

/*

*/

#include "ConstructUniqueBTPreInOrder.h"

// use binary search in this array since it's already sorted
int SearchElementInArr(int* arr, int size, int elem)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == elem)
            return i;
    }
    
    return -1;
}

void ConstructUniqueBTPreInOrder_Helper(int* inArr, int* preArr, int startIn, int endIn, BT_Node** root)
{
    static int preInd = 0;
    
    if(startIn > endIn) return;
    
    *root = (BT_Node*) malloc(sizeof(BT_Node));
    (*root)->data = preArr[preInd++];
    (*root)->left = NULL;
    (*root)->right = NULL;
    
    int index = SearchElementInArr(inArr, endIn+1, (*root)->data);
    
    ConstructUniqueBTPreInOrder_Helper(inArr, preArr, startIn, index-1, &(*root)->left);
    ConstructUniqueBTPreInOrder_Helper(inArr, preArr, index+1, endIn, &(*root)->right);
}

BT_Node* ConstructUniqueBTPreInOrder(int* inArr, int* preArr, int size)
{
    BT_Node* root;
    
    ConstructUniqueBTPreInOrder_Helper(inArr, preArr, 0, size-1, &root);
    
    return root;
}
