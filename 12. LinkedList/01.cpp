#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        this -> data = value;
        next = NULL;
    }

    ~Node() {
        if(next != NULL) {
            delete next;
            next = NULL;
        }
    }
};

class List {
    Node* Head;
    Node* Tail;
public:
    List() {
        Head = NULL;
        Tail = NULL;
    }

    ~List() {
        if(Head != NULL) {
            delete Head;
            Head = NULL;
        }
    }

    void push_front(int data) {
        Node* newNode = new Node(data);
        if(Head == NULL) {
            Head = Tail = newNode;
        } else {
            newNode -> next = Head;
            Head = newNode;
        }
    }

    void push_back(int data) {
        Node* newNode = new Node(data);
        if(Tail == NULL) {
            Head = Tail = NULL;
        } else {
            Tail -> next = newNode;
            Tail = newNode;
        }
    }

    void print_list() {
        if(Head == NULL) {
            cout << "List is empty.." << endl;
        }

        Node* temp;
        temp = Head;
        while(temp != NULL) {
            cout << temp -> data << " -> ";
            temp = temp -> next;
        }
        cout << endl;
    }

    void insert(int data, int pos) {
        Node* newNode = new Node(data);
        Node* temp = Head;
        for(int i = 1; i < pos-1; i++) {
            if(temp == NULL) {
                cout << "postion not valid" << endl;
                return;
            }
            temp = temp -> next;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }

    void pop_front() {
        if(Head == NULL) {
            cout << "List is empty.." << endl;
        }

        Node* temp = Head;
        Head = Head -> next;
        temp -> next = NULL;

        delete temp;
    }

    void pop_back() {
        if(Head == NULL) {
            cout << "List is empty.." << endl;
        }

        Node* temp = Head;
        while(temp -> next -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = NULL;
        delete Tail;
        Tail = temp;

    }

    int searchItr(int key) {
        Node* temp = Head;
        int pos = 1;
        while(temp != NULL) {
            if(temp -> data == key) {
                return pos;
            }
            temp = temp -> next;
            pos++;
        }
    }

    int helper(Node* temp, int key) {
        if(temp == NULL) {
            return -1;
        }

        if(temp -> data == key) {
            return 1;
        }

        int idx = helper(temp -> next, key);
        if(idx == -1) {
            return -1;
        }
        return idx+1;
    }

    int searchRec(int key) {
        return helper(Head, key);
    }

    void reverse_list() {
        Node* curr = Head;
        Node* prev = NULL;
        Node* next = NULL;

        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;

            prev = curr;
            curr = next;
        }
        Head = prev;
    }

    int listSize() {
        int size = 0;
        Node* temp = Head;

        while(temp != NULL) {
            temp = temp -> next;
            size++;
        }
        return size;
    }

    void removeNth(int n) { // last Nth position...
        int size = listSize();
        Node* prev = Head;
        for(int i = 1; i < (size-n); i++) {
            prev = prev -> next;
        }
        Node* toDel = prev -> next;
        prev -> next = prev -> next -> next;
        toDel -> next = NULL;

        delete toDel;
    }
};

int main() {
    List l1;

    l1.push_front(10);
    l1.push_front(20);
    l1.push_front(30);

    l1.push_back(50);
    l1.push_back(70);

    l1.print_list();

    l1.insert(99, 3);
    cout << "After insert 3rd position 99 value =>" << endl;
    l1.print_list();

    l1.pop_front();
    cout << "After pop the front value =>" << endl;
    l1.print_list();

    l1.pop_back();
    cout << "After pop the back value =>" << endl;
    l1.print_list();

    int ans = l1.searchItr(99);
    cout << "99 present in " << ans << " position" << endl;

    int ans2 = l1.searchRec(10);
    cout << "10 present in " << ans2 << " position" << endl;

    l1.reverse_list();
    cout << "Reverse the list =>" << endl;
    l1.print_list();

    l1.removeNth(3);
    cout << "After delete at 3 position form end =>" << endl;
    l1.print_list();
 

    return 0;
}