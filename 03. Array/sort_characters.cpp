#include<iostream>
using namespace std;

void sortChar(char *arr, int n) { // O(n^2)
    for(int i = 1; i < n; i++) {
        int curr = arr[i];
        int prev = i-1;

        while(prev >= 0 && arr[prev] < curr) {
            swap(arr[prev], arr[prev+1]);
            prev--;
        }
        arr[prev+1] = curr;
    }
}

int main() {
    char ch[] = {'a','c','b','u','w','n','m'};
    int n = sizeof(ch) / sizeof(ch[0]);

    sortChar(ch, n);

    for(int i = 0; i < n; i++) {
        cout<<ch[i]<<" ";
    }
    cout<<endl;

    return 0;
}