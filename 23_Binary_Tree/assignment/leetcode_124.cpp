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

void levelOrderTraversal(Node* root) {
    queue<Node*> Q;
    Q.push(root);
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

int calMax(Node* node, int &m) {
    if (node == NULL) {
        return 0;
    }

    int left = max(0, calMax(node->left, m));
    int right = max(0, calMax(node->right, m));

    m = max(m, left + right + node->value);

    return max(left, right) + node->value;
}

int maxPathSum(Node* root) {
    int max = root->value;

    calMax(root, max);

    return max;
}

int main() {
    vector<int> nums = {-10,9,-1,-1,20,15,-1,-1,7,-1,-1};

    Node* root = buildTree(nums);

    levelOrderTraversal(root);

    cout << maxPathSum(root) << endl;
    return 0;
}