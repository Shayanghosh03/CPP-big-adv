#include<iostream>
using namespace std;

void binaryString(int n, int lastPlace, string ans) {
    if(n == 0) {
        cout << ans << endl;
        return;
    }

    if(lastPlace != 1) {
        binaryString(n-1, 0, ans + '0');
        binaryString(n-1, 1, ans + '1');
    } else {
        binaryString(n-1, 0, ans + '0');
    }
}

void binaryString2(int n, string ans) {
    if(n == 0) {
        cout << ans << endl;
        return;
    }

    if(ans[ans.length() - 1] != '1') {
        binaryString2(n-1, ans + '0');
        binaryString2(n-1, ans + '1');
    } else {
        binaryString2(n-1, ans + '0');
    }
}

int main() {
    string ans = "";
    binaryString(3, 0, ans);

    cout << "2nd Logic" << endl;
    binaryString2(3, ans);

    return 0;
}