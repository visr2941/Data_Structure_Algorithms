//
//  MergeSort.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/14/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "MergeSort.h"

Node* MergeSort(Node* head)
{
    Node* l1 = head;
    Node* l2 = head;
    Node* prel2 = NULL;
    
    if(head->next == NULL) return  head;
    
    // Split the link list in two halves
    while(l1 && l1->next)
    {
        prel2 = l2;
        l2 = l2->next;
        l1 = l1->next->next;
    }
    prel2->next = NULL;
    l1 = head;
    // split done
    
    l1 = MergeSort(l1);
    l2 = MergeSort(l2);
    
    return MergeSortedList(l1, l2);
}
