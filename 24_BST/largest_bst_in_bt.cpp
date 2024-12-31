#include <iostream>
#include <queue>
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

class Info {
    public :
        bool isBST;
        int min;
        int max;
        int sz;

        Info(bool isBST, int min, int max, int sz) {
            this->isBST = isBST;
            this->min = min;
            this->max = max;
            this->sz = sz;
        }
};

static int maxSize;

Info* largestBST(Node* node) {

    if(node == NULL) {
        return new Info(true, INT_MAX, INT_MIN, 0);
    }

    Info* leftInfo = largestBST(node->left);
    Info* rightInfo = largestBST(node->right);

    int currMin = min(node->value, min(leftInfo->min, rightInfo->min));
    int currMax = max(node->value, max(leftInfo->max, rightInfo->max));
    int currSz = leftInfo->sz + rightInfo->sz + 1;

    if (leftInfo->isBST && rightInfo->isBST
        && node->value > leftInfo->max 
        && node->value < rightInfo->min) {
            maxSize = max(maxSize, currSz);
            return new Info(true, currMin, currMax, currSz);
    }

    return new Info(false, currMin, currMax, currSz);
}

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    levelOrder(root);

    largestBST(root);

    cout << "Max Length : " << maxSize; 
    return 0;
}