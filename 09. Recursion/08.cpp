#include<iostream>
using namespace std;

int tilingProblem(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }

    // vertical
    int ans1 = tilingProblem(n-1); // 2x(n-1)

    // Horizontal
    int ans2 = tilingProblem(n-2); // 2x(n-2);

    return ans1 + ans2; // return tilingProblem(n-1) + tilingProblem(n-2)
}

int main() {
    cout << tilingProblem(3) << endl;

    return 0;
}