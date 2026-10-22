#include<iostream>
#include<stack>
using namespace std;

void printStack(stack<int> stk) {
    if(stk.empty()) {
        cout << "Stack is empty..." << endl;
        return;
    }
    while(!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

void pushAtBottom(stack<int> &stk, int value) {
    if(stk.empty()) {
        stk.push(value);
        return;
    }

    int temp = stk.top();
    stk.pop();
    pushAtBottom(stk, value);

    stk.push(temp);
}

void reverseStack(stack<int> &stk) {
    if(stk.empty()) {
        return;
    }

    int temp = stk.top();
    stk.pop();
    reverseStack(stk);

    pushAtBottom(stk, temp);
}

int main() {
    stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    printStack(stk);

    cout << "Reverse stack " << endl;
    reverseStack(stk);
    printStack(stk);

    return 0;
}