//
//  linkedlist.hpp
//  DSA
//
//  Created by BA-000277306 on 08/09/22.
//

#ifndef linkedlist_hpp
#define linkedlist_hpp

#include <stdio.h>

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

void traverseList(struct Node* n);
void reverseList(struct Node** n);
ListNode* mergeTwoLists(ListNode** oneList, ListNode** twoList);
void callMergeList();
void twoSumProblem(struct DoubleNode* head, int sum);

#endif /* linkedlist_hpp */
