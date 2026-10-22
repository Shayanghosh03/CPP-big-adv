#include<iostream>
#include <cstring>
using namespace std;

int main() {
    char work[] = "Code";
    cout<<work<<endl;

    char work2[5] = "Code";
    cout<<work2<<endl;

    char arr[50] = {'s', 'h', 'a', 'y', 'a', 'n'};
    cout<<arr<<endl;

    char arr2[50] = {'h', 'e', 'l', 'l', 'o', '\0'};
    cout<<strlen(arr2)<<endl;

    return 0;
}