#include<iostream>
using namespace std;

void spiralMatrix(int arr[][4], int n, int m) {
    int sRow = 0, sCol = 0;
    int eRow = n-1, eCol = m-1;
    
    while(sRow <= eRow && sCol <= eCol) {
        //top
        for(int j = sCol;  j <= eCol; j++) {
            cout<<arr[sRow][j]<<" ";
        }
        //right
        for(int i = sRow+1; i <= eRow; i++) {
            cout<<arr[i][eCol]<<" ";
        }
        //bottom
        for(int j = eCol-1; j >= sCol; j--) {
            if(sRow == eRow) {
                break;
            }
            cout<<arr[eRow][j]<<" ";
        }
        //left
        for(int i = eRow-1; i >= sRow+1; i--) {
            if(sCol == eCol) {
                break;
            }
            cout<<arr[i][sCol]<<" ";
        }

        sRow++; sCol++;
        eRow--; eCol--;
    }
    cout<<endl;
}

int main() {
    int arr[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int n = 4, m = 4;

    spiralMatrix(arr, n, m);

    return 0;
}