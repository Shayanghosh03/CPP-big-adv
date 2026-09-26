#include<iostream>
using namespace std;

int setIthBit(int num, int pos) {
    int bitMask = (1 << pos);

    return (num | bitMask);
}

int clearIthBit(int num, int pos) {
    int bitMask = ~(1 << pos);

    return (num & bitMask);
}

bool powerOf2(int num) {
    if(!(num & (num - 1))) {
        return true;
    } else {
        return false;
    }
}

int main() {

    cout << "SetBit value is => " << setIthBit(6, 3) << endl;
    
    cout << "ClearBit value is => " << clearIthBit(6, 1) << endl;

    powerOf2(8) ? cout << "true" : cout << "false" << endl;
    powerOf2(15) ? cout << "true" : cout << "false" << endl;

    return 0;
}