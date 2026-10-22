#include<iostream>
using namespace std;

void printSubstr(string str, string subStr) {
    if(str.length() == 0) {
        cout << subStr << endl;
        return;
    }
    char ch = str[0];
    // Yes
    printSubstr(str.substr(1, str.length()-1), subStr+ch);
    // No
    printSubstr(str.substr(1, str.length()-1), subStr);
}

int main() {
    string str = "abc";
    string subSrt = "";

    printSubstr(str, subSrt);

    return 0;
}