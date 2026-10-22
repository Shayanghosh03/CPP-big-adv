#include<iostream>
#include<stack>
using namespace std;

string reverseString(string str) {
    string ans = "";
    stack<char> stk;

    for(char ch : str) {
        stk.push(ch);
    }

    while(!stk.empty()) {
        char top = stk.top();
        ans += top;
        stk.pop();
    }
    return ans;
}

int main() {
    string str = "shayan";
    cout << "String => " << str << endl;

    cout << "Reverse String => " << reverseString(str) << endl;

    return 0;
}