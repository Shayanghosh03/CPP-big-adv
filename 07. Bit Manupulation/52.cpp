#include<iostream>
using namespace std;

void oddEvenCheck2(int num) {
    if(num % 2 == 0) {
        cout << "Even number" << endl;
    } else {
        cout << "Odd number" << endl;
    }
}

void oddEvenCheck(int num) {
    if(!(num & 1)) {
        cout << "Even Number" << endl;
    } else {
        cout << "Odd Number" << endl; 
    }
}

int main() {
    oddEvenCheck(8);
    oddEvenCheck(5);

    oddEvenCheck2(6);

    return 0;
}