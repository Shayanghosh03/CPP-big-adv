#include<iostream>
using namespace std;

class Example {
    public:
    Example() {
        cout << "Constructor..." << endl;
    }

    ~Example() {
        cout << "Distructor..." << endl;
    }
};

int main() {
    int a = 0;

    if(a == 0) {
        Example e1;
    }

    cout << "Code Ending..." << endl;

    return 0;
}