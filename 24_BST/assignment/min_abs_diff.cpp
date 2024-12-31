#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
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

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
}

Node* buildBST(vector<int> arr) {
    Node* root = NULL;

    for(int i=0; i<arr.size(); i++) {
        root = insert(root, arr[i]);
    }

    return root;
}

void levelOrder(Node* node) {
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

static int minAbs = INT_MAX;

int min_abs_diff(Node* node, int K) {
    if (node == NULL) {
        return INT_MAX;
    }

    int left_abs = min_abs_diff(node->left, K);
    int right_abs = min_abs_diff(node->right, K);
    int curr_abs;

    if (K < node->value) {
        curr_abs = node->value - K;
    } else {
        curr_abs = K - node->value;
    }

    return min(curr_abs, min(left_abs, right_abs));

}

int main() {
    vector<int> arr = {8, 5, 3, 6, 11, 20};

    Node* root = buildBST(arr);

    levelOrder(root);

    cout << min_abs_diff(root, 19);

    return 0;
}