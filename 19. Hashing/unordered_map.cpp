#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> m;
    m["India"] = 252;
    m["Chaina"] = 150;
    m["USA"] = 456;
    m["Nepal"] = 344;

    cout << "India Population => " << m["India"] << endl; // Value

    for(pair<string, int> country : m) {
        cout << "("<< country.first << ", " << country.second << ")" << endl;
    }

    if(m.count("Nepal")) { // if 1 nepan exists and 0 not exists
        cout << "Nepal Exixsts" << endl;
    } else {
        cout << "Nepal Not exists" << endl;
    }
    if(m.count("Canada")) {
        cout << "CanaDa Exixsts" << endl;
    } else {
        cout << "Canada not exixts" << endl;
    }

    // Erase
    m.erase("Nepal");
    m["USA"] = 700;

    cout << "After remove nepal & update USA" << endl;
    for(pair<string, int> country : m) {
        cout << "("<< country.first << ", " << country.second << ")" << endl;
    }

    return 0;
}

// unordered_map time compexity searching, insert, erase O(1) and use internally Hash Table data Structure
// Map is same just time complexity is O(logn) and sorted key value pair and use internally Read Black tree Data Structure