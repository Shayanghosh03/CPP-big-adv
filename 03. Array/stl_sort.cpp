#include<iostream>
#include<algorithm>
using namespace std;

int main() {    
    int arr[] = {10,45,67,23,89,23,45,90,12,67};
    int n = sizeof(arr) / sizeof(arr[0]);

    // sort(arr, arr+n);
    // sort(arr+2, arr+6);
    sort(arr, arr+n, greater<int>());

    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}