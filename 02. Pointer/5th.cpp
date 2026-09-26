#include<iostream>
using namespace std;

void num(int a) {
    a = 20;
    cout<<a<<endl;
}

void changeA(int *ptr) {
    *ptr = 20;

    cout<<*ptr<<endl;
}

void chnageB(int &b) {
    b = 40;
    cout<<b<<endl;
}

int main() {
    int a = 10;
    num(a);
    cout<<a<<endl;

    changeA(&a);
    cout<<a<<endl;
    
    int b = 30;
    chnageB(b);
    cout<<b<<endl;

    return 0;
}