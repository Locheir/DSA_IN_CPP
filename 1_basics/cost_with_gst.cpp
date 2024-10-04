#include<iostream>
using namespace std;

int main() {
    float pencil;
    float pen;
    float eraser;

    cout << "Enter cost of Pencil : ";
    cin >> pencil;
    cout << "Enter cost of Pen : ";
    cin >> pen;
    cout << "Enter cost of Eraser : ";
    cin >> eraser;

    float total = pencil + pen + eraser;
    total += (total * 0.18);

    cout << "Total Cost with 18% GST : "<< total;

    return 0;
}