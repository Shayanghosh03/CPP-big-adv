#include<iostream>
using namespace std;

int linearSearch(int *arr, int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {20,45,6,89,23,3,9,13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 23;

    int position = linearSearch(arr, n, key);

    cout<<position+1<<endl;
    return 0;
}