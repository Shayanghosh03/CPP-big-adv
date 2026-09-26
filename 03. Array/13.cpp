#include<iostream>
using namespace std;

int main() {
    int arr[25] = {1,2,3,4,5};

    int *ptr1 = arr;
    int *ptr2 = arr + 3;

    cout<<*ptr1<<endl;
    cout<<*ptr2<<endl;

    cout<<ptr2 - ptr1<<endl;

    cout<<(ptr2 > ptr1)<<endl;

    cout<<(ptr1 == arr)<<endl;

    return 0;
}