#include<iostream>
#include<vector>
using namespace std;

int FirstOcc(vector<int> arr, int target, int i) {
    if(i == arr.size()-1) {
        return -1;
    }

    if(arr[i] == target) {
        return i;
    }

    return FirstOcc(arr, target, i+1);
}

int LastOcc(vector<int> arr, int target, int i) {
    if(i == arr.size()-1) {
        return -1;
    }

    int idxFound = LastOcc(arr, target, i+1);

    if(idxFound == -1 && arr[i] == target) {
        return i;
    }

    return idxFound;
}

int main() {
    vector<int> arr = {1, 2, 3, 3, 3, 4, 5};
    cout << FirstOcc(arr, 3, 0) << endl;

    cout << LastOcc(arr, 3, 0) << endl;

    return 0;
}