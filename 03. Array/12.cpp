#include<iostream>
using namespace std;

int binarySearch(int *arr, int n, int key) {
    int start = 0, end = n-1;

    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(arr[mid] == key) {
            return mid;
        }
        if(key > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10,20,30,40,50,60,70};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 60;

    int result = binarySearch(arr, n, key);

    cout<<"Position :"<<result+1<<endl;

    return 0;
}