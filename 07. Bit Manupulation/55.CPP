#include<iostream>
using namespace std;

void updateIthbit(int num, int pos, int val) {
    num = num & (~(1 << pos));

    num = num | (val << pos);

    cout << num << endl;
}

void clearLastIthBit(int num, int pos) {
    int bitMask = (~0) << pos;

    num = num & bitMask;

    cout << num << endl;
}

void countSetBits(int num) {
    int count = 0;

    while(num > 0) {
        int lastBit = num & 1;
        count += lastBit;
        num = num >> 1;
    }

    cout << "Set bit count is => " << count << endl;
} 

int main() {

    updateIthbit(6, 2, 0);

    clearLastIthBit(15, 2);

    countSetBits(10);

    return 0;
}