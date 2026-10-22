#include<iostream>
using namespace std;

class A {
    string secret = "hsr98pw7rtbif";
    friend class B;
    friend void revealSecret(A &obj);
};

class B {
    public:
    void showSecret(A &obj) {
        cout << obj.secret << endl;
    }
};

void revealSecret(A &obj) {
    cout << obj.secret << endl;
}

int main() {
    A a1;
    B b2;

    b2.showSecret(a1);

    revealSecret(a1);

    return 0;
}