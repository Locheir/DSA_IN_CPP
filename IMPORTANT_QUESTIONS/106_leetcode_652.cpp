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

string findDuplicates(Node* node, vector<string> &res, map<string,int> &M) {
    if (node == NULL) {
        return "null";
    }

    string leftSide = findDuplicates(node->left, res, M);
    string rightSide = findDuplicates(node->right, res, M);

    string total = leftSide +','+ rightSide +','+ to_string(node->value);

    if (M[total] == 1) {
        res.push_back(total);
    }

    M[total]++;

    return total;
}

void findDuplicateSubTrees(Node* node) {
    vector<string> res;
    map<string, int> M;

    findDuplicates(node, res, M);

    for(int i=0; i<res.size(); i++) {
        cout << "[ " << res[i] << " ] , ";
    }
    cout << endl;
}

int main() {
    vector<int> input = {1,2,4,-1,-1,-1,3,2,4,-1,-1,-1,4,-1,-1};

    Node* root = buildTree(input);

    // levelOrderTraversal(root);

    findDuplicateSubTrees(root);

    return 0;
}