#include<iostream>
using namespace std;

class Animal {
    public:
    void breath() {
        cout << "Breathing" << endl;
    }
};

class Mammel : public Animal {
    public:
    string bloodType;

    Mammel() {
        bloodType = "Worm";
    }
};

class Dog : public Mammel {
    public:
    void tailWalk() {
        cout << "Dog walk.." << endl;
    }
};

int main() {
    Dog d1;
    cout << d1.bloodType << endl;

    d1.tailWalk();
    d1.breath();

    return 0;
}