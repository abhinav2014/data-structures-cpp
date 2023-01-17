//
//  linkedlist.cpp
//  DSA
//
//  Created by BA-000277306 on 08/09/22.
//

#include "linkedlist.hpp"
#include <iostream>
#include <math.h>

using namespace::std;

// MARK: - Linked list methods
void traverseList(struct Node* n) {
    while (n != NULL) {
        printf("%d\n", n->value);
        n = n->next;
    }
    printf("\n");
}
void traverseList(struct ListNode* n) {
    while (n != NULL) {
        printf("%d\n", n->val);
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

void swapNodesInPairs() {  // Not completed yet, need to check
    struct Node* head = NULL;
    struct Node* first = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // Allocate memory
    head = (struct Node*)malloc(sizeof(struct Node));
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Give values
    head->value = 0;
    first->value = 1;
    second->value = 2;
    third->value = 3;
    
    // Link nodes
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = NULL;

    cout<<"\nswap Nodes In Pairs:\n";
    struct Node* list = NULL;
    struct Node* list1 = NULL;

    list = head;
    list1 = head;
    struct Node* temp = NULL;
    while(list1 != NULL) {
//        cout<<list1->value;
        
        temp = list1->next;
//        cout<<temp->value;
        if (list1->next->next == NULL) {
            list1->next = NULL;
        } else {
            list1->next = list1->next->next;
        }
        temp->next = list1;
//        cout<<temp->value;
        cout<<list1->value;

        list1 = list1->next;
    }
    cout<<"\n";
    traverseList(list);
}

void addTwoNumbers() {
    cout<<"Add Two Numbers (Linked list):";
    
    struct ListNode* head1 = new ListNode();
    struct ListNode* first1 = new ListNode();
    struct ListNode* second1 = new ListNode();

    head1->val = 2;
    first1->val = 4;
    second1->val = 3;
    
    // Link nodes
    head1->next = first1;
    first1->next = second1;
    second1->next = NULL;

    struct ListNode* head2 = new ListNode();
    struct ListNode* first2 = new ListNode();
    struct ListNode* second2 = new ListNode();

    head2->val = 5;
    first2->val = 6;
    second2->val = 4;
    
    // Link nodes
    head2->next = first2;
    first2->next = second2;
    second2->next = NULL;

    struct ListNode* list1 = head1;
    struct ListNode* list2 = head2;
    
    // find count
    int count1 = 0;
    while (list1 != NULL) {
        count1 += 1;
        list1 = list1->next;
    }
    printf("count1 = %d", count1);
    
    int count2 = 0;
    while (list2 != NULL) {
        count2 += 1;
        list2 = list2->next;
    }
    printf("count2 = %d", count2);
    
    // Sum of Linked list elements
    int num1 = 0;
    while(count1 > 0) {
        count1 -= 1;
        num1 = num1 + head1->val * pow(10, count1);
        head1 = head1->next;
    }
    printf("\nnum1 = %d", num1);

    int num2 = 0;
    while(count2 > 0) {
        count2 -= 1;
        num2 = num2 + head2->val * pow(10, count2);
        head2 = head2->next;
    }
    printf("num2 = %d", num2);
    
    // Add two numbers
    int sum = num1+num2;
    cout<<"sum = "<<sum;
    
    // Create linked list out of the Sum
    int mod = 0;
    ListNode *sumList = NULL;
    ListNode *sumListTraverse = NULL;
    while(sum > 0) {
        mod = sum % 10;
        sum = sum / 10;
        ListNode *node = new ListNode();
        node->val = mod;
        if (sumList == NULL) {
            sumList = node;
            sumListTraverse = node;
        } else {
            sumList->next = node;
            sumList = sumList->next;
        }
    }
    
    // traverse Sum list
    cout<<"\nSum List =\n";
    traverseList(sumListTraverse);
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
