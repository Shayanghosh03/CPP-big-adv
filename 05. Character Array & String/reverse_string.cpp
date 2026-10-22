#include<iostream>
#include<cstring>
using namespace std;

void reverseString(char str[], int n) {
    int i = 0, j = n-1;
    while( i < j) {
        swap(str[i++], str[j--]);
    }
}

int main() {
    char str[] = "shayan";

    reverseString(str, strlen(str));
    cout<<"Rverse String is => "<<str<<endl;

    return 0;
}