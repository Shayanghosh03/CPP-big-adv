#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

void countSort(int *arr, int n) {
    int freq[100000];
    int minVal = INT_MAX, maxVal = INT_MIN;
    for(int i = 0; i < n; i++) {
        // if(arr[i] < minVal) {
        //     minVal = arr[i];
        // }
        // if(arr[i] > maxVal) {
        //     maxVal = arr[i];
        // }

        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }

    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    for(int i = minVal, j = 0; i <= maxVal, j < n; i++) {
        while(freq[i] > 0) {
            arr[j] = i;
            j++;
            freq[i]--;
        }
    }
}

int main() {
    int arr[] = {10,45,23,78,56,90,28,49};
    int n = sizeof(arr) / sizeof(arr[0]);

    countSort(arr, n);

    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}