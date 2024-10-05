#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4};
    cout << "size : " << vec.size() << endl;
    cout << "capacity : " << vec.capacity() << endl;

    // push_back(num) : used to add in vector
    vec.push_back(5);
    cout << "size : " << vec.size() << endl;
    cout << "capacity : " << vec.capacity() << endl;

    vec.push_back(6);
    cout << "size : " << vec.size() << endl;
    cout << "capacity : " << vec.capacity() << endl;

    // pop_back() : used to delete the last element.
    vec.pop_back();
    cout << "size : " << vec.size() << endl;
    cout << "capacity : " << vec.capacity() << endl;
    return 0;
}