/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
    struct ListNode* primnode = head;
    struct ListNode* secnode = head;
    struct ListNode* temp = NULL;
    
    while(n--!= 0 && secnode != NULL)
    {
        secnode = secnode->next;
    }
    
    if(secnode == NULL && n < 0) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        while(secnode->next != NULL)
        {
            primnode = primnode->next;
            secnode = secnode->next;
        }

        temp = primnode->next;
        primnode->next = primnode->next->next;
        free(temp);
    }

    
    return head;
}

=============================================================================================================================
=============================================================================================================================
=============================================================================================================================
/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* Merge(struct ListNode* first, struct ListNode* sec)
{
    struct ListNode* retNode;
    struct ListNode** refNode = &retNode;
    
    while(first != NULL && sec != NULL)
    {
        if(first->val < sec->val)
        {
            *refNode = first;
            first = first->next;
        }
        else
        {
            *refNode = sec;
            sec = sec->next;
        }
        
        refNode = &((*refNode)->next);
    }
    
    if(first == NULL)
        *refNode = sec;
    else
        *refNode = first;
    
    return retNode;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int i;
    
    if(listsSize == 0) return NULL;
    
    for(i = 0; i < listsSize-1; i++)
    {
        lists[i+1] = Merge(lists[i], lists[i+1]);
    }
    
    return lists[i];
}



=============================================================================================================================
=============================================================================================================================
=============================================================================================================================

/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void reverse_recursive(struct ListNode ** head)
{
    if((*head)->next == NULL)
        return;
    
    struct ListNode * prev = *head;
    struct ListNode * curr = (*head)->next;
    
    reverse_recursive(&curr);
    
    prev->next->next = prev;
    prev->next = NULL;
	
    *head = curr;

    return;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    
    if(k==0 || head == NULL || head->next == NULL) return head;
    
    int i = 0;
    struct ListNode ** prevNext = &head;
    struct ListNode ** currNext = NULL;
    struct ListNode * lastNode = head;
    struct ListNode * restList = NULL;
    
    while((*prevNext) != NULL)
    {
        currNext = &((*prevNext)->next);
        
        for(i = 0; i < k-1 && lastNode->next != NULL; i++)
        {
            lastNode = lastNode->next;
        }
        
        if(lastNode->next == NULL && i != (k-1)) break; 
        
        restList = lastNode->next;
        lastNode->next = NULL;
                
        reverse_recursive(prevNext);
        
        lastNode = restList;
        *currNext = restList;
        prevNext = currNext;
    }
    
    return head;

}

=============================================================================================================================
=============================================================================================================================
=============================================================================================================================
/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    int cnt = 0;
    
    if(head == NULL) return head;
    
    struct ListNode* tempNode = head;
    struct ListNode* retNode;
        
    while(tempNode->next != NULL) {
        tempNode = tempNode->next;
        cnt++;
    }
    
    cnt++;
    
    k = k%cnt;
    
    tempNode->next = head;
    
    for(int i = 0; i < (cnt-k); i++)
    {
        tempNode = tempNode->next;
    }
    
    retNode = tempNode->next;
    
    tempNode->next = NULL;
    
    return retNode;    
}
=============================================================================================================================
=============================================================================================================================
=============================================================================================================================
/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    
    if(head == NULL) return head;
    
    struct ListNode** prev = NULL;
    struct ListNode** curr = &head;
    
    bool flag;
    
    while((*curr) != NULL)
    {
        if(prev != NULL)
        {
            while((*prev)->val == (*curr)->val)
            {
                curr = &((*curr)->next);
                flag = true;
                
                if((*curr) == NULL) break;
            }
            
            if(flag)
            {
                *prev = *curr;
                curr = prev;
                flag = false;
                
                if(*curr == NULL) break;
            }
        }

        prev = curr;
        curr = &((*curr)->next);
    }
    
    return head;
}


=============================================================================================================================
=============================================================================================================================
=============================================================================================================================
/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
*/

/*
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    
    struct ListNode* t1 = head;
    struct ListNode* t2 = head;
    //struct ListNode* t3 = head;
    
    while(t1 != NULL && t2 != NULL)
    {
        t1 = t1->next;
        
        if(t1==NULL)
                break;
        
        while(t1->val == t2->val)
        {
            t1 = t1->next;
            if(t1==NULL)
                break;
        }
        
        t2->next = t1;
        t2 = t1;
    }
    
    return head;
}
*/


=============================================================================================================================
=============================================================================================================================
=============================================================================================================================
/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void reverse_recursive(struct ListNode ** head)
{
    if((*head)->next == NULL)
        return;
    
    struct ListNode * prev = *head;
    struct ListNode * curr = (*head)->next;
    
    reverse_recursive(&curr);
    
    prev->next->next = prev;
    prev->next = NULL;
	
    *head = curr;

    return;
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    
    if(head == NULL || m == 0 || n==0) return NULL;
    
    struct ListNode** currNext = NULL;
    struct ListNode** curr = &head;
    
    struct ListNode* lastNode = head;
    struct ListNode* restList = NULL;
    
    while(--m) curr = &((*curr)->next);

    currNext = &((*curr)->next);
    
    while(--n) lastNode = lastNode->next;
    
    restList = lastNode->next;
    
    lastNode->next = NULL;
    
    reverse_recursive(curr);
    
    *currNext = restList;
    
    return head;
}


=============================================================================================================================
=============================================================================================================================
=============================================================================================================================
/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    
    if(head == NULL || head->next == NULL) return NULL;
    
    struct ListNode * fastPtr = head;
    struct ListNode * slowPtr = head;
    bool flag = false;

    do
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
        if(fastPtr == NULL) {
            flag = true;
            break;
        }
        else
        {
            fastPtr = fastPtr->next;
        }
        
    } while(fastPtr != slowPtr && fastPtr != NULL);
    
    if(flag == true || fastPtr == NULL) return NULL;
    
    slowPtr = head;
    
    while(slowPtr != fastPtr)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
    }
    
    return slowPtr;
}


=============================================================================================================================
=============================================================================================================================
=============================================================================================================================
/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void reverse_recursive(struct ListNode ** head)
{
    if((*head)->next == NULL)
        return;
    
    struct ListNode * prev = *head;
    struct ListNode * curr = (*head)->next;
    
    reverse_recursive(&curr);
    
    prev->next->next = prev;
    prev->next = NULL;
	
    *head = curr;

    return;
}

void reorderList(struct ListNode* head) {
    if(head == NULL || head->next == NULL || head->next->next == NULL)    return;
    
    struct ListNode* slowPtr = head;
    struct ListNode* fastPtr = head;
    
    struct ListNode* l1Head = NULL;
    struct ListNode* l2Head = NULL;
    struct ListNode* l1Next = NULL;
    struct ListNode* l2Next = NULL;
    
    int cnt = 1;
    
    while(fastPtr->next != NULL) 
    {
        fastPtr = fastPtr->next;
        
        if(fastPtr != NULL)
        {
            fastPtr = fastPtr->next;
            
            if(fastPtr == NULL) break;
        }
        else
            break;
        
        slowPtr = slowPtr->next;
    }    
     
    l2Head = slowPtr->next;

    slowPtr->next = NULL;

    reverse_recursive(&l2Head);
    
    l1Head = head;
    
    while(l1Head != NULL)
    {
        l1Next = l1Head->next;
        l1Head->next = l2Head;
        if(l2Head != NULL)
        {
            l2Next = l2Head->next; 
            l2Head->next = l1Next;
            l2Head = l2Next;
        }
        l1Head = l1Next;
    }
}


=============================================================================================================================
=============================================================================================================================
=============================================================================================================================

/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head == NULL) return head;
    
    struct ListNode** curr = &head;
    struct ListNode* freePtr = NULL;
    
    while((*curr) != NULL)
    {
        if((*curr)->val == val) {
            freePtr = *curr;
            *curr = (*curr)->next;
            free(freePtr);
        }
        else    curr = &((*curr)->next);
    }
    
    return head;
}


=============================================================================================================================
=============================================================================================================================
=============================================================================================================================
/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the
node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* oddEvenList(struct ListNode* head) {
    if(head == NULL || head->next == NULL || head->next->next == NULL) return head;
    
    struct ListNode* oddptr = head;
    struct ListNode* evenptr = head->next;
    
    struct ListNode* oddptrhead = oddptr;
    struct ListNode* evenptrhead = evenptr;
    
    bool flag = false;
    
    while(evenptr != NULL && flag == false)
    {
        if(evenptr->next != NULL)
        {
            oddptr->next = evenptr->next;
            oddptr = oddptr->next;
            
            if(oddptr->next != NULL)
            {              
                evenptr->next = oddptr->next;
                evenptr = evenptr->next;
            }
            else
            {
                evenptr->next = NULL;
                flag = true;
            }
        }
        else
            flag = true;
    }
    
    oddptr->next = evenptrhead;
    
    return oddptrhead;
}


=============================================================================================================================
=============================================================================================================================
=============================================================================================================================
/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void reverse_recursive(struct ListNode ** head)
{
    if((*head)->next == NULL)
        return;
    
    struct ListNode * prev = *head;
    struct ListNode * curr = (*head)->next;
    
    reverse_recursive(&curr);
    
    prev->next->next = prev;
    prev->next = NULL;
	
    *head = curr;

    return;
}

bool isPalindrome(struct ListNode* head) {
    
    if(head == NULL || head->next == NULL) return true;
    
    struct ListNode* slow = head;
    struct ListNode* prevslow = NULL;
    struct ListNode* fast = head;
    
    struct ListNode* sec_half_list;
    struct ListNode* first_half_list = head;
    
    bool flag = false;
    
    while(fast != NULL)
    {
        fast = fast->next;
        
        if(fast != NULL)
            fast = fast->next;
        else
        {
            flag = true;
            break;
        }
        
        prevslow = slow;
        slow = slow->next;
    }
    
    /* for odd number of elements, the first half list will have one more element */
    if(flag)
    {
        sec_half_list = slow->next;
        slow->next = NULL;
    }
    /* for even number of elements, both halves will have same number of elements */
    else
    {
        sec_half_list = slow;
        prevslow->next = NULL;
    }
    
    reverse_recursive(&sec_half_list);
    
    while(first_half_list != NULL && sec_half_list != NULL)
    {
        if(first_half_list->val != sec_half_list->val) return false;
        
        first_half_list = first_half_list->next;
        sec_half_list = sec_half_list->next;
    }
    
    return true;    
}



=============================================================================================================================
=============================================================================================================================
=============================================================================================================================
/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    
    if(head == NULL) return false;
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    bool flag = false;
    
    do{
        slow = slow->next;
        fast = fast->next;
        
        if(fast != NULL)    fast = fast->next;
        else
        {
            flag = true;
            break;
        }
        
    } while(fast != slow && fast != NULL);
    
    if(flag || !fast) return false;
    else return true;
}

=============================================================================================================================
=============================================================================================================================
=============================================================================================================================
/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode * retptr;
    struct ListNode** refptr = &retptr;
    
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->val < l2->val)
        {
            *refptr = l1;
            l1 = l1->next;
        }
        else
        {
            *refptr = l2;
            l2 = l2->next;
        }
        
        refptr = &((*refptr)->next);
    }
    
    if(l1 == NULL)
        *refptr = l2;
    else
        *refptr = l1;
    
    return retptr;
}

=============================================================================================================================
=============================================================================================================================
=============================================================================================================================
/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    // base case
    if(head == NULL || head->next == NULL) return head;
    
    struct ListNode* curr = head;
    struct ListNode* prev = NULL;
    struct ListNode* next = head->next;
    
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}



=============================================================================================================================
=============================================================================================================================
=============================================================================================================================
/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Given linked list -- head = [4,5,1,9], which looks like following:

    4 -> 5 -> 1 -> 9
Example 1:

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list
             should become 4 -> 1 -> 9 after calling your function.
Example 2:

Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list
             should become 4 -> 5 -> 9 after calling your function.
Note:

The linked list will have at least two elements.
All of the nodes' values will be unique.
The given node will not be the tail and it will always be a valid node of the linked list.
Do not return anything from your function.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode* nextnode = node->next;
    
    node->val = nextnode->val;
    node->next = nextnode->next;
    
    free(nextnode);
}


=============================================================================================================================
=============================================================================================================================
=============================================================================================================================
/*
Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:

Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
Example 2:

Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    if(head == NULL) return head;
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    bool flag = false;
    
    do 
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
        }
        else
        {
            flag = true;
            break;
        }

        slow = slow->next;
        
    } while(fast != NULL);
    
    return slow;    
}

=============================================================================================================================
=============================================================================================================================
=============================================================================================================================



=============================================================================================================================
=============================================================================================================================
=============================================================================================================================



=============================================================================================================================
=============================================================================================================================
=============================================================================================================================



=============================================================================================================================
=============================================================================================================================
=============================================================================================================================