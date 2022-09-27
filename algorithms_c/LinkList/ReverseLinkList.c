//
//  ReverseLinkList.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/14/20.
//  Copyright © 2020 interview. All rights reserved.
//
#include "ReverseLinkList.h"

Node* ReverseLinkList(Node* head)
{
    Node* old = NULL;
    Node* curr = head;
    Node* new = curr;
    
    while(new != NULL)
    {
        new = curr->next;
        curr->next = old;
        old = curr;
        curr = new;
    }
    
    return old;
}
