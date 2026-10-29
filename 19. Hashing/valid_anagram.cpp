#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

bool validAnagram(string s, string t) {
    if(s.length() != t.length()) {
        return false;
    }

    unordered_map<char, int> m;
    for(int i = 0; i < s.length(); i++) {
        if(m.count(s[i])) {
            m[s[i]]++;
        } else {
            m[s[i]] = 1;
        }
    }

    for(int i = 0; i < t.length(); i++) {
        if(m.count(t[i])) {
            m[t[i]]--;
            if(m[t[i]] == 0) {
                m.erase(t[i]);
            }
        } else {
            return false;
        }
    }

    return m.size() == 0;
}

int main() {
    string s = "race";
    string t = "care";

    cout << validAnagram(s, t) << endl;

    return 0;
}