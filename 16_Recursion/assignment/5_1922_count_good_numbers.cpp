#include <iostream>
using namespace std;
#define MOD 1000000007;

long long power(int num, long long pow) {
    if (pow == 0) {
        return 1;
    }
    long long ans = power(num, pow/2);
    ans = (ans*ans)%MOD;
    if (pow%2==1) {
        ans = (ans*num)%MOD;
    }
    return ans;

}

int countGoodNumbers(int num) {
    long long odd = num/2;
    long long even = num/2 + num%2;
    return (power(5,even)*power(4,odd))%MOD;
}

int main() {
    int num = 1;
    cout << countGoodNumbers(num);
    return 0;
}