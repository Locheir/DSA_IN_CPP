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

void levelOrderTraversal(Node* node) {
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

            if(curr->left != NULL) {
                Q.push(curr->left);
            }

            if(curr->right != NULL) {
                Q.push(curr->right);
            }
        }
    }
}   

bool isIdentical(Node* tree1, Node* tree2) {
    if (tree1 == NULL && tree2 == NULL) {
        return true;
    } else if (tree1 == NULL || tree2 == NULL) {
        return false;
    }

    if (tree1->value != tree2->value) {
        return false;
    }

    return isIdentical(tree1->left, tree2->left) 
           && isIdentical(tree1->right, tree2->right);
}

bool isSubTree(Node* node, Node* subTree) {
    if (node == NULL && subTree == NULL) {
        return true;
    } else if (node == NULL || subTree == NULL) {
        return false;
    }

    if(node->value == subTree->value) {
        if(isIdentical(node, subTree)) {
            return true;
        }
    }

    int leftSubTree = isSubTree(node->left, subTree);

    if (!leftSubTree) {
        return isSubTree(node->right, subTree);
    }

    return true;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    Node* subTree = new Node(2);
    subTree->left = new Node(4);
    subTree->right = new Node(5);

    cout << isSubTree(root, subTree);

    return 0;
}