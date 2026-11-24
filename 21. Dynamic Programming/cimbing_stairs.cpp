#include<iostream>
#include<vector>
using namespace std;
 
int countWayRec(int n) { // o(n^2)
    if(n == 0 || n == 1) {
        return 1;
    }

    return countWayRec(n - 1) + countWayRec(n - 2);
}

// Dynamic Programming - Memoization
int countWayDP(int n, vector<int>& dp) { // o(n)
    if(n == 0 || n == 1) {
        return 1;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n] = countWayDP(n - 1, dp) + countWayDP(n - 2, dp);

    return dp[n];
}

// Dynamic Programming - Tabulation
int countWayDP2(int n) { // O(n)
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i < dp.size(); i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// Using Tabulation in 1, 2 & 3 Climbs
int countWayDP3(int n) { // O(n)
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i < dp.size(); i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}

int main() {
    int n = 5;

    cout << countWayRec(n) << endl;

    vector<int> dp(n + 1, -1);
    cout << countWayDP(n, dp) << endl;

    cout << countWayDP2(n) << endl;

    cout << countWayDP3(n) << endl;

    return 0;
}