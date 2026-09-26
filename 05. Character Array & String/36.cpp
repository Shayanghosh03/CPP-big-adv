#include<iostream>
#include<cstring>
using namespace std;

void toUpper(char ch[], int n) {
    for(int i = 0; i < n; i++) {
        char word = ch[i];
        if(word >= 'A' && word <= 'Z') {
            continue;
        } else {
            ch[i] = word - 'a' + 'A';
        }
    }
}

int main() {
    char ch[] = "ApPle";

    toUpper(ch, strlen(ch));

    cout<<"Upper case value is => "<<ch<<endl;
    
    return 0;
}