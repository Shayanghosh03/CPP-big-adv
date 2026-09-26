#include<iostream>
using namespace std;

void insertionSort(int *arr, int n) {
    for(int i = 1; i < n; i++) {
        int curr = arr[i];
        int prev = i-1;

        while(prev >= 0 && arr[prev] > curr) {
            swap(arr[prev], arr[prev+1]);
            prev--;
        }
        arr[prev+1] = curr;
    }
}

int main() {
    int arr[] = {12,56,23,78,48,23,90};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}