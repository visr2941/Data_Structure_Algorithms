//
//  RemoveDuplicate.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/14/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "RemoveDuplicate.h"

/* Removing duplicate elemets from a sorted list */

Node* RemoveDuplicate(Node* head)
{
    Node** refNode = &(head->next);
    Node* temp = NULL;
    
    uint32 currVal = head->val;
    
    while(*refNode != NULL)
    {
        if(currVal == (*refNode)->val)
        {
            temp = *refNode;
            *refNode = temp->next;
            free(temp);
        }
        else
        {
            currVal = (*refNode)->val;
            refNode = &((*refNode)->next);
        }
    }
    
    return head;
}
