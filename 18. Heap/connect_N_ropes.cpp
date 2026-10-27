#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int connectNropes(vector<int> ropes) {
    priority_queue<int, vector<int>, greater<int>> pq(ropes.begin(), ropes.end()); // O(n)
    int cost = 0;

    while(pq.size() > 1) {
        int p1 = pq.top();
        pq.pop();
        int p2 = pq.top();
        pq.pop();

        cost += p1 + p2;

        pq.push(p1 + p2);
    }

    return cost;
}

int main() {
    vector<int> ropes = {4, 3, 2, 6};

    cout << "Minimum cost is => " << connectNropes(ropes) << endl;

    return 0;
}