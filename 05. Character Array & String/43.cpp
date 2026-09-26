#include<iostream>
#include<string>
using namespace std;

int main() {
    string str = "Shayan";

    cout<<"Length is => "<<str.length()<<endl;
    cout<<"4th charactor is => "<<str[3]<<endl;
    cout<<"4th charactor is => "<<str.at(3)<<endl;

    cout<<"Substring is => "<<str.substr(1, 4)<<endl;

    string str1 = "I love c++ programming language";

    cout<<str1.find("c++")<<endl;

    return 0;
}