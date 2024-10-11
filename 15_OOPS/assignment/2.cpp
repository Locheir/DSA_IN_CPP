#include <iostream>
using namespace std;

class BankAccount {
    private :
        int accNum;
        double bal;

    public :
        BankAccount(int accNum, double bal) {
            this->accNum = accNum;
            this->bal = bal;
        }

        void deposit(double bal) {
            this->bal += bal;
            cout << this->bal << endl;
        }

        void withdraw(double bal) {
            if (this->bal >= bal) {
                this->bal -= bal;
                cout << this->bal << endl;
            } else {
                cout << "Insufficient Balance" << endl;
            }
        }

        void getBalance() {
            cout << bal << endl;
        }
};  

int main() {
    BankAccount b1(1212,15000);
    b1.getBalance();
    b1.deposit(1000);
    b1.deposit(5000);
    b1.withdraw(25000);
    b1.withdraw(11000);
    b1.getBalance();

    return 0;
}