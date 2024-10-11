// Compile Time Polymorphism
//  2. Operator Overloading 

#include <iostream>
using namespace std;

class Complex {
    private :
        int real;
        int imaginary;

    public :
        Complex(int real, int imaginary) {
            this->real = real;
            this->imaginary = imaginary;
        }

        void showNum() {
            cout << real << " + " << imaginary << "i \n";
        }

        Complex operator + (Complex &c2) {
            int temp_real = this->real + c2.real;
            int temp_img = this->imaginary + c2.imaginary;
            Complex c3(temp_real, temp_img);
            return c3;
        }
};

int main() {
    
    Complex c1(1, 2);
    Complex c2(3, 4);
    c1.showNum();
    c2.showNum();

    Complex c3 = c1 + c2;
    c3.showNum();

    return 0;
}