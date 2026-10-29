// Set is a collection of unique elements
#include<iostream>
#include<unordered_set> // Use hash table DS
using namespace std;

int main() {
    unordered_set<int> s;
    
    s.insert(5);
    s.insert(56);
    s.insert(2);
    s.insert(10);
    s.insert(66);
    s.insert(10);
    s.insert(10);
    
    cout << "Set Size -> " << s.size() << endl;

    if(s.find(2) != s.end()) { // Exists
        cout << "3 exists" << endl;        
    } else {
        cout << "3 Not exixsts" << endl;
    }

    s.erase(2); 

    for(auto el : s) {
        cout << el << " ";
    }
    cout << endl;

    return 0;
}