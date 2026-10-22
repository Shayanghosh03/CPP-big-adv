#include<iostream>
using namespace std;

int Pow(int x, int n) {
    if(n == 0) {
        return 1;
    }

    int halfPower = Pow(x, n/2);
    int halfPowerSquare = halfPower * halfPower;

    if(n % 2 != 0) {
        return x * halfPowerSquare;
    }

    return halfPowerSquare;
}

int main() {

    cout << Pow(2, 10) << endl;

    return 0;
}