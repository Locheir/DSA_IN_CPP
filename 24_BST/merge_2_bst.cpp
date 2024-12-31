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
            left = NULL;
            right = NULL;
        }
};

void inOrder(Node* node, vector<int> &arr) {
    if (node == NULL) {
        return;
    }

    inOrder(node->left, arr);
    arr.push_back(node->value);
    inOrder(node->right, arr);
}

vector<int> merge(vector<int> arr1, vector<int> arr2) {
    vector<int> ans;
    int end1 = arr1.size()-1;
    int end2 = arr2.size()-1;
    int i=0; 
    int j=0;

    while (i<=end1 && j<=end2) {
        if (arr1[i] < arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
        } else {
            ans.push_back(arr2[j]);
            j++;
        }
    }

    while (i<=end1) {
        ans.push_back(arr1[i]);
        i++;
    }

    while (j<=end2) {
        ans.push_back(arr2[j]);
        j++;
    }

    return ans;
}

Node* BuildBST(vector<int> arr, int st, int ed) {
    if (st > ed) {
        return NULL;
    }

    int mid = (st + ed)/2;

    Node* currNode = new Node(arr[mid]);
    currNode->left = BuildBST(arr, st, mid-1);
    currNode->right = BuildBST(arr, mid+1, ed);

    return currNode;
}

Node* mergeBST(Node* root1, Node* root2) {
    vector<int> arr1;
    vector<int> arr2;

    inOrder(root1, arr1);
    inOrder(root2, arr2);

    vector<int> mergelist = merge(arr1, arr2);

    return BuildBST(mergelist, 0, mergelist.size()-1);
}

void inOrderPrint(Node* node) {
    if (node == NULL) {
        return;
    }

    inOrderPrint(node->left);
    cout << node->value << " ";
    inOrderPrint(node->right);
}

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
                return;
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
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    Node* root3 = mergeBST(root1, root2);

    levelOrder(root3);
    cout << endl;
    inOrderPrint(root3);

    return 0;
}