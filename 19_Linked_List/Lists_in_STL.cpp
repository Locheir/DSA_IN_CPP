#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void printList(list<int> ll) {
    // Iterators in C++ are objects that allow you to traverse
    // through the elements of a container in sequential manner.

    list<int>:: iterator itr;

    for (itr = ll.begin(); itr!=ll.end(); itr++) {
        cout << *itr << "->";
    }    

    cout << "NULL" << endl;
}

int main() {
    list<int> ll;
    ll.push_front(0);
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);

    printList(ll);

    cout << ll.size() << endl;
    cout << ll.front() << endl;
    cout << ll.back() << endl;
    
    ll.pop_front();
    printList(ll);

    ll.pop_back();
    printList(ll);

    return 0;
}