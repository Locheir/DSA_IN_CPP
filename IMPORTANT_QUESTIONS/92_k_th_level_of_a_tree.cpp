#include <iostream>
#include <vector>
#include <queue>
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

void KthLevelOfTree(Node* node, int level) {
    queue<pair<Node*, int>> Q;
    Q.push(make_pair(node, 1));

    while (!Q.empty()) {
        pair<Node*, int> curr = Q.front();
        Q.pop();

        Node* currNode = curr.first;
        int currLevel = curr.second;

        if (currLevel == level) {
            cout << currNode->value << " ";
        }

        if (currNode->left != NULL) {
            pair<Node*, int> temp = make_pair(currNode->left, currLevel+1);
            Q.push(temp);
        }

        if (currNode->right != NULL) {
            pair<Node*, int> temp = make_pair(currNode->right, currLevel+1);
            Q.push(temp);
        }
    }
}

void helper(Node* node, int K, int currLevel) {
    if(currLevel == K) {
        cout << node->value << " ";
        return;
    }

    if (node->left != NULL) {
        helper(node->left, K, currLevel+1);
    }

    if (node->right != NULL) {
        helper(node->right, K, currLevel+1);
    }
}

void Kth_Level_using_Recursion(Node* root, int K) {
    helper(root, K, 1);
}

int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    Kth_Level_using_Recursion(root, 3);

    return 0;
}