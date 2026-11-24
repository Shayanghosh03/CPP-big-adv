#include<iostream>
#include<vector>
using namespace std;

int knapSackRec(vector<int> val, vector<int> wt, int w, int n) {
    if(n == 0 || w == 0) {
        return 0;
    }
    int itemval = val[n-1];
    int itemwt = wt[n-1];

    if(itemwt <= w) {
        // Including
        int ans1 = knapSackRec(val, wt, w - itemwt, n - 1) + itemval;

        // Excluding
        int ans2 = knapSackRec(val, wt, w, n - 1);

        return max(ans1, ans2);
    } else {
        return knapSackRec(val, wt, w, n - 1);
    }
}

// Dynamic Programming - Memoization (Top Down Approach)
int knapSackDP(vector<int> val, vector<int> wt, int w, int n, vector<vector<int>>& dp) {
    if(n == 0 || w == 0) {
        return 0;
    }

    if(dp[n][w] != -1) {
        return dp[n][w];
    }

    int itemval = val[n - 1];
    int itemwt = wt[n - 1];

    if(itemwt <= w) {
        // Including
        int ans1 = knapSackDP(val, wt, w - itemwt, n - 1, dp) + itemval;
        
        // Esclusing
        int ans2 = knapSackDP(val, wt, w, n - 1, dp);

        dp[n][w] = max(ans1, ans2);
    } else {
        // Excluding
        dp[n][w] = knapSackDP(val, wt, w, n - 1, dp);
    }

    return dp[n][w];
}

// Dynamic Programming - Tabulation (Bottom Up Approach)
int knapSackDP2(vector<int> val, vector<int> wt, int w, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < w + 1; j++) {
            int itemval = val[i - 1];
            int itemwt = wt[i - 1];

            if(itemwt <= j) {
                // Including
                int ans1 = dp[i - 1][j - itemwt] + itemval;

                // Excluding
                int ans2 = dp[i - 1][j];

                dp[i][j] = max(ans1, ans2);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][w];
}

int main() {
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int w = 7;
    int n = 5;

    cout << knapSackRec(val, wt, w, n) << endl;

    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));

    cout << knapSackDP(val, wt, w, n, dp) << endl;

    cout << knapSackDP2(val, wt, w, n) << endl;

    return 0;
}