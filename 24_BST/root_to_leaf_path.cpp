#include <iostream>
#include <queue>
#include <vector>
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

void printArr(vector<int> arr) {

    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void backTrack(Node* node, vector<int> &nums) {
    if (node == NULL) {
        return;
    }

    nums.push_back(node->value);

    if (node->left == NULL && node->right == NULL) {
        printArr(nums);
        nums.pop_back();
        return;
    }
    
    backTrack(node->left, nums);
    backTrack(node->right, nums);
    nums.pop_back();
}

void RootToLeaf(Node* root) {
    vector<int> nums;
    backTrack(root, nums);
}

int main() {
    int arr[] = {8, 10, 11, 14, 5, 6, 3, 1, 4};
    int size = sizeof(arr) / sizeof(int);

    Node* root = buildTree(arr, size);

    levelOrder(root);
    cout << endl;

    RootToLeaf(root);

    return 0;
}