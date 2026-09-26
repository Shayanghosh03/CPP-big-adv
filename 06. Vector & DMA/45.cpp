#include<iostream>
using namespace std;

int main() {
    // Dynamic Menmory Allocation
    int *newInt = new int;
    *newInt = 50;
    cout<<*newInt<<endl;

    delete newInt;

    int size;
    cin>>size;
    int *arr = new int[size];
    int x = 0;
    for(int i = 0; i < size; i++) {
        arr[i] = x;
        cout<<arr[i]<<" ";
        x++;
    }
    cout<<endl;

    delete[] arr;

    return 0;
}