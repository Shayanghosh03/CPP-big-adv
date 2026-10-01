// Remove duplicate in a string
#include<iostream>
#include<vector>
using namespace std;

void removeDuplicate(string str, string ans, int i, vector<int> &map) {
    if(i == str.length()-1) {
        cout << ans << endl;
        return;
    }

    char ch = str[i];
    int mapIdx = (int)(ch - 'a');

    if(map[mapIdx] == true) {
        removeDuplicate(str, ans, i+1, map);
    } else {
        map[mapIdx] = true;
        removeDuplicate(str, ans+str[i], i+1, map);
    }
}

int main() {
    string str = "shayaanghhossh";
    string ans = "";
    vector<int> map(26, false);

    removeDuplicate(str, ans, 0, map);

    return 0;
}