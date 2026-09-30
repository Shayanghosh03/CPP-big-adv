#include<iostream>
using namespace std;

class Car {
    string name;
    string color;

    public:

    Car(string name, string color) {
        this -> name = name;
        this -> color = color;
    }

    Car(Car &original) { // Custome copy constructor
        cout << "Copy..." << endl;
        this -> name = original.name;
        this -> color = original.color;
    }

    void getDetails() {
        cout << name << endl;
        cout << color << endl;
    }
};

int main() {
    Car c1("Maruti 800", "White");

    Car c2(c1);
    c2.getDetails();

    return 0;
}