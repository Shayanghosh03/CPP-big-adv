#include<iostream>
#include<algorithm>
using namespace std;

void selectionSort(int *arr, int n) {
    for(int i = 0; i < n-1; i++) {
        int minIdx = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
                break;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

int main() {
    int arr[] = {10,34,67,23,89,34};
    int n = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr, n);

    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}