#include<iostream>
using namespace std;

template<class T>
class Node {
public:
    T data;
    Node* next;
    
    Node(T data) {
        this -> data = data;
        this -> next = NULL;
    }
};

template<class T>
class Queue {
    Node<T>* head;
    Node<T>* tail;
public:
    Queue() {
        head = tail = NULL;
    }

    void enqueue(T data) {
        Node<T>* newNode = new Node<T>(data);
        if(head == NULL) {
            head = tail = newNode;
            return;
        }
        tail -> next = newNode;
        tail = newNode;
    }
    void dequeue() {
        if(empty()) {
            return;
        }
        Node<T>* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;

        if(head == NULL) {
            tail = NULL;
        }
    }
    T front() {
        if(empty()) {
            return -1;
        }
        return head -> data;
    }

    bool empty() {
        return head == NULL;
    }

};

int main() {
    Queue<int> q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);

    while(!q1.empty()) {
        cout << q1.front() << " ";
        q1.dequeue();
    }
    cout << endl;

    return 0;
}