#include<iostream>
using namespace std;

int getIthBit(int num, int i) {
    int bitMusk = (1 << i);

    if(!(num & i)) {
        return 0;
    } else {
        return 1;
    }
}

int main() {

    cout << getIthBit(6, 2) << endl;
    cout << getIthBit(4, 2) << endl;


    return 0;
}