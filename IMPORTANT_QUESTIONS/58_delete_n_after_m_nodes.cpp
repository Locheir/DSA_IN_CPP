#include <iostream>
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

        void remove_n_after_m(int m, int n) {
            int i = 1;
            int j = 0;

            Node* tmp_node = head;

            while (tmp_node != NULL) {
                for (int i=1; i<m && tmp_node != NULL; i++) {
                    tmp_node = tmp_node->next;
                }

                if (tmp_node == NULL) {
                    return;
                }

                Node* temp = tmp_node->next;

                for (int j = 0; j < n && temp != NULL; j++) {
                    Node* nodeToDelete = temp;
                    tmp_node->next = temp->next;
                    temp = temp->next;
                    nodeToDelete->next = NULL;
                    delete nodeToDelete;
                }

                tmp_node->next = temp;
                tmp_node = temp;
            }

        }
};



int main() {
    LinkedList ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    ll.push_back(8);

    ll.printList();
    ll.remove_n_after_m(2,2);
    ll.printList();

    return 0;
}