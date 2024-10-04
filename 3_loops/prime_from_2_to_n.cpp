#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num;
    int count=2;

    cout << "Enter a Number : ";
    cin >> num;

    while (count <= num) {
        bool isprime = true;

        for (int i=2; i<=sqrt(count);i++){
            if (count%i==0){
                isprime = false;
                break;
            }
        }

        if (isprime) {
            cout << count << endl;
        }

        count++;
    }

    return 0;
}