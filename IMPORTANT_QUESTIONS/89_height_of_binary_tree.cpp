#include <iostream>
#include <vector>
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

int heightOfTree(Node* node) {
    if (node == NULL) {
        return 0;
    }

    int left_height = heightOfTree(node->left);
    int right_height = heightOfTree(node->right);

    return max(left_height, right_height) + 1;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    cout << heightOfTree(root);

    return 0;
}