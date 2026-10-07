#include<iostream>
using namespace std;

template<class T>
class Node {
public:
    T data;
    Node<T>* next;
    
    Node(T data) {
        this -> data = data;
        next = NULL;
    }
};

template<class T>
class Stack {
public:
    Node<T>* head;

    Stack() {
        head = NULL;
    }

    void push(T data) {
        Node<T>* newNode = new Node<T>(data);
        if(head == NULL) {
            head = newNode;
            return;
        }
        newNode -> next = head;
        head = newNode;
    }
    void pop() {
        if(head == NULL) {
            cout << "Stack is empty..." << endl;
            return;
        }
        Node<T>* temp = head;
        head = head -> next;
        temp -> next = NULL;
        cout << temp -> data << " is pop" << endl;
        
        delete temp;

    }
    void top() {
        if(head == NULL) {
            cout << "Stack is empty..." << endl;
            return;
        }
        cout << "Top => " << head -> data << endl; 
    }

};

int main() {
    Stack<int> s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.pop();

    s1.top();

    return 0;
} 