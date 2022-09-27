//
//  LinkList.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/13/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "LinkList.h"

Node* CreateNode(int val)
{
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    
    return newNode;
}

void PrintList(Node* head)
{
    while(head != NULL)
    {
        printf("%d->", head->val);
        head = head->next;
    }
    
    printf("\b\b\n");
}

Node* CreateList(int val)
{
    Node* head = CreateNode(val);
    
    return head;
}

Node* InsertAtFront(Node* head, int val)
{
    Node* newHead = CreateNode(val);
    newHead->next = head;
    
    return newHead;
}

Node* DeleteSingleOccurence(Node* head, int val)
{
    Node** curr = &head;
    Node* ptrToFree = NULL;
    
    while((*curr) != NULL && (*curr)->val != val)
    {
        curr = &((*curr)->next);
    }
    
    if(*curr != NULL)
    {
        ptrToFree = *curr;
        *curr = (*curr)->next;
        free(ptrToFree);
    }

    return head;
}

Node* DeleteAllOccurence(Node* head, int val)
{
    Node** curr = &head;
    Node* ptrToFree = NULL;
    
    while(*curr != NULL)
    {
        if((*curr)->val == val)
        {
            ptrToFree = *curr;
            *curr = (*curr)->next;
            free(ptrToFree);
        }
        else
        {
            curr = &((*curr)->next);
        }
    }

    return head;
}
