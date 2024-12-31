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

void LevelOrder(Node* node) {
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

void inOrder(Node* node) {
    if (node == NULL) {
        return;
    }

    inOrder(node->left);
    cout << node->value << " ";
    inOrder(node->right);
}

bool search(Node* node, int val) {
    if (node == NULL) {
        cout << "Data not found" << endl;
        return false;
    }
    
    if (val == node->value) {
        cout << "Data found" << endl;
        return true;
    } 

    if (val < node->value) {
        return search(node->left, val);
    } else {
        return search(node->right, val);
    }
}

int main() {
    int n = 7;
    int arr[n] = {55, 98, 23, 61, 24, 10, 70};

    Node* root = buildBST(arr, n);

    inOrder(root);

    cout << endl;

    cout << search(root, 22);
    return 0;
}