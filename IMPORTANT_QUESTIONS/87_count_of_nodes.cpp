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

int countNodes(Node* node) {
    if (node == NULL) {
        return 0;
    }

    int left_count = countNodes(node->left);
    int right_count = countNodes(node->right);

    return left_count+right_count+1;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    cout << countNodes(root);

    return 0;
}