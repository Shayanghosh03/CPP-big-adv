#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this -> data = data;
        next = prev = NULL;
    }
    ~Node() {

    }
};

class DoublyList {
public:
    Node* head;
    Node* tail;

    DoublyList() {
        head = tail = NULL;
    }

    ~DoublyList() {

    }

    void push_front(int data) {
        Node* newNode = new Node(data);

        if(head == NULL) {
            head = tail = newNode;
            return;
        }
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode; 
    }

    void push_back(int data) {
        Node* newNode = new Node(data);

        if(tail == NULL) {
            head = tail = newNode;
            return;
        }
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }

    void pop_front() {
        if(head == NULL) {
            cout << "List is empty..." << endl;
            return;
        }
        Node* temp = head;
        if(head == tail) {
            head = tail = NULL;
        } else {
            head = head -> next;
            head -> prev = NULL;
            temp -> next = NULL;
        }
        delete temp;
    }

    void pop_back() {
        if(head == NULL) {
            cout << "List is empty..." << endl;
            return; 
        }
        Node* temp = tail;
        if(head == tail) {
            head = tail = NULL;
        } else {
            tail = tail -> prev;
            tail -> next = NULL;
            temp -> prev = NULL;
        }
        delete temp;
    }

    void printList() {
        if(head == NULL && tail == NULL) {
            cout << "List is empty..." << endl;
            return;
        }
        Node* temp = head;
        while(temp != NULL) {
            cout << temp -> data << " -> ";
            temp = temp -> next;
        }
        cout << endl;
    }
    
    void reverse_print() {
        if(head == NULL && tail == NULL) {
            cout << "List is empty..." << endl;
            return;
        }
        Node* temp  = tail;
        while(temp != NULL) {
            cout << temp -> data << " -> ";
            temp = temp -> prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyList l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    l1.push_front(99);
    l1.push_front(89);

    l1.printList();
    l1.reverse_print();

    l1.pop_front();
    l1.printList();

    l1.pop_back();
    l1.printList();

    return 0;
}