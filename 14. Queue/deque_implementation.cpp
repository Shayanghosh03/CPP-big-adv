#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Deque {
    queue<int> q;
public:
    void push_back(int data) {
        q.push(data);
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