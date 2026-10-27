#include<iostream>
#include<string>
#include<queue>
using namespace std;

class Student { // '<' operator overloading
public:
    string name;
    int marks;

    Student(string name, int marks) {
        this -> name = name;
        this -> marks = marks;
    }

    bool operator < (const Student &obj) const {
        return this -> marks < obj.marks;
    }
};

int main() {
    priority_queue<Student> pq;

    pq.push(Student("Shayan", 500));
    pq.push(Student("Sumanta", 600));
    pq.push(Student("Arnab", 478));
    pq.push(Student("Yansh", 534));
    pq.push(Student("Manika", 223));
    pq.push(Student("Naon", 354));

    while(!pq.empty()) {
        cout << pq.top().name << ", " << pq.top().marks << endl;
        pq.pop();
    }
    cout << endl;

    return 0;
}