#include<iostream>
#include<deque>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_front(10);
    dq.push_front(20);
    dq.push_back(50);
    dq.push_back(88);

    // 20 <-> 10 <-> 50 <-> 88

    cout << dq.front() << endl;
    cout << dq.back() << endl;

    dq.pop_front();
    dq.pop_back();

    cout << dq.front() << endl;
    cout << dq.back() << endl;

    return 0;
}