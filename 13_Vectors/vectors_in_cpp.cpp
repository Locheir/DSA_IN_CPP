#include <iostream>
#include <vector>
using namespace std;



int main() {
    vector<int> vec1 = {1, 2, 3, 4};
    cout << "Length : " << vec1.size() << "\n";

    for (int i=0; i<vec1.size(); i++) {
        cout << vec1[i] << " "; 
    }

    return 0;
}