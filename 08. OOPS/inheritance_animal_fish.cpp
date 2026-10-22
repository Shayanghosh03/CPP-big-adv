#include<iostream>
using namespace std;

class Animal {
    public:
    void eat() {
        cout << "Eating.." << endl;
    }

    void breath() {
        cout << "Breathing..." << endl;
    }
};

class Fish : public Animal{
    public:

    int fins;

    void swim() {
        eat();
        cout << "Swiming" << endl;
    }
};

int main() {
    Fish f1;

    f1.fins = 4;

    cout << f1.fins << endl;
    f1.swim();
    f1.eat();
    f1.breath();

    return 0;
}