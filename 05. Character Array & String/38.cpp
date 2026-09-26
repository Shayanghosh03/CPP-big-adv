#include<iostream>
#include<cstring>
using namespace std;

bool palindromeCheck(char str[], int n) {
    int i = 0, j = n-1;
    while(i < j) {
        if(str[i++] != str[j--]) {
            cout<<"It's not a valid palindrome"<<endl;
            return false;
        }
    }
    cout<<"Valid palindrome"<<endl;
}

int main() {
    char str[] = "racecar";

    palindromeCheck(str, strlen(str));

    return 0;
}