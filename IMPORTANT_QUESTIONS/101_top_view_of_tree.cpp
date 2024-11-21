#include <iostream>
#include <map>
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
        }
};

static int idx = -1;

Node* buildTree(vector<int> nodes) {
    idx++;
    if(nodes[idx] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

void topViewOfTree(Node* node) {
    queue<pair<Node*,int>> Q;
    map<int,int> M; // (Horizontal Distance, Node->data)

    Q.push(make_pair(node,0));

    while(!Q.empty()) {
        pair<Node*, int> currPair = Q.front();
        Q.pop();

        Node* currNode = currPair.first;
        int currHD = currPair.second;

        if (!M.count(currHD)) {
            M[currHD] = currNode->value;
        }

        if(currNode->left != NULL) {
            pair<Node*, int> left = make_pair(currNode->left, currHD-1);
            Q.push(left);
        }

        if(currNode->right != NULL) {
            pair<Node*, int> right = make_pair(currNode->right, currHD+1);
            Q.push(right);
        }
    }

    for(auto it:M) {
        cout << it.second << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    topViewOfTree(root);

    return 0;
}