#include<iostream>
using namespace std;

class Solution {
    public:
    static int x;
};

int Solution::x = 0; // :: scope operator 

int main() {
    Solution s1;
    Solution s2;
    Solution s3;

    cout << s1.x++ << endl;
    cout << s2.x++ << endl;
    cout << s3.x++ << endl;

    return 0;
}