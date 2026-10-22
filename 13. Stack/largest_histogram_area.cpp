#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int maxAreaHistogram(vector<int> height) {
    int n = height.size();
    vector<int> nsl(n);
    stack<int> s;

    nsl[0] = -1;
    s.push(0);
    for(int i = 1; i < height.size(); i++) {
        int curr = height[i];
        while(!s.empty() && curr <= height[s.top()]) {
            s.pop();
        }
        if(s.empty()) {
            nsl[i] = -1;
        } else {
            nsl[i] = s.top();
        }
        s.push(i);
    }
    while(!s.empty()) {
        s.pop();
    }

    vector<int> nsr(n);
    nsr[n-1] = n;
    s.push(n-1);

    for(int i = n-2; i >= 0; i--) {
        int curr = height[i];
        while(!s.empty() && curr <= height[s.top()]) {
            s.pop();
        }
        if(s.empty()) {
            nsr[i] = n;
        } else {
            nsr[i] = s.top();
        }
        s.push(i);
    }

    int maxArea = 0;
    for(int i = 0; i < n; i++) {
        int ht = height[i];
        int width = nsr[i] - nsl[i] - 1;
        int area = ht * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    vector<int> height = {2, 1, 5, 6, 2, 3};

    cout << maxAreaHistogram(height) << endl;

    return 0;
}