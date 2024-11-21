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
    if(node == NULL) {
        return 0;
    }

    int l_cnt = heightOfTree(node->left);
    int r_cnt = heightOfTree(node->right);

    return max(l_cnt, r_cnt) + 1;
}

int diameterOfTree_n_square_approach(Node* node) {

    if (node == NULL) {
        return 0;
    }

    int currD = heightOfTree(node->left) + heightOfTree(node->right) + 1;
    int leftD = diameterOfTree_n_square_approach(node->left);
    int rightD = diameterOfTree_n_square_approach(node->right);

    return max(max(currD, leftD),rightD);
}

pair<int, int> diameterOfTree_n_approach(Node* node) {

    if (node == NULL) {
        return make_pair(0,0);
    }

    //(diameter, height)
    pair<int, int> leftInfo = diameterOfTree_n_approach(node->left);
    pair<int, int> rightInfo = diameterOfTree_n_approach(node->right);

    int currD = leftInfo.second + rightInfo.second + 1;
    int finalD = max(currD, max(leftInfo.first, rightInfo.second));
    int finalHt = max(leftInfo.second, rightInfo.second) + 1;

    return make_pair(finalD, finalHt);

}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    cout << diameterOfTree_n_approach(root).first;

    return 0;
}