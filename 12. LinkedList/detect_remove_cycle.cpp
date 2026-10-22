#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        next = NULL;
    }
};

class List{
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int data) {
        Node* newNode = new Node(data);
        if(head == NULL) {
            head = tail = newNode;
            return;
        }
        newNode -> next = head;
        head = newNode;
    }

    void push_back(int data) {
        Node* newNode = new Node(data);
        if(tail == NULL) {
            tail = head = newNode;
            return;
        }
        tail -> next = newNode;
        tail = newNode;
    }

    void print_list() {
        if(head == NULL && tail == NULL) {
            cout << "List is empty..." << endl;
        }

        Node* temp = head;
        while(temp != NULL) {
            cout << temp -> data << " -> ";
            temp = temp -> next;
        }
        cout << endl;
    }

};

bool isCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast) {
            cout << "Cycle exists.." << endl;
            return true;
        }
    }

    cout << "Cycle not exists.." << endl;
    return false;
}

void removeCycle(Node* head) {
    // Detect Cycle
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast) {
            cout << "Cycle Exists..." << endl;
            isCycle = true;
            break;
        }
    }
    
    if(!isCycle) {
        cout << "Cycle not exists.." << endl;
        return;
    }

    // Remove Cycle
    slow = head;
    if(slow == fast) { // Special case tail -> head
        while(fast -> next != slow) {
            fast = fast -> next;
        }
        fast -> next = NULL;
    } else { // Normal Case
        Node* prev = fast;
        while(slow != fast) {
            slow = slow -> next;
            prev = fast;
            fast = fast -> next;
        }
        prev -> next = NULL;
    }

}

int main() {
    List l1;

    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_front(90);
    l1.push_front(55);

    l1.print_list();

    cout << "After cycle present check ->" << endl;
    l1.tail -> next = l1.head -> next;
    isCycle(l1.head);

    cout << "Remove the cycle..." << endl;
    removeCycle(l1.head);
    cout << "After remmoving cycle check ->" << endl;
    isCycle(l1.head);
    l1.print_list();

    return 0;
}