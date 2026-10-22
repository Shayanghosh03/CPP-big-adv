#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int start, int mid, int end) {
    vector<int> ans;
    int i = start;
    int j = mid+1;

    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            ans.push_back(arr[i]);
            i++;
        } else {
            ans.push_back(arr[j]);
            j++;
        }
    }
    while(i <= mid) {
        ans.push_back(arr[i]);
        i++;
    }
    while(j <= end) {
        ans.push_back(arr[j]);
        j++;
    }

    for(int i = start, x = 0; i <= end; i++, x++) {
        arr[i] = ans[x];
    }
}

void mergeSort(int arr[], int start, int end) {
    if(start >= end) {
        return;
    }

    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    merge(arr, start, mid, end);
}

int main() {
    int arr[6] = {6, 3, 7, 5, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n-1);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}