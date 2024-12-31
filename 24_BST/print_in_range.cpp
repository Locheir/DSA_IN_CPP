#include <iostream>
#include <queue>
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

    if (value < node->value) {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }

    return node;
}

Node* buildTree(int arr[], int n) {
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

void printRange(Node* node, int st, int en) {
    if (node == NULL) {
        return;
    }

    if (node->value >= st && node->value <= en) {
        printRange(node->left, st, en);
        cout << node->value << " ";
        printRange(node->right, st, en);
    } else if (node->value < st) {
        printRange(node->right, st, en);
    } else {
        printRange(node->left, st, en);
    }
}

int main() {
    int arr[] = {8, 10, 11, 14, 5, 6, 3, 1, 4};
    int size = sizeof(arr) / sizeof(int);

    Node* root = buildTree(arr, size);

    levelOrder(root);
    cout << endl;

    printRange(root, 5, 12);

    return 0;
}