#include<iostream>
using namespace std;

class Student {
    public:
    string name;
    float cgpa;

    void getPercentage() {
        cout << (cgpa * 10) << endl;
    }
};

class User {
    int id;
    string unsername;
    string password;
    string bio;

    void deactivate() {
        cout << "Deleting the account" << endl;
    }

    void editBio(string newBio) {
        bio = newBio;
    }
};

int main() {
    Student s1;
    s1.name = "Shayan Ghosh";

    cout << s1.name << endl;  
    return 0;
}