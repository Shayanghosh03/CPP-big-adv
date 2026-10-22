#include<iostream>
#include<cstring>
using namespace std;

int main() {
    char ch[50];
    cin>>ch; // Ignore the letters after whitespace

    cout<<"Word is => "<<ch<<endl;
    cout<<"Lenght is => "<<strlen(ch)<<endl;

    return 0;
}