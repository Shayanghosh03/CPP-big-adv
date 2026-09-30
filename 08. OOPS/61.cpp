#include<iostream>
using namespace std;

class Car {
    public:

    string name;
    string color;
    int *mileage;

    Car(string name, string color) {
        this -> name = name;
        this -> color = color;
        mileage = new int;
        *mileage = 12;
    }

    Car(Car &original) { // Custome copy constructor
        cout << "Copy..." << endl;
        name = original.name;
        color = original.color;
        mileage = new int;
        *mileage = *original.mileage; // Deep Copy in shallow copy dont need the DMA and mileage = original.mileage;
    }

    void getDetails() {
        cout << name << endl;
        cout << color << endl;
        cout << *mileage << endl;
    }

    ~Car() {
        cout << "Deleting the object.." << endl;

        if(mileage != NULL) {
            delete mileage;
            mileage = NULL;
        }
    }
};

int main() {
    Car c1("Maruti 800", "White");
    cout << "C1 Details => " << endl;
    c1.getDetails();

    Car c2(c1);
    cout << "C2 Details =>" << endl;
    c2.getDetails();

    *c2.mileage = 10;

    cout << "c1 mileage => " << *c1.mileage << endl;
    cout << "c2 mileage => " << *c2.mileage << endl;

    return 0;
}