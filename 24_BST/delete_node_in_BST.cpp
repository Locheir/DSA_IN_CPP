#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
    public : 
        Node* left;
        int value;
        Node* right;

        Node(int value) {
            this->value = value;
            left = NULL;
            right = NULL;
        }
};

Node* insert(Node* node, int val) {
    if (node == NULL) {
        node = new Node(val);
        return node;
    }

    if (val < node->value) {
        node->left = insert(node->left, val);
    } else {
        node->right = insert(node->right, val);
    }

    return node;
}

Node* buildBST(int arr[], int n) {
    Node* root = NULL;

    for(int i=0; i<n; i++) {
        root = insert(root, arr[i]);
    }
    
    return root;
}

Node* getInorderSuccessor(Node* node) {
    while(node->left != NULL) {
        node = node->left;
    }

    return node;
}

Node* delNode(Node* node, int val) {
    if (node == NULL) {
        return NULL;
    }

    if (val < node->value) { // left subtree
        node->left = delNode(node->left, val);
    } else if (val > node->value) { // right subtree
        node->right = delNode(node->right, val);
    } else {
        // root == vnode
        // case1 : 0 children
        if (node->left == NULL && node->right == NULL) {
            delete node;
            return NULL;
        }

        // case2 : 1 child
        if (node->left == NULL || node->right == NULL) {
            return node->left == NULL ? node->right : node->left;
        }

        // case3 : 2 children
        Node* IS = getInorderSuccessor(node->right);
        node->value = IS->value;
        node->right = delNode(node->right, IS->value); // case1, case2
        return node;
    }

    return node;
}

void inOrder(Node* node) {
    if (node == NULL) {
        return;
    }

    inOrder(node->left);
    cout << node->value << " ";
    inOrder(node->right);
}

int main() {
    int arr[] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    int size = sizeof(arr) / sizeof(int);

    Node* root = buildBST(arr, size);

    inOrder(root);
    cout << endl;

    delNode(root, 4);

    inOrder(root);
    cout << endl;
    
    return 0;
}