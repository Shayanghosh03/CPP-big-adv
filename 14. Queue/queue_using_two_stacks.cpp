#include<iostream>
#include<stack>
using namespace std;

class Queue {
    stack<int> s1;
    stack<int> s2;
public:
    void push(int data) { // O(n)
        // s1 -> s2;
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(data);
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop() {
        s1.pop();
    }
     
    int front() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
    Queue q1;

    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);

    while(!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }
     cout << endl;

    return 0;
}