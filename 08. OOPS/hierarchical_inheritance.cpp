#include<iostream>
using namespace std;

class Teaher {
    public:
    int salary;
    string subject;
};

class Student {
    public:
    int rollNumber;
    float cgpa;
};

class TA : public Teaher, public Student {
    public:

    string name;

    TA() {
        cout << "TA Details" << endl;
    }
};

int main() {
    TA t1;
    t1.name = "Shayan Ghosh";
    t1.rollNumber = 40;
    t1.subject = "Data Structure & Algorithm";
    t1.salary = 50000;

    cout << t1.name << endl;
    cout << t1.rollNumber << endl;
    cout << t1.subject << endl;
    cout << t1.salary << endl;

    return 0;
}