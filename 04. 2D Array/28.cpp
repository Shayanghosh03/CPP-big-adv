#include<iostream>
using namespace std;

void searchSortedMatrix(int arr[][4], int n, int m, int key) { // O(n+m)
    int i = 0, j = m-1;

    while(i < n && j >= 0) {
        if(arr[i][j] == key) {
            cout<<"Value found at => "<<"("<<i+1<<", "<<j+1<<")"<<" position"<<endl;
            break;
        } else if(arr[i][j] > key) {
            j--; // LEFT 
        } else {
            i++; // DOWN
        }
    }
    cout<<"Value not found"<<endl;
}

int main() {
    int arr[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    searchSortedMatrix(arr, 4, 4, 14);

    return 0;
}