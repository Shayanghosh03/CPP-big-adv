#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int maxChainLength(vector<pair<int, int>> pair) {
    int n = pair.size();
    sort(pair.begin(), pair.end(), compare);

    int ans = 1;
    int currEnd = pair[0].second;
    for(int i = 1; i < n; i++) {
        if(currEnd <= pair[i].first) {
            ans++;
            currEnd = pair[i].second;
        }
    }
    return ans;
}

int main() {
    int n = 5;
    vector<pair<int, int>> pair(n, make_pair(0, 0));
    pair[0] = make_pair(5, 24);
    pair[1] = make_pair(39, 60);
    pair[2] = make_pair(5, 28);
    pair[3] = make_pair(27, 40);
    pair[4] = make_pair(50, 90);

    int ans = maxChainLength(pair);

    cout << "Maximum Chain Length is => " << ans << endl;

    return 0;
}