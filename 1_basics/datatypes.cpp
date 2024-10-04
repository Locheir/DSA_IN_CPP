#include<iostream>
using namespace std;

int main() {

    int a = 10;
    char ch = 'a';
    bool b = false;
    float f = 1.43f;
    double d = 2.34532;

    cout << "value : "<< a <<" , size : "<< sizeof(int)<< endl;
    cout << "value : "<< ch <<" , size : "<< sizeof(char)<< endl;
    cout << "value : "<< b <<" , size : "<< sizeof(bool)<< endl;
    cout << "value : "<< f <<" , size : "<< sizeof(float)<< endl;
    cout << "value : "<< d <<" , size : "<< sizeof(double)<< endl;

    return 0;
}