#include<iostream>
using namespace std;

//Abstract Class
class Shape {
    public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
    public:
    void draw() {
        cout << "Draw circle" << endl;
    }
};

int main() {
    Circle c1;
    c1.draw();

    return 0;
}