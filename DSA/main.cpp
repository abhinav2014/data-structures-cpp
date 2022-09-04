//
//  main.cpp
//  DSA
//
//  Created by BA-000277306 on 15/08/22.
//

#include <iostream>
#include "tree.hpp"
#include "array.hpp"

using namespace::std;

struct Node {
    int value;
    int val;
    struct Node *next;
};

struct ListNode {
    int val;
    struct ListNode *next;
};

struct DoubleNode {
    int val;
    struct DoubleNode *next;
    struct DoubleNode *prev;
};


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

void arrayMethods() {
    mergeTwoArrays();
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

void listMethods() {
    // Declare Nodes
    struct Node* head = NULL;
    struct Node* first = NULL;
    struct Node* second = NULL;
    
    // Allocate memory
    head = (struct Node*)malloc(sizeof(struct Node));
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    
    // Give values
    head->value = 0;
    first->value = 1;
    second->value = 2;
    
    // Link nodes
    head->next = first;
    first->next = second;
    second->next = NULL;
    
    // Traverse the list
    traverseList(head);
    
    // Reverse the list
    reverseList(&head);
    traverseList(head);
    
    // Merge two sorted lists
    callMergeList();
}

void doublyLinkedListMethods() {
    /* Initialize nodes */
    struct DoubleNode *head;
    struct DoubleNode *one = NULL;
    struct DoubleNode *two = NULL;
    struct DoubleNode *three = NULL;

    /* Allocate memory */
    one = new DoubleNode();
    two = new DoubleNode();
    three = new DoubleNode();

    /* Assign data values */
    one->val = 1;
    two->val = 2;
    three->val = 3;

    /* Connect nodes */
    one->next = two;
    one->prev = NULL;

    two->next = three;
    two->prev = one;

    three->next = NULL;
    three->prev = two;

    /* Save address of first node in head */
    head = one;
    
    
}

int main(int argc, const char * argv[]) {
    
    // Linked list operations
    listMethods();
    
    // Tree Operations
    createTree();
    
    // Array Operations
    arrayMethods();

    return 0;
}
