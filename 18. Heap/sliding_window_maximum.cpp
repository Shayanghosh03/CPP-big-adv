#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void slidongWindowMax(vector<int> arr, int k) {
    priority_queue<pair<int, int>> pq;
    vector<int> ans;

    for(int i = 0; i < k; i++) {
        pq.push(make_pair(arr[i], i));
    }
    ans.push_back(pq.top().first);

    for(int i = k; i < arr.size(); i++) {
        if(!pq.empty() && pq.top().second <= (i - k)) {
            pq.pop();
        }
        pq.push(make_pair(arr[i], i));
        ans.push_back(pq.top().first);
    }

    for(int i = 0 ; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    slidongWindowMax(arr, k);


    return 0;
}