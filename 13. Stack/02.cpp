#include<iostream>
#include<list>
using namespace std;

template<class T>
class Stack {
    list<T> ll;
public:
    void push(T data) {
        ll.push_front(data);
    }
    void pop() {
        ll.pop_front();
    }
    T top() {
        return ll.front();
    }
    bool isEmpty() {
        return ll.size() == 0;
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