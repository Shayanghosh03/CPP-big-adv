#include<iostream>
using namespace std;

void binaryDecimal(int num) {
    int n = num;
    int dec = 0;
    int pow = 1;

    while(n != 0) {
        int dig = n % 10;
        dec += dig * pow;
        pow = pow * 2;
        n = n / 10;
    }
    cout<<dec<<endl;
}

void decimalBinary(int num) {
    int n = num;
    int binary = 0;
    int pow = 1;

    while(n != 0) {
        int rem = n % 2;
        binary += rem * pow;
        pow = pow * 10;
        n = n / 2;
    }
    cout<<binary<<endl;
}

int main() {
    binaryDecimal(101);
    decimalBinary(4);

    return 0;
}