#include<iostream>
using namespace std;

void reverseArr(int *arr, int n) {
    int coppyArr[n];
    for(int i = 0; i < n; i++) {
        int j = n-i-1;
        coppyArr[i] = arr[j];
    }

    for(int i = 0; i < n; i++) {
        arr[i] = coppyArr[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    reverseArr(arr, n);

    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}