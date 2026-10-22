#include<iostream>
#include<climits>
using namespace std;

int main() {
    int arr[] {2,8,5,9,10,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    int max = INT_MIN;

    for(int i = 0; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    cout<<max<<endl;

    return 0;
}