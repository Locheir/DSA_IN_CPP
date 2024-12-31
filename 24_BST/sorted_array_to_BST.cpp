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

Node* sortedArrayToBST(int arr[], int l, int r) {
    if (l > r) {
        return NULL;
    }

    int mid = l + (r-l)/2;

    Node* node = new Node(arr[mid]);

    node->left = sortedArrayToBST(arr, l, mid-1);
    node->right = sortedArrayToBST(arr, mid+1, r);

    return node;
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

int main() {
    int arr[] = {3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(int);

    Node* root = sortedArrayToBST(arr, 0, 6);

    LevelOrder(root);

    return 0;
}