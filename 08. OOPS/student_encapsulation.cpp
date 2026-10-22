#include<iostream>
#include<string>
using namespace std;

class Student {
    string name;
    float cgpa;

    public:

    void setName(string newName) {
        name = newName;
    }
    void setCgpa(float newCgpa) {
        cgpa = newCgpa;
    }

    string getName() {
        return name;
    }

    float getCgpa() {
        return cgpa;
    }
};

int main() {
    Student s1;
    s1.setName("Shayan Ghosh");
    s1.setCgpa(8.57);

    cout << s1.getName() << endl;
    cout << s1.getCgpa() << endl;

    return 0;
}