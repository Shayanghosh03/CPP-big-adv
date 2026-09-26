#include<iostream>
using namespace std;

int main() {
    char ch[] = {'a', 'b', 'c', 'd', 'e', '\0'};

    for(char word : ch) {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}