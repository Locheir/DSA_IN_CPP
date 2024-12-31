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

Node* insert(Node* root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return root;
    }

    if (val < root->value) { // left subtree
        root->left = insert(root->left, val);
    } else { // right subtree
        root->right = insert(root->right, val);
    }

    return root;
}

Node* buildBST(int arr[], int n) {
    Node* root = NULL;

    for(int i=0; i<n; i++) {
        root = insert(root, arr[i]);
    }

    return root;
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
    int n = 6;
    int arr[n] = {5, 1, 3, 4, 2, 7};

    int n2 = 9;
    int arr2[n2] = {8, 5, 3, 1, 4, 6, 10, 11, 14};

    Node* root = buildBST(arr, n);

    inOrder(root);

    cout << endl;

    Node* root2 = buildBST(arr2, n2);
    
    inOrder(root2);

    cout << endl;

    return 0;
}