//
//  AddTwoNumbers.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/13/20.
//  Copyright © 2020 interview. All rights reserved.
//
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example

//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
//Explanation: 342 + 465 = 807.


#include "AddTwoNumbers.h"

Node* addTwoNumbers(Node* l1, Node* l2)
{
    Node* result = (Node *) malloc(sizeof(Node)); // dummy node
    Node* temp = result;

    uint8 carry = 0;
    
    while((l1 != NULL) && (l2 != NULL))
    {
        temp->next = (Node *) malloc(sizeof(Node));
        temp = temp->next;
        
        temp->next = NULL;
        temp->val = (l1->val + l2->val + carry);
        
        if(temp->val >= 10)
        {
            temp->val = (temp->val - 10);
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        
        l1 = l1->next;
        l2 = l2->next;
    }
    

    if(l1 != NULL)
    {
        while(l1 != NULL)
        {
            temp->next = (Node *) malloc(sizeof(Node));
            temp = temp->next;
            
            temp->next = NULL;
            temp->val = l1->val + carry;
            if(temp->val >= 10)
            {
                temp->val = (temp->val - 10);
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            l1 = l1->next;
        }
    }
    else if(l2 != NULL)
    {
        while(l2 != NULL)
        {
            temp->next = (Node *) malloc(sizeof(Node));
            temp = temp->next;
            
            temp->next = NULL;
            temp->val = l2->val + carry;
            if(temp->val >= 10)
            {
                temp->val = (temp->val - 10);
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            l2 = l2->next;
        }
    }
    
    if(carry == 1)
    {
        temp->next = (Node *) malloc(sizeof(Node));
        temp = temp->next;
        
        temp->next = NULL;
        temp->val = carry;
    }

    temp = result;
    result = result->next;
    
    free(temp);
    
    return result;
}

