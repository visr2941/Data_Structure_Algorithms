//
//  LinkList.h
//  practice_programming
//
//  Created by Vishal Srivastav on 1/13/20.
//  Copyright © 2020 interview. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

struct ListNode {
    struct ListNode* next;
    int              val;
};

typedef struct ListNode Node;

Node* CreateNode(int val);
Node* CreateList(int val);
Node* InsertAtFront(Node* head, int val);
Node* DeleteSingleOccurence(Node* head, int val);
Node* DeleteAllOccurence(Node* head, int val);
void PrintList(Node* head);

#include "AddTwoNumbers.h"
#include "MergeSortedList.h"
#include "ReverseLinkList.h"
#include "ReverseLinkListRecursive.h"
#include "IsPalindromeLinkList.h"
#include "MergeSort.h"
#include "RemoveDuplicate.h"

#endif /* LinkList_h */
