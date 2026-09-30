#include<iostream>
using namespace std;

class Animal {
    public:
    void breath() {
        cout << "Breathing..." << endl;
    } 
};

class Dog : public Animal {
    public :
    void sound() {
        cout << "Bhaow Bhaow" << endl;
    }
};

class Cat : public Animal {
    public:
    void tailWalk() {
        cout << "Dog Walk" << endl;
    }
};

int main() {
    Cat c1;
    c1.breath();

    Dog d1;
    d1.breath();

    return 0;
}