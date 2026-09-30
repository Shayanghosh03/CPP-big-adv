#include<iostream>
using namespace std;

class Print {
    public:

    void show(int num) {
        cout << num << endl;
    }

    void show(string str) {
        cout << str << endl;
    }
};

int main() {
    Print p1;
    p1.show(9);
    p1.show("Shayan");

    return 0;
}