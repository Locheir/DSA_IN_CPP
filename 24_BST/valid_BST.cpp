#include <iostream>
#include <vector>
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

bool check(Node* node, Node* min, Node* max) {
    if (node == NULL) {
        return true;
    }

    if (min != NULL && node->value < min->value) {
        return false;
    }
    if (max != NULL && node->value > max->value) {
        return false;
    }

    return check(node->left, min, node->value) && check(node->right, node->value, max);
}

bool validateBST(Node* root) {
    return check(root, NULL, NULL);
}
int main() {
    
    return 0;
}