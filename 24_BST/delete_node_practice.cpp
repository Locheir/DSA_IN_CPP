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

Node* insert(Node* node, int value) {
    if (node == NULL) {
        return new Node(value);
    }

    if (value < node->value)  {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
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

void levelOrder(Node* node) {
    queue<Node*> Q;
    Q.push(node);
    Q.push(NULL);

    while(!Q.empty()) {
        Node* curr = Q.front();
        Q.pop();

        if (curr == NULL) {
            cout << endl;
            if (Q.empty()) {
                break;
            }
            Q.push(NULL);
        } else {
            cout << curr->value << " ";

            if (curr->left != NULL) {
                Q.push(curr->left);
            }

            if (curr->right != NULL) {
                Q.push(curr->right);
            }
        }
    }
}

Node* IS(Node* node) {

    while (node->left != NULL) {
        node = node->left;
    }

    return node;
}

Node* delNode(Node* node, int value) {
    if (node == NULL) {
        return NULL;
    }

    if (value < node->value) {
        node->left = delNode(node->left, value);
    } else if (value > node->value) {
        node->right = delNode(node->right, value);
    } else {
        // Case1 : O children
        if (node->left == NULL && node->right == NULL) {
            delete node;
            return NULL;
        }

        // Case2 : 1 child
        if (node->left == NULL || node->right == NULL) {
            return node->left == NULL ? node->right : node->left; 
        }

        // Case3 : 2 children
        Node* inOrderSuccesor = IS(node->right);
        node->value = inOrderSuccesor->value;
        node->right = delNode(node->right, inOrderSuccesor->value); // case1, case2
    }

    return node;
}

int main() {
    int arr[] = {8, 10, 11, 14, 5, 3, 6, 1, 4};
    int size = sizeof(arr) / sizeof(int);

    Node* root = buildBST(arr, size);

    cout << "Level Order Traversal : " << endl;
    levelOrder(root);

    delNode(root, 5);

    cout << endl;
    levelOrder(root);
    
    return 0;
}