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

bool findPath(Node* node, vector<int> &path, int num) {
    if (node == NULL) {
        return false;
    }

    path.push_back(node->value);

    if (node->value == num) {
        return true;
    }

    int isLeft = findPath(node->left, path, num);
    int isRight = findPath(node->right, path, num);

    if (isLeft || isRight) {
        return true;
    } else {
        path.pop_back();
        return false;
    }
}

int LowestCommonAncestor(Node* node, int n1, int n2) {
    vector<int> path1;
    vector<int> path2;

    findPath(node, path1, n1);
    findPath(node, path2, n2);

    int lca = -1;
    for(int i=0, j=0; i<path1.size() && j<path2.size(); i++, j++) {
        if (path1[i] != path2[i]) {
            return lca;
        }
        lca = path1[i];
    }
}

Node* LCA_optimized(Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }

    if (root->value == n1 || root->value == n2) {
        return root;
    }

    Node* leftLCA = LCA_optimized(root->left, n1, n2);
    Node* rightLCA = LCA_optimized(root->right, n1, n2);

    if (leftLCA != NULL && rightLCA != NULL) {
        return root;
    }

    return leftLCA == NULL ? rightLCA : leftLCA;
}

int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    cout << LCA_optimized(root, 4, 6)->value;

    return 0;
}