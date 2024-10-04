#include <iostream>
using namespace std;

int main() {
    int nums[3][3] = {
        {1, 4, 9},
        {11, 4, 3},
        {2, 2, 3}
    };

    for(int i=0, j=1; i<3; i++) {
        cout << nums[j][i] << " ";
    }

    return 0;
}