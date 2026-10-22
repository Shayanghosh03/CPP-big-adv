#include<iostream>
#include<iterator>
#include<list>
using namespace std;

int main() {
    list<int> ll;

    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_front(12);
    ll.push_front(45);

    ll.pop_back();
    ll.pop_front();

    list<int>::iterator itr;
    
    for(itr = ll.begin(); itr != ll.end(); itr++) {
        std::cout << (*itr) << " -> ";
    }
    cout << endl;

    cout << ll.size() << endl;

    cout << ll.front() << endl;
    cout << ll.back() << endl;

    return 0;
}