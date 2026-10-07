#include<iostream>
#include<stack>
using namespace std;

void puhsAtBottom(stack<int> &stk, int value) {
    if(stk.empty()) {
        stk.push(value);
        return;
    }

    int temp = stk.top();
    stk.pop();
    puhsAtBottom(stk, value);

    stk.push(temp);
}

void printStack(stack<int> stk) {
    if(stk.empty()) {
        cout << "Stack is Empty..." << endl;
        return;
    }
    while(!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }

    cout << endl;
}

int main() {

    stack<int> stk;

    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);

    cout << "Size => " << stk.size() << endl;
    printStack(stk);

    puhsAtBottom(stk, 99);

    cout << "Size => " << stk.size() << endl;
    printStack(stk);

    return 0;
}