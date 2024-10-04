#include <iostream>
using namespace std;

int main() {

    int sum = 0;
    int num ;

    cout << "Enter the N th Natural Number : ";
    cin >> num;

    for (int i=1; i<=num; i++){
        sum += i;
    }

    cout << "Sum of "<< num << " Natural Numbers is : " << sum;
    
    return 0;
}