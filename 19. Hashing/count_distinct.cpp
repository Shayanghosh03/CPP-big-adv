#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int countDistinct(vector<int> nums) {
    unordered_set<int> s;

    for(int i = 0; i < nums.size(); i++) {
        s.insert(nums[i]);
    }

    return s.size();
}

int main() {
    vector<int> nums = {4, 3, 2, 5, 6, 7, 3, 4, 2, 1};

    cout << countDistinct(nums) << endl;

    return 0;
}