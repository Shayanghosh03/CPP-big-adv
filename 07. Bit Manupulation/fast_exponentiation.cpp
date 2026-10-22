#include<iostream>
using namespace std;

int fastExpo(int x, int n) {
    int ans = 1;
    while(n > 0) {
        int lastBit = n & 1;
        if(lastBit) {
            ans = ans * x;
        }
        x = x * x;
        n = n >> 1;
    }
    return ans;
}

int main() {

    cout << fastExpo(3, 5) << endl;

    return 0;
}