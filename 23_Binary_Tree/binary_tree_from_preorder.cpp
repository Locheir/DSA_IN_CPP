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

class BinaryTree {
    private :
        Node* root;
};

Node* buildTree(vector<int> nodes) {
    
}

int main() {
    vector<int> arr = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    return 0;
}