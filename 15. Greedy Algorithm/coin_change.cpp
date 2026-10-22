#include<iostream>
#include<vector>
using namespace std;

int getMinChnange(vector<int> coin, int v) {
    int n = coin.size();
    int ans = 0;
    for(int i = n-1; i >= 0 && v > 0; i--) {
        if(coin[i] <= v) {
            ans += v/coin[i];
            v = v%coin[i];
        }
    }
    return ans;
}

int main() {
    vector<int> coin = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int v = 590;
    int ans = getMinChnange(coin, v);

    cout << "Ans => " << ans << endl;

    return 0;
}