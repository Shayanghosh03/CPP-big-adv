#include<iostream>
using namespace std;

void inputArr(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
}

int main() {
    int arr[25] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(int);

    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int arr2[5];
    inputArr(arr2, 5);
    for(int i = 0; i < 5; i++) {
        cout<<arr2[i]<<" ";
    }

    cout<<endl;

    return 0;
}