// 2D Dynamic array
#include<iostream>
using namespace std;

int main() {
    int row, col;
    cout << "Enter the row size: ";
    cin >> row;

    cout << "Enter the column size: ";
    cin >> col;

    int **matrix = new int*[row];

    for(int i = 0; i < row; i++) {
        matrix[i] = new int[col];   
    }

    int x = 1;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            matrix[i][j] = x;
            cout << matrix[i][j] << " ";
            x++;
        }
        cout << endl;
    }

    return 0;
}