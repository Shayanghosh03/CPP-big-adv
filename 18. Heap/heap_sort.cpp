#include<iostream>
#include<vector>
using namespace std;

void heapify(int parIdx, vector<int> &arr, int n) {
    int leftIdx = 2 * parIdx + 1;
    int rightIdx = 2 * parIdx + 2;

    int maxIdx = parIdx;

    if(leftIdx < n && arr[leftIdx] > arr[maxIdx]) {
        maxIdx = leftIdx;
    }
    if(rightIdx < n && arr[rightIdx] > arr[maxIdx]) {
        maxIdx = rightIdx;
    }

    if(maxIdx != parIdx) {
        swap(arr[maxIdx], arr[parIdx]);
        heapify(maxIdx, arr, n);
    }
}

void heapSort(vector<int> &arr) {
    int n = arr.size();

    // Step 1 => build max heap
    for(int i = n/2 - 1; i >= 0; i--) {
        heapify(i, arr, n);
    }

    // Step 2 => taking els to correct pos
    for(int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(0, arr, i);
    }
}

int main() {
    vector<int> arr = {1, 4, 2, 5, 3};
    heapSort(arr);

    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}