#include<iostream>
using namespace std;

int girdWays(int row, int col, int n, int m, string ans) {
    if(row == n-1 && col == m-1) {
        cout << ans << " ";
        return 1;
    }

    if(row >= n || col >= m) {
        return 0;
    }

    // Right
    int val1 = girdWays(row, col+1, n, m, ans+"R");

    // Down
    int val2 = girdWays(row+1, col, n, m, ans+"D");

    return val1+val2;
}

int main() {
    int n = 3;
    int m = 3;
    string ans = "";
    cout << "Total Ways => " << girdWays(0, 0, n, m, ans) << endl;

    return 0;
}