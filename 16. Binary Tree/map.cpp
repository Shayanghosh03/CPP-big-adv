#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
    map<int, string> m;

    m[100] = "Shayan";
    m[101] = "Sumanta";
    m[102] = "Sonali";
    m[104] = "Arnab";
    
    cout << m[102] << endl;

    m[102] = "Debalina";

    cout << m[102] << endl; // Value overwride

    cout << m.count(101) << endl;  // if key present then print 1 other wise 0;
    cout << m.count(105) << endl;

    for(auto it : m) {
        cout << it.first << ", " << it.second << endl;
    }

    for(auto it : m) {
        cout << it.first*2 << ", " << it.second << endl;
    }

    return 0;
}