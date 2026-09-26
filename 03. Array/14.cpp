#include<iostream>
#include<algorithm>
using namespace std;

void bubbleSort(int *arr, int n) {
    for(int i = 0; i < n-1; i++) {
        bool isSwap = false;
        for(int j = 0; j < (n-i-1); j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap) {
            return;
        }
    }
}

int main() {
    int arr[] = {10,45,23,78,45,26,90};
    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, n);

    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}