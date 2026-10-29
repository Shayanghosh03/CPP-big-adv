#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int largestSubWith0Sum(vector<int> arr) {
    unordered_map<int, int> m; // key-> Sum value-> idx
    int sum = 0;
    int ans= 0;

    for(int j = 0; j < arr.size(); j++) {
        sum += arr[j];
        if(m.count(sum)) {
            int currLength = j - m[sum];
            ans = max(ans, currLength); 
        } else {
            m[sum] = j;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {15, -2, 3, -8, 1, 7, 10};
    cout << largestSubWith0Sum(arr) << endl;

    return 0;
}