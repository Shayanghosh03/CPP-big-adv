#include<iostream>
using namespace std;

int partition(int arr[], int start, int end) {
    int i = start - 1;
    int pivot = arr[end];

    for(int j = start; j < end; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[end]);

    return i;
}

void quickSort(int arr[], int start, int end) {
    if(start >= end) {
        return;
    }

    int pivotIdx = partition(arr, start, end);

    quickSort(arr, start, pivotIdx - 1);
    quickSort(arr, pivotIdx + 1, end);
}

int main() {
    int arr[] = {2, 5, 7, 3, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n-1);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}