#include <iostream>
using namespace std;

int main() {
    int month_num;

    cout << "Enter the number of Month : ";
    cin >> month_num;

    switch(month_num) {
        case 1:
            cout << "January";
            break;
        case 2:
            cout << "Febraury";
            break;
        case 3:
            cout << "March";
            break;
        case 4:
            cout << "April";
            break;
        case 5:
            cout << "May";
            break;
        case 6:
            cout << "June";
            break;
        case 7:
            cout << "July";
            break;
        case 8:
            cout << "August";
            break;
        case 9:
            cout << "September";
            break;
        case 10:
            cout << "October";
            break;
        case 11:
            cout << "November";
            break;
        case 12:
            cout << "December";
            break;
        default:
            cout << "Month Number can be from 1 to 12 only!";
            break;
    }

    return 0;
}