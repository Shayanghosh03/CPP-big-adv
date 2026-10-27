#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

struct Compare {
    bool operator () (pair<string, int> &p1, pair<string, int> &p2) {
        return p1.second < p2.second;
    }
};

int main() {
    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;

    pq.push(make_pair("Shayan", 500));
    pq.push(make_pair("Sumanta", 600));
    pq.push(make_pair("Arnab", 478));
    pq.push(make_pair("Yansh", 534));
    pq.push(make_pair("Manika", 223));
    pq.push(make_pair("Naon", 354));

    while(!pq.empty()) {
        cout << pq.top().first << ", " << pq.top().second << endl;
        pq.pop();
    }
    cout << endl;

    return 0;
}