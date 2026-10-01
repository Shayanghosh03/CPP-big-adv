#include<iostream>
using namespace std;

int rotatedSortedArray(int arr[], int start, int end, int target) {
    if(start > end) {
        return -1;
    }

    int mid = start + (end - start) / 2;
    if(target == arr[mid]) {
        return mid;
    }

    if(arr[start] <= arr[mid]) {  // L1
        if(arr[start] <= target && target <= arr[mid]) {
            return rotatedSortedArray(arr, start, mid-1, target);
        } else {
            return rotatedSortedArray(arr, mid+1, end, target);
        }
    } else { // L2
        if(arr[mid] <= target && target <= arr[end]) {
            return rotatedSortedArray(arr, mid+1, end, target);
        } else {
            return rotatedSortedArray(arr, start, mid-1, target);
        }
    }

}

int main() {
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 0;

    int result = rotatedSortedArray(arr, 0, n-1, target);

    cout << target << " value is present at " << (result+1) << " position" << endl;

    return 0;
}