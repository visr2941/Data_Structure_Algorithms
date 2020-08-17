//
//  MergeSortedList.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/13/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "MergeSortedList.h"

Node* MergeSortedList(Node* l1, Node* l2)
{
    Node* retHead = NULL;;
    Node** refNode = &retHead;
    
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->val < l2->val)
        {
            *refNode = l1;
            l1 = l1->next;
        }
        else
        {
            *refNode = l2;
            l2 = l2->next;
        }
        
        refNode = &((*refNode)->next);
    }
    
    if(l1 != NULL) *refNode = l1;
    else if(l2 != NULL) *refNode = l2;
    
    return retHead;
}
