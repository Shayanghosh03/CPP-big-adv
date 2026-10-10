#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isValid(string str) {
    stack<char> s;
    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if(ch == '(' || ch == '{' || ch == '[') { // Opening
            s.push(ch); 
        } else { // Closing
            if(s.empty()) {
                return false;
            }

            char top = s.top();
            if(ch == ')' && top == '('
                || ch == '}' && top == '{'
                || ch == ']' && top == '[') {
                s.pop();
            } else {
                return false;
            }
        }
    }
    if(s.empty()) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string str = "({[]})";
    string str1 = "({[";
    string str2 = "({[})]";

    cout << isValid(str) << endl;
    cout << isValid(str1) << endl;
    cout << isValid(str2) << endl;

    return 0;
}