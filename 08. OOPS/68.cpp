#include<iostream>
using namespace std;

class Parent {
    public:
    void show() {
        cout << "Parent class show.." << endl;
    }

    virtual void hello() { // Child class must redifine this funtion with different implementation
        cout << "Parent hello" << endl;
    }
};

class Child : public Parent {
    public:
    void show() {
        cout << "Child class show.." << endl;
    }

    void hello() {
        cout << "Child Hello" << endl;
    }
};

int main() {
    Child c1;
    c1.show();
    c1.hello();

    Parent *ptr;
    ptr = &c1; // Runtime Binding
    ptr -> hello();

    return 0;
}