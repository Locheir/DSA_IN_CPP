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

Node* LCA(Node* node, int n1, int n2) {
    if (node == NULL) {
        return NULL;
    }

    if (node->value == n1 || node->value == n2) {
        return node;
    }

    Node* leftLCA = LCA(node->left, n1, n2);
    Node* rightLCA = LCA(node->right, n1, n2);

    if (leftLCA != NULL && rightLCA != NULL) {
        return node;
    }

    return leftLCA == NULL ? rightLCA : leftLCA;
}

int dist(Node* node, int n) {
    if (node == NULL) {
        return -1;
    }

    if (node->value == n) {
        return 0;
    }

    int left_dist =  dist(node->left, n);

    if (left_dist != -1) {
        return left_dist + 1;
    } 

    int right_dist = dist(node->right, n);

    if (right_dist != -1) {
        return right_dist + 1;
    }

    return -1;
}

int minDist(Node* node, int n1, int n2) {
    Node* lca = LCA(node, n1, n2);

    int dist1 = dist(lca, n1);
    int dist2 = dist(lca, n2);

    return dist1 + dist2;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    cout << minDist(root, 4, 6);

    return 0;
}