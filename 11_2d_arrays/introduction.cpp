#include <iostream>
using namespace std;

int main() {
    int n,m;

    cout << "Enter No of Student : ";
    cin >> n;

    cout << "Enter No of Subjects : ";
    cin >> m;

    int student[n][m] = {};

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout <<"Enter marks for Subject " << j+1 << " for Student " << i+1 << " : ";
            cin >> student[i][j];
        }
    }

    for (int i=0; i<n; i++) {
        cout << "Student No " << i+1 << " : ";
        for (int j=0; j<m; j++) {
            cout << student[i][j] << " ";
        }
        cout << endl;
    }    

    return 0;
}