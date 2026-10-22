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

Node* merge(Node* left, Node* right) {
    List ans;
    Node* i = left;
    Node* j = right;

    while(i != NULL && j != NULL) {
        if(i -> data >= j -> data) {
            ans.push_back(j -> data);
            j = j -> next;
        } else {
            ans.push_back(i -> data);
            i = i -> next;
        }
    }

    while(i != NULL) {
        ans.push_back(i -> data);
        i = i -> next;
    }
    while(j != NULL) {
        ans.push_back(j -> data);
        j = j -> next;
    }
    return ans.head;
}

Node* mergeSort(Node* head) {
    if(head == NULL || head -> next == NULL) { // Base case
        return head;
    }

    Node* rightHead = splitAtMid(head);

    Node* left = mergeSort(head); // left head
    Node* right = mergeSort(rightHead); // Rgiht head

    return merge(left, right);
}


int main() {
    List l1;
    
    l1.push_front(10);
    l1.push_back(50);
    l1.push_back(45);
    l1.push_front(23);

    l1.print_list();

    cout << "After Merge Sort =>" << endl;
    l1.head = mergeSort(l1.head);
    l1.print_list();
  
    return 0;
}