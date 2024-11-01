#include <iostream>
#include <vector>
using namespace std;

class Node {
    public :
        int value;
        Node *next;
    
        Node(int value) {
            this->value = value;
            this->next = NULL;
        }

        ~Node() {
            // cout << "Destructor of Node !" << endl;
            if (next!=NULL) {
                delete next;
                next = NULL;
            }
        }
};

class LinkedList {
    private :
        Node *head;
        Node *tail;

    public :
        LinkedList() {
            head = NULL;
            tail = NULL;
        }

        ~LinkedList() {
            // cout << "Destructor of LinkedList !" << endl;
            if (head != NULL) {
                delete head;
                head = NULL;
            }
        }

        void push_front(int value) {
            Node* newNode = new Node(value);

            if (this->head == NULL) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }

        }

        void push_back(int value) {
            Node* newNode = new Node(value);

            if (this->head == NULL) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        void printList() {
            Node* tmpNode = head;

            while (tmpNode != NULL) {
                cout << tmpNode->value;
                if (tmpNode->next != NULL) {
                    cout << "->";
                }
                tmpNode = tmpNode->next;
            }
            cout << endl;
        }

        void insert(int value, int pos) {
            Node* newNode = new Node(value);
            Node * tmpNode = head;

            for (int i=0; i<pos-1; i++) {
                if (tmpNode == NULL) {
                    cout << "Position is INVALID" << endl;
                    return;
                }
                tmpNode = tmpNode->next;
            }

            newNode->next = tmpNode->next;
            tmpNode->next = newNode;
        }

        void pop_front() {
            if (head == NULL) {
                cout << "Linked List is Empty !" << endl;
                return;
            }

            Node* tmp_node = head;
            head = head->next;
            tmp_node->next = NULL;
            cout << "Removed Element : " << tmp_node->value << endl;
            delete tmp_node;        
        }

        void pop_back() {
            if (head == NULL) {
                cout << "Linked List is Empty !" << endl;
                return;
            }

            Node * tmp_node = head;
            while (tmp_node->next != tail) {
                tmp_node = tmp_node->next;
            }
            Node* popped_node = tail;
            tail = tmp_node;
            tail->next = NULL;
            cout << "Removed Element : " << popped_node->value << endl;
            delete popped_node;  
        }

        int search(int key) {
            int count = 0;
            Node* tmp_node = head;

            while (tmp_node != NULL) {
                if (tmp_node->value == key) {
                    return count;
                }
                tmp_node = tmp_node->next;
                count++;
            }

            return -1;
        }

        int rec_search(int key) {
            Node* tmp_node = head;
            int count = 0;
            return searching(tmp_node, key,count);
        }

        int searching(Node* tmp_node, int key, int count) {
            if (tmp_node == NULL) {
                return -1;
            }
            if (tmp_node->value == key) {
                return count;
            }

            searching(tmp_node->next, key, ++count);
        }

        void reverse() {
            Node* curr = head;
            Node* prev = NULL;

            while (curr != NULL) {
                Node* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            Node* tmp = head;
            head = tail;
            tail = tmp;
        }
        
        int size() {
            int count = 0;
            Node* tmp_node = head;
            
            while (tmp_node != NULL) {
                count++;
                tmp_node = tmp_node->next;
            }

            return count;
        }

        void nthNodeFromBack(int n) {
            int size = this->size();
            Node* tmp_node = head;
            
            for (int i=1; i<(size-n); i++) {
                tmp_node = tmp_node->next;
            }

            Node* popped_node = tmp_node->next;
            tmp_node->next = popped_node->next;
            cout << "Deleted Node : " << popped_node->value << endl;
            popped_node->next = NULL;
            delete popped_node;
        }

        string returnList() {
            Node* tmp_node = head;
            string temp = "";

            while (tmp_node != NULL) {
                temp += tmp_node->value;
                tmp_node = tmp_node->next;
            }

            return temp;
        }

        bool isPalindrome() {
            string asc = returnList();

            this->reverse();

            string desc = returnList();

            this->reverse();
            
            if (asc == desc) {
                return true;
            } else {
                return false;
            }
        }
};

int main() {
    LinkedList ll;

    // ll.push_front(3);
    // ll.push_front(2);
    // ll.push_front(1);
    // ll.push_back(4);
    // ll.push_back(5);

    // ll.printList();

    // ll.insert(20, 2);

    // ll.printList();

    // ll.pop_front();

    // ll.printList();

    // ll.pop_back();
    // ll.printList();

    // cout << ll.search(9) << endl;
    // cout << ll.rec_search(1) << endl;

    // ll.printList();
    // ll.reverse();
    // ll.printList();

    // ll.nthNodeFromBack(3);
    // ll.printList();

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(2);
    ll.push_back(1);

    ll.printList();

    cout << ll.isPalindrome() << endl;

    return 0;
}