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

Node* buildBST(vector<int> arr) {
    Node* root = NULL;

    for(int i=0; i<arr.size(); i++) {
        root = insert(root, arr[i]);
    }

    return root;
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

void printArr(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void inOrder(Node* root, vector<int> &seq) {
    if(root == NULL) {
        return;
    }

    inOrder(root->left, seq);
    seq.push_back(root->value);
    inOrder(root->right, seq);
}

Node* BalancedBST(vector<int> arr, int st, int en) {
    if (st > en) {
        return NULL;
    }

    int mid = st + (en - st)/2;

    Node* node = new Node(arr[mid]);
    node->left = BalancedBST(arr, st, mid-1);
    node->right = BalancedBST(arr, mid+1, en);

    return node;
}

Node* convertToBST(Node* root) {
    vector<int> inOrderSeq;

    inOrder(root, inOrderSeq);

    return BalancedBST(inOrderSeq, 0, inOrderSeq.size()-1);
}

int main() {
    vector<int> arr = {6, 5, 4, 3, 7, 8, 9};

    Node* root = buildBST(arr);

    convertToBST(root);

    root = convertToBST(root);

    levelOrder(root);

    return 0;
}