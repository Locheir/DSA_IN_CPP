#include<iostream>
using namespace std;

int main() {
    
    float sci;
    float eng;
    float maths;

    cout << "Enter English Marks : ";
    cin >> eng;
    cout << "Enter Science Marks : ";
    cin >> sci;
    cout << "Enter Maths Marks : ";
    cin >> maths;

    float avg = (eng + sci + maths) / 3;
    cout << "Average : " << avg;

    return 0;
}