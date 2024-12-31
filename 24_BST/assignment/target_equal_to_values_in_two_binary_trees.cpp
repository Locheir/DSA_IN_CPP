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

Node* buildBST(vector<int> arr) {
    Node* root = NULL;

    for(int i=0; i<arr.size(); i++) {
        root = insert(root, arr[i]);
    }

    return root;
}

Node* levelOrder(Node* node) {
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

void inOrderArray(Node* node, vector<int> &arr) {
    if (node == NULL) {
        return;
    }

    inOrderArray(node->left, arr);
    arr.push_back(node->value);
    inOrderArray(node->right, arr);
}

bool equalSumTwoBST(Node* root1, Node* root2, int target) {
    vector<int> arr1;
    vector<int> arr2;

    inOrderArray(root1, arr1);
    inOrderArray(root2, arr2);

    int i = 0;
    int j = arr2.size() - 1;

    while (i < arr1.size() && j >= 0) {
        int curr = arr1[i] + arr2[j];
        if ( curr == target) {
            return true;
        }

        if (curr < target) {
            i++;
        } else {
            j--;
        }
        
    }

    return false;
}

int main() {
    vector<int> arr1 = {3, 4, 1};
    vector<int> arr2 = {8,1,20};

    Node* root1 = buildBST(arr1);
    Node* root2 = buildBST(arr2);

    levelOrder(root1);
    levelOrder(root2);

    cout << equalSumTwoBST(root1, root2, 29);
    return 0;
}