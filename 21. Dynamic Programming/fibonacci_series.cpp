#include<iostream>
#include<vector>
using namespace std;

int fib(int n) { // O(log(n))
    if(n == 0 || n == 1) { 
        return n;
    }

    return fib(n-1) + fib(n-2);
}

// DP -> Memoization
int fibDP(int n, vector<int>& f) { // O(n)
    if(n == 1 || n == 0) {
        return n;
    }

    if(f[n] != -1) {
        return f[n];
    }

    f[n] = fibDP(n-1, f) + fibDP(n-2, f);
}

// DP -> Tabulation
int fibDP2(int n) {
    vector<int> f(n+1, -1);
    f[0] = 0;
    f[1] = 1;

    for(int i = 2; i < n+1; i++) {
        f[i] = f[i-1] + f[i-2];
    }

    return f[n];
}

int main() {
    int n = 8;
    vector<int> f(n+1, -1);

    cout << fib(n) << endl;

    cout << fibDP(n, f) << endl;

    cout << fibDP2(n) << endl;

    return 0;
}