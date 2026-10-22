#include<iostream>
#include<stack>
#include<vector>
using namespace std;
 
void nextGreater(vector<int> arr, vector<int> &ans) { // O(n)
    stack<int> s;
    int idx = arr.size()-1;
    ans[idx] = -1;
    s.push(arr[idx]);

    for(idx = idx-1; idx >= 0; idx--) {
        int curr = arr[idx];
        while(!s.empty() && curr >= s.top()) {
            s.pop();
        }
        if(s.empty()) {
            ans[idx] = -1;
        } else {
            ans[idx] = s.top();
        }
        s.push(curr);
    }
}

int main() {
    vector<int> arr = {6, 8, 0, 1, 3};
    int n = arr.size();
    vector<int> ans(n, 0);

    nextGreater(arr, ans);

    cout << "Next Greater elements => " << endl;

    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}