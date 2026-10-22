#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Stack {
    vector<T> vec;
public:
    void push(T data) {
        vec.push_back(data);
    }
    void pop() {
        if(isEmpty()) {
            cout << "Stack is empty..." << endl;
            return;
        }
        vec.pop_back();
    }

    T top() {
        // if(isEmpty()) {
        //     cout << "Stack is empty..." << endl;
        //     return -1;
        // }
        int lastIdx = vec.size() - 1;
        return vec[lastIdx];
    }

    bool isEmpty() {
        return vec.size() == 0;
    }
};

int main() {
    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);

    s1.pop();

    cout << s1.top() << endl;

    Stack<char> s2;

    s2.push('A');
    s2.push('B');
    s2.push('C');

    cout << s2.top() << endl;

    return 0;
}