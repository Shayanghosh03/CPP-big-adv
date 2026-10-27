#include<iostream>
#include<queue>
using namespace std;

int main() {
    priority_queue<int> pq; // MAX HEAP
    cout << "MAX HEAP" << endl;

    pq.push(9);
    pq.push(4);
    pq.push(1);
    pq.push(10);
    pq.push(14);
    pq.push(3);

    cout << "Top element of priority queue => " << pq.top() << endl;

    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    priority_queue<int, vector<int>, greater<int>> min_pq; // MIN HEAP
    cout << "MIN HEAP" << endl;

    min_pq.push(9);
    min_pq.push(4);
    min_pq.push(1);
    min_pq.push(10);
    min_pq.push(14);
    min_pq.push(3);

    cout << "Top element of priority queue => " << min_pq.top() << endl;

    while(!min_pq.empty()) {
        cout << min_pq.top() << " ";
        min_pq.pop();
    }
    cout << endl;

    return 0;
}