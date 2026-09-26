#include<iostream>
using namespace std;

void diagonalSum1(int arr[][4], int n, int m) { // O(n^2)
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == j) {
                sum += arr[i][j];
            } else if(j == n-i-1) {
                sum += arr[i][j];
            }
        }
    }
    cout<<"Diagonal Sum is => "<<sum<<endl;
}

void diagonalSum2(int arr[][4], int n) { // O(n)
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i][i];

        if(i != n-i-1) {
            sum += arr[i][n-i-1];
        }
    }
    cout<<"Diagonal Sum is => "<<sum<<endl;
}

int main() {
    int arr[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    diagonalSum1(arr, 4, 4);
    diagonalSum2(arr, 4);

    return 0;
}