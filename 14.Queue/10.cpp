#include<iostream>
#include<queue>
using namespace std;

class Deque {
    queue<int> q;
public:
    void push_back(int data) {
        q.push(data);
    }

    void pop_front() {
        q.pop();
    }

    int front() {
        return q.front();
    }

    bool isEmpty() {
        return q.empty();
    }

};

int main() {
    Deque dq;

    dq.push_back(10);
    dq.push_back(30);
    dq.push_back(40);

    cout << dq.front() << endl;

    return 0;
}