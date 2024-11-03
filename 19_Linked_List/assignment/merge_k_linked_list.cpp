#include <iostream>
#include <vector>
using namespace std;

class Node {
    public :
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = NULL;
        }
};

class LinkedList {
    public : 
        Node* head;
        Node* tail;

        LinkedList() {
            head = tail = NULL;
        }

        void push_back(int value) {
            Node* new_node = new Node(value);

            if (head == NULL) {
                head = tail = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
        }

        void printList() {
            if (head == NULL) {
                cout << "Linked List is Empty!" << endl;
                return;
            }

            Node* tmp_node = head;

            while (tmp_node != NULL) {
                cout << tmp_node->value;
                if (tmp_node->next != NULL) {
                    cout << "->";
                }
                tmp_node = tmp_node->next;
            }

            cout << endl;
        }
};

Node* merge2List(Node* list1, Node* list2) {

    if (list1 == NULL && list2 == NULL) {
        return NULL;
    } 
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    Node* head_prev = new Node(-1);
    Node* tmp_l1 = list1;
    Node* tmp_l2 = list2;

    Node* tmp_node = head_prev;

    while (tmp_l1 != NULL && tmp_l2 != NULL) {
        if (tmp_l1->value < tmp_l2->value) {
            tmp_node->next = tmp_l1;
            tmp_l1 = tmp_l1->next;
        } else {
            tmp_node->next = tmp_l2;
            tmp_l2 = tmp_l2->next;
        }
        tmp_node = tmp_node->next;
    }

    if (tmp_l1 != NULL) {
        tmp_node->next = tmp_l1;
    }

    if (tmp_l2 != NULL) {
        tmp_node->next = tmp_l2;
    }

    return head_prev->next;
}

Node* mergekList(vector<Node*> arr) {

    if (arr.size() == 0) {
        return NULL;
    }

    if (arr.size() == 1) {
        return list[0];
    }

    Node* head = arr[0];

    for(int i=1; i<arr.size(); i++) {
        head = merge2List(head, arr[i]);
    }

    return head;
}

int main() {
    LinkedList ll;

    ll.push_back(1);
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(9);

    ll.printList();

    LinkedList ll2;
    
    ll2.push_back(2);
    ll2.push_back(3);
    ll2.push_back(7);
    ll2.push_back(10);

    ll2.printList();

    LinkedList ll3;

    ll3.push_back(4);
    ll3.push_back(8);

    ll3.printList();

    LinkedList ll4;

    ll4.push_back(0);

    ll4.printList();

    vector<Node*> arr;

    arr.push_back(ll.head);
    arr.push_back(ll2.head);
    arr.push_back(ll3.head);
    arr.push_back(ll4.head);

    ll4.head = mergekList(arr);

    ll4.printList();

    return 0;
}