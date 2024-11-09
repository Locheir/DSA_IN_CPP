#include <iostream>
using namespace std;

class Node {
    public :
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            this->next = NULL;
        }
};

class Queue {
    private :
        Node* head;
        Node* tail;

    public :
        Queue() {
            head = tail = NULL;
        }

        void enqueue(int value) {
            Node* new_node = new Node(value);

            if (head == NULL) {
                head = tail = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
        }

        void dequeue() {
            if (head == NULL) {
                cout << "Cannot Dequeue form Empty Queue !" << endl;
                return;
            }

            Node* popped_Node = head;
            head = head->next;
            popped_Node->next = NULL;
            delete popped_Node;
        }

        int front() {
            if (head == NULL) {
                cout << "Queue is Empty !" << endl;
                return -1;
            }

            return head->value;
        }

        bool empty() {
            return head == NULL;
        }
};

int main() {

    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    while(!q.empty()) {
        cout << q.front() << endl;
        q.dequeue();
    }

    return 0;
}