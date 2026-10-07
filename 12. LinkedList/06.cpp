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

class List {
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
            return;
        }
        Node* temp = head;
        while(temp != NULL) {
            cout << temp -> data << " -> ";
            temp = temp -> next;
        }
        cout << endl;
    }
};

Node* splitAtMid(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast != NULL && fast -> next != NULL) {
        prev = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    if(prev != NULL) {
        prev -> next = NULL;
    }
    return slow;
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL) {
        next = curr -> next;
        curr -> next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}

Node* merge(Node* left, Node* right) {
    Node* head = left;
    Node* tail = right;
    while(left != NULL && right != NULL) {
        Node* nextLeft = left -> next;
        Node* nextRight = right -> next;

        left -> next = right;
        right -> next = nextLeft;
        tail = right;

        left = nextLeft;
        right = nextRight;
    }

    if(right != NULL) {
        tail -> next = right;
    }

    return head;
}

Node* zigZagLL(Node* head) {
    Node* rightHead = splitAtMid(head);
    Node* rightHeadRev = reverse(rightHead);

    Node* mergeHead = merge(head, rightHeadRev);

    return mergeHead;
}

int main() {
    List l1;
    
    l1.push_front(10);
    l1.push_back(50);
    l1.push_back(45);
    l1.push_front(23);

    l1.print_list();

    cout << "Zig Zag Linked List =>" << endl;
    l1.head = zigZagLL(l1.head);
    l1.print_list();

  
    return 0;
}