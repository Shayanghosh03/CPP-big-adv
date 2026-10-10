#include<iostream>
#include<stack>
using namespace std;

bool isDuplicate(string str) {
    stack<char> s;
    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if(ch != ')') { // Non-Closing
            s.push(ch);
        } else { // Closing
            if(s.top() == '(') {
                return true; // Duplicate
            } else {
                while(s.top() != '(') {
                    s.pop();
                }
                s.pop();
            }
        }
    }
    return false;
}

int main() {
    string str = "((a+b)+(b+c))";

    isDuplicate(str) ? cout << "Duplicate brakects present" << endl : cout << "Duplicate brackets are not present" << endl;

    return 0;
} 