//
//  IsPalindromeLinkList.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/14/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "IsPalindromeLinkList.h"

/*
bool IsPalindromeLinkList(Node* head)
{
    Node* slow = head;
    Node* preSlow = NULL;
    Node* fast = head;
    
    while(fast && fast->next)
    {
        preSlow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    preSlow->next = NULL;
    
    slow = ReverseLinkList(slow);
    
    while(slow && head)
    {
        if(slow->val != head->val)
            return false;
        
        slow = slow->next;
        head = head->next;
    }
    
    return true;
}
*/

 bool IsPalindromeLinkList_Helper(Node **left, Node *right)
 {
    if(right == NULL)
        return true;
     
    bool isp1 = IsPalindromeLinkList_Helper(left, right->next);
    
    if(isp1 == false)
        return false;
    
    bool isp2 = ((*left)->val == right->val);
    
    *left = (*left)->next;
    
    return isp2;
 }

 bool IsPalindromeLinkList(Node* head){
     return IsPalindromeLinkList_Helper(&head, head);
 }

