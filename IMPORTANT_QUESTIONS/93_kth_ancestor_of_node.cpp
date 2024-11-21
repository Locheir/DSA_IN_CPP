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
        }
};

static int idx = -1;

Node* buildTree(vector<int> nodes) {
    idx++;

    if (nodes[idx] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

int KthAncestorOfNode(Node* root, int value, int n) {
    if (root == NULL) {
        return -1;
    }

    if (root->value == value) {
        return 0;
    }
    
    int leftDist = KthAncestorOfNode(root->left, value,  n);
    int rightDist = KthAncestorOfNode(root->right, value,  n);

    if (leftDist == -1 && rightDist == -1) {
        return -1;
    }

    int validValue = leftDist == -1 ? rightDist : leftDist;

    if (validValue + 1 == n) {
        cout << root->value << endl;
    }

    return validValue + 1;
}

int main() {
    
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    KthAncestorOfNode(root, 5, 2);

    return 0;
}