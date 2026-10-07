#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void stockSpan(vector<int> stock, vector<int> &span) {
    stack<int> s;
    span[0] = 1;
    s.push(0);

    for(int i = 1; i < stock.size(); i++) {
        int currPrice = stock[i];
        while(!s.empty() && currPrice >= stock[s.top()]) {
            s.pop();
        }
        if(s.empty()) {
            span[i] = i + 1;
        } else {
            int prevHigh = s.top();
            span[i] = i - prevHigh;
        }
        s.push(i);
    }
}

int main() {
    vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
    int n = stock.size();
    vector<int> span(n, 0);

    stockSpan(stock, span);

    for(int i : span) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}