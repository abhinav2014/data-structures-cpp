//
//  main.cpp
//  DSA
//
//  Created by BA-000277306 on 15/08/22.
//

#include <iostream>
#include "tree.hpp"
#include "array.hpp"
#include "stack.hpp"
#include "linkedlist.hpp"
#include "strings.hpp"

using namespace::std;

// MARK: - Linked list methods
void listMethods() {
    // Declare Nodes
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

    // Traverse the list
    traverseList(head);
    
    // Reverse the list
    reverseList(&head);
    traverseList(head);
    
    // Merge two sorted lists
    callMergeList();
    
    // Swap nodes in pairs
    swapNodesInPairs();
    
    // Add two numbers (Linked List)
    addTwoNumbers();
}

// MARK: - Doubly linked list methods
void doublyLinkedListMethods() {
    /* Initialize nodes */
    struct DoubleNode *head;
    struct DoubleNode *one = NULL;
    struct DoubleNode *two = NULL;
    struct DoubleNode *three = NULL;
    struct DoubleNode *four = NULL;
    struct DoubleNode *five = NULL;
    struct DoubleNode *six = NULL;
    
    /* Allocate memory */
    one = new DoubleNode();
    two = new DoubleNode();
    three = new DoubleNode();
    four = new DoubleNode();
    five = new DoubleNode();
    six = new DoubleNode();

    /* Assign data values */
    one->val = 1;
    two->val = 2;
    three->val = 3;
    four->val = 4;
    five->val = 5;
    six->val = 6;

    /* Connect nodes */
    one->next = two;
    one->prev = NULL;

    two->next = three;
    two->prev = one;

    three->next = four;
    three->prev = two;
    
    four->next = five;
    four->prev = three;
    
    five->next = six;
    five->prev = four;
    
    six->next = NULL;
    six->prev = five;

    /* Save address of first node in head */
    head = one;

    // Call Two Sum Problem
    twoSumProblem(head, 11);
}

// MARK: - Array functions
void arrayMethods() {
    mergeTwoArrays();
    
    // Common prefix method
    std::vector<std::string> data = {"Hello World!", "Goodbye World!"};
    commonPrefix(data);
}

// MARK: - Stack functions
void callStackMethods() {
    
    // Checking for valid paranthesis
    string str = "{()}[]";
    bool check = parenthesisCheck(str);
    cout<<"\nParenthesis check: "<<check;
}

// MARK: - Main Function
int main(int argc, const char * argv[]) {
    
    // Linked list operations
    listMethods();
    
    // Doubly Linked List Methods
    doublyLinkedListMethods();
    
    // Tree Operations
    createTree();
    
    // Array Operations
    arrayMethods();
    
    // Stack Methods
    callStackMethods();

    return 0;
}
// Murmansk
