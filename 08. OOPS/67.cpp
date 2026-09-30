#include<iostream>
using namespace std;

class Complex {
    int real;
    int img;

    public:
    Complex(int real, int img) {
        this -> real = real;
        this -> img = img;
    }
    
    void show() {
        cout << real << " + " << img << "i" << endl;
    }

    void operator + (Complex &c2) {
        int resReal = this -> real + c2.real;
        int resImg = this -> img + c2.img;
        Complex c3(resReal, resImg);

        c3.show();
    }
};

int main() {
    Complex c1(5, 2);
    c1.show();

    Complex c2(4, 3);
    c2.show();

    cout << "Result is => " << endl;
    
    c1 + c2; // Operator Overloading

    return 0;
}