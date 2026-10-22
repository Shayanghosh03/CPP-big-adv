#include<iostream>
using namespace std;

void permuations(string str, string ans) {
    int n = str.length();

    if(n == 0) {
        cout << ans << endl;
        return;
    }

    for(int i = 0; i < n; i++) {
        char ch = str[i];
        string nextStr = str.substr(0, i) + str.substr(i+1, n-i-1);
        permuations(nextStr, ans+ch);
    }
}

int main() {
    string str = "abc";
    string ans = "";

    permuations(str, ans);

    return 0;
}