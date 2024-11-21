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

bool isValid(Node* node, int value) {
    if (node == NULL) {
        return true;
    }

    if (node->value != value) {
        return false;
    }

    return isValid(node->left, value) && isValid(node->right, value);
}

bool isUnivalued(Node* root) {
    if (root == NULL) {
        return true;
    }

    int value = root->value;

    return isValid(root, value);
}

int main() {

    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    vector<int> nodes2 = {1, 1, 1, 1};

    Node* root2 = buildTree(nodes2);

    cout << isUnivalued(root2);

    return 0;
}