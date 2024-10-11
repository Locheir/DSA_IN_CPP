#include <iostream>
using namespace std;

class ComplexNum {
    private :
        int real;
        int img;
    
    public :
        ComplexNum(int real, int img) {
            this->real = real;
            this->img = img;
        }

        ComplexNum operator - (ComplexNum &num2) {
            int temp_real = this->real - num2.real;
            int temp_img = this->img - num2.img;
            ComplexNum c3(temp_real, temp_img);
            return c3;
        }

        void show() {
            cout << real << " + " << img << "i \n";
        }

};

int main() {
    ComplexNum c1(2, 1);
    ComplexNum c2(1, 4);

    ComplexNum c3 = c1 - c2;

    c3.show();

    return 0;
}