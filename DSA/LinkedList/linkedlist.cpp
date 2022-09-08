//
//  linkedlist.cpp
//  DSA
//
//  Created by BA-000277306 on 08/09/22.
//

#include "linkedlist.hpp"
#include <iostream>

using namespace::std;

// MARK: - Linked list methods
void traverseList(struct Node* n) {
    while (n != NULL) {
        printf("%d\n", n->value);
        n = n->next;
    }
    printf("\n");
}

void reverseList(struct Node** n) {
    // Three pointer approach
    struct Node* prev = NULL;
    struct Node* current = *n;
    struct Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        
        prev = current;
        current = next;
    }
    *n = prev;
}

ListNode* mergeTwoLists(ListNode** oneList, ListNode** twoList) {
    struct ListNode* list1 = *oneList;
    struct ListNode* list2 = *twoList;
    
    ListNode *merged = new ListNode();
    ListNode *head = new ListNode();
    head = merged;
    while(true) {
        struct ListNode* item = new ListNode();
        if (list1 == NULL) {
            item->val = list2->val;
            merged->next = item;
            list2 = list2->next;
            if (list2 == NULL) {
                break;
            }
        } else if (list2 == NULL) {
            item->val = list1->val;
            merged->next = item;
            list1 = list1->next;
            if (list1 == NULL) {
                break;
            }
        } else if (list1->val > list2->val) {
            item->val = list2->val;
            merged->next = item;
            merged->next = item;
            list2 = list2->next;
        } else if (list1->val < list2->val) {
            item->val = list1->val;
            merged->next = item;
            list1 = list1->next;
        }
        merged = merged->next;
    }
    // traverseList;
    printf("Merged list: \n");
    if (head->next != NULL) {
        head = head->next;
    }
    while (head != NULL) {
        printf("%d\t", head->val);
        head = head->next;
    }
    printf("\n");
    return head;
}
void callMergeList() {
    struct ListNode* head1 = new ListNode();
    struct ListNode* first1 = new ListNode();
    struct ListNode* second1 = new ListNode();

    head1->val = 1;
    first1->val = 3;
    second1->val = 5;
    
    // Link nodes
    head1->next = first1;
    first1->next = second1;
    second1->next = NULL;


    struct ListNode* head2 = new ListNode();
    struct ListNode* first2 = new ListNode();
    struct ListNode* second2 = new ListNode();

    head2->val = 2;
    first2->val = 4;
    second2->val = 6;
    
    // Link nodes
    head2->next = first2;
    first2->next = second2;
    second2->next = NULL;

    mergeTwoLists(&head1, &head2);
}

// MARK: - Doubly linked list methods
void twoSumProblem(struct DoubleNode* head, int sum) {
    struct DoubleNode *tempHead = NULL;
    struct DoubleNode *tail = NULL;
    
    tempHead = head;

    cout<<"\nDoubly linked list:\n";
    while(tempHead != NULL) {
        cout<<tempHead->val<<"\t";
        if(tempHead->next == NULL) {
            tail = tempHead;
        }
        tempHead = tempHead->next;
    }
    
    cout<<"\n2 Sum problem\n";
    while(true) {
        if((head->val + tail->val) > sum) {
            tail = tail->prev;
        } else if((head->val + tail->val) < sum) {
            head = head->next;
        } else {
            cout<<head->val<<"\t"<<tail->val;
            break;
        }
    }
}
