//
//  tree.cpp
//  DSA
//
//  Created by BA-000277306 on 15/08/22.
//

#include <iostream>
#include <stdlib.h>
#include <queue>
#include "tree.hpp"

using namespace::std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    
    inOrderTraversal(root->left);
    printf("%d",root->data);
    printf("\t");
    inOrderTraversal(root->right);
    return;
}

void preOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    
    printf("%d\t",root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    return;
}

void postOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d\t",root->data);
    return;
}

void levelOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        
        if(node != NULL) {
            cout<<node->data<<"\t";
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        } else if(!q.empty()) {
            q.push(NULL);
        }
    }
    
    return;
}

void sumTillKthLevel(struct Node* root) {
    if (root == NULL)
        return;
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level = 1;
    int k = 4;   // kth Level
    int sum = root->data;
    
    if (k==1) {
        cout<<"\nSum = "<<sum<<"\n";
        return;
    }
    
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        
        if(node != NULL ) { // && level <= k
            cout<<node->data<<"\t";
            if(node->left) {
                q.push(node->left);
                sum += node->left->data;
            }
            if(node->right) {
                q.push(node->right);
                sum += node->right->data;
            }
        } else if(!q.empty()) {
            q.push(NULL); // Level ends here
            level += 1;
        }
        
        if (level >= k) {
            break;
        }
    }
    cout<<"\nSum = "<<sum<<"\n";
    
    return;
}

void sumOfKthLevel(struct Node* root) {
    if (root == NULL)
        return;
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int k = 3;   // kth Level
    int sum = 0;
    
    if (k==0) {
        sum = root->data;
        cout<<"\nSum = "<<sum<<"\n";
        return;
    } else {
        level += 1;
    }
    
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        
        if(node != NULL) {
            cout<<node->data<<"\t";
            if(node->left) {
                q.push(node->left);
                if (level == k) {
                    sum += node->left->data;
                }
            }
            if(node->right) {
                q.push(node->right);
                if (level == k) {
                    sum += node->right->data;
                }
            }
        } else if(!q.empty()) {
            q.push(NULL); // Level ends here
            if (level == k) {
                cout<<"\nSum = "<<sum<<"\n";
                return;
            }
            level += 1;
        }
    }
//    cout<<"\nSum = "<<sum<<"\n";
    
    return;
}

void createTree() {
    
    struct Node* root = NULL;
    root = createNode(0);
    root->left = createNode(1);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->right->left = createNode(5);
    root->right->right = createNode(6);
    root->left->left->right = createNode(7);
    
    // In Order Traversal
    printf("\nInOrder traversal\n");
    inOrderTraversal(root);
    
    // Pre Order Traversal
    printf("\nPreOrder traversal\n");
    preOrderTraversal(root);
    
    // Post Order Traversal
    printf("\nPostOrder traversal\n");
    postOrderTraversal(root);
    
    // Level Order Traversal
    printf("\nLevelOrder traversal\n");
    levelOrderTraversal(root);
    
    // Sum Till kth level
    printf("\nSum till kth level\n");
    sumTillKthLevel(root);

    // Sum of kth level
    printf("\nSum of kth level\n");
    sumOfKthLevel(root);

}
