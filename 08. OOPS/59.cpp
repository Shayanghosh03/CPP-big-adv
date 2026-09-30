#include<iostream>
using namespace std;

class Car  {
    string name;
    string color;
    int price;

    public:

    Car() {
        cout << "Constructor without constructor..." << endl;
    }

    Car(string name, string color, int price) {
        cout << "Constructor called..." << endl;
        // name = nameVal;
        // color = colorVal;
        // price = priceVal;
        this -> name = name;
        this -> color = color;
        this->price = price;
    }

    void start() {
        cout << "Car is started.." << endl;
    }

    void stop() {
        cout << "Car is stopped.." << endl;
    }

    // Getter

    void getCarDeatils() {
        cout << name << endl;
        cout << color << endl;
        cout << price << endl;
    }
};

int main() {
    Car c1("Maruti 800", "White", 120000);
    Car c2;

    c1.start();

    c1.getCarDeatils();

    return 0;
}