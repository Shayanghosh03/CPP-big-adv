#include<iostream>
using namespace std;

// Both are same
void func(int arr[][4], int n, int m) {
    cout<<"0th row ptr => "<<arr<<endl;
    cout<<"1th row ptr => "<<arr+1<<endl;
    cout<<"2nd row ptr => "<<arr+2<<endl;

    cout<<endl;

    cout<<"0th row value => "<<*arr<<endl;
    cout<<"1th row value => "<<*(arr+1)<<endl;
    cout<<"2nd row value => "<<*(arr+2)<<endl;

    cout<<endl;

    cout<<"arr[2][3] = "<<"*(*(arr+2)+3) => "<<*(*(arr+2)+3)<<endl;
}

void sunc(int (*arr)[4], int n, int m) {

}

int main() {
    int arr[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    func(arr, 4, 4);

    return 0;
}