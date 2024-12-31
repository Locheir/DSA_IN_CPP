#include<iostream>
#include<vector>
#include<queue>
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

Node* buildBST(vector<int> arr) {
    Node* root = NULL;

    for(int i=0; i<arr.size(); i++) {
        root = insert(root, arr[i]);
    }

    return root;
}

void inOrder(Node* node, vector<int> &arr){
    if (node == NULL) {
        return;
    }

    inOrder(node->left, arr);
    arr.push_back(node->value);
    inOrder(node->right, arr);
}

int KthSmallestElement(Node* root, int K) {
    vector<int> arr;

    inOrder(root, arr);

    return arr[K-1];
}

void levelOrder(Node* root) {
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

int main() {
    vector<int> arr = {7,5,4,6,11,13,9};
    Node* root = buildBST(arr);

    levelOrder(root);
    int K = 3;
    cout << "Kth Smallest Element is " << KthSmallestElement(root, K);
    return 0;
}