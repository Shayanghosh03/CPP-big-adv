#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Node {
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val) {
        this -> key = key;
        this -> val = val;
        next = NULL;
    }
 
    ~Node() {
        if(next != NULL) {
            delete next;
        }
    }
};

class HashTable {
    int totalSize;
    int currSize = 0; // Rehashing
    Node** table;

    int hashFuction(string key) {
        int idx = 0;
        for(int i = 0; i < key.size(); i++) {
            idx = (idx + (key[i] * key[i]) % totalSize) % totalSize;
        }

        return idx;
    }

    void rehash() { // O(n)
        Node** oldTable = table;
        int oldSize = totalSize;

        totalSize = 2 * totalSize;
        table = new Node*[totalSize];

        for(int i = 0; i < totalSize; i++) {
            table[i] = NULL;
        }

        for(int i = 0; i < oldSize; i++) {
            Node* temp = oldTable[i];
            while(temp != NULL) {
                insert(temp -> key, temp -> val);
                temp = temp -> next;
            }

            if(oldTable[i] != NULL) {
                delete oldTable[i];
            }
        }
    }

public:
    HashTable(int size) {
        totalSize = size;
        table = new Node*[totalSize];

        for(int i = 0; i < totalSize; i++) {
            table[i] = NULL;
        }
    }

    void insert(string key, int val) { // O(1) - Avg
        int idx = hashFuction(key);
        Node* newNode = new Node(key, val);

        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;

        double lambda = currSize / double(totalSize);
        if(lambda > 1) {
            rehash(); // O(n) - Wost
        }
    }
    
    bool exists(string key) {
        int idx = hashFuction(key);

        Node* temp = table[idx];
        while(temp != NULL) {
            if(temp -> key == key) {
                return true;
            }
            temp = temp -> next;
        }
        return false;
    }

    int search(string key) {
        int idx = hashFuction(key);
        Node* temp = table[idx];

        while(temp != NULL) {
            if(temp -> key == key) {
                return temp -> val;
            }
            temp = temp -> next;
        }
        return -1;
    }

    void remove(string key) {
        int idx = hashFuction(key);
        Node* temp = table[idx];
        Node* prev = temp;

        while(temp != NULL) {
            if(temp -> key == key) {
                if(prev == temp) {
                    table[idx] = temp -> next;
                } else {
                    prev -> next = temp -> next;
                }
            }
            prev = temp;
            temp = temp -> next;
        }
    }

    void print() {
        for(int i = 0; i < totalSize; i++) {
            cout << "idx " << i << " ->";
            Node* temp = table[i];
            while(temp != NULL) {
                cout << temp -> key << ", " << temp -> val << " -> ";
                temp = temp -> next;
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(5);

    ht.insert("India", 250);
    ht.insert("Chaina", 500);
    ht.insert("USA", 489);
    ht.insert("Nepal", 120);
    ht.insert("UK", 325);

    if(ht.exists("India")) {
        cout << "India population is => " << ht.search("India") << endl;
    }

    cout << "Hash Table is =>" << endl;
    ht.print();

    cout << endl;
    ht.remove("Chaina");

    cout << "After removing Chaina => " << endl;
    ht.print();

    return 0;
}