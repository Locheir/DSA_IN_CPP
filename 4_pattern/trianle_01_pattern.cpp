#include <iostream>
using namespace std;

int main() {

    int num;
    int zero_or_one = 1;

    cout << "Enter No of Rows : ";
    cin >> num;

    for(int i=0; i<num; i++) {
        if ((i+1)%2!=0) {
            zero_or_one = 1;
        } else {
            zero_or_one = 0;
        }
        for (int j=i; j>=0; j--){
            cout << zero_or_one << " ";
            if (zero_or_one==0) {
                zero_or_one = 1;
            } else {
                zero_or_one = 0;
            }
        }
        cout << endl;
    }

    return 0;
}