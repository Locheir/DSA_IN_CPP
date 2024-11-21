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

Node* deleteNodeswithGivenValues(Node* node, int target) {
    if (node == NULL) {
        return NULL;
    }

    Node* leftNode = deleteNodeswithGivenValues(node->left, target);
    Node* rightNode = deleteNodeswithGivenValues(node->right, target);

    if (node->left != NULL && leftNode == NULL) {
        node->left = NULL;
    }

    if (node->right != NULL && rightNode == NULL) {
        node->right = NULL;
    }

    if (node->value == target && leftNode == NULL && rightNode == NULL) {
        return NULL;
    }

    return node;
}

void LevelOrderTraversal(Node* node) {
    queue<Node*> Q;
    Q.push(node);
    Q.push(NULL);

    while (!Q.empty()) {
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

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 2, -1, -1, 3, -1, 2, -1, -1};

    Node* root = buildTree(nodes);

    LevelOrderTraversal(root);

    root = deleteNodeswithGivenValues(root, 2);

    LevelOrderTraversal(root);

    return 0;
}