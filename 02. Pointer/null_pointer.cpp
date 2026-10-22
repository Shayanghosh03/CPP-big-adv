#include<iostream>
using namespace std;

int main() {
    int a = 20;
    int *ptr = &a;
    int **pptr = &ptr;

    cout<<&a<<endl;
    cout<<ptr<<endl;
    cout<<pptr<<endl;

    cout<<sizeof(ptr)<<endl;

    cout<<*ptr<<endl;
    cout<<*pptr<<endl;
    cout<<**pptr<<endl;

    cout<<*(&a)<<endl;

    // NULL Pointer

    int *ptr2;
    cout<<ptr2<<endl; // Random address

    int *ptr1 = NULL;
    cout<<ptr1<<endl;
    cout<<*ptr1<<endl; // Segmentaiion fault


    return 0;
}