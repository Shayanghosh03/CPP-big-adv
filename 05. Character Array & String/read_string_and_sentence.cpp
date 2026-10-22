#include<iostream>
#include<string>
using namespace std;

int main() {
    string str;
    cin>>str; // Without space like => Shayan
    cout<<str<<endl;

    string str1;
    getline(cin, str1); // With sapce like => Shayan Ghosh
    cout<<str1<<endl;

    return 0;
}