//
//  ReverseLinkListRecursive.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/14/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "ReverseLinkListRecursive.h"

static void ReverseLinkListRecursive_Helper(Node* head, Node** newHead)
{
    if(head->next == NULL)
    {
        *newHead = head;
        return;
    }
    
    ReverseLinkListRecursive_Helper(head->next, newHead);
    
    head->next->next = head;
    head->next = NULL;
}

Node* ReverseLinkListRecursive(Node* head)
{
    Node* newHead = NULL;
    
    ReverseLinkListRecursive_Helper(head, &newHead);
    
    return newHead;
}
