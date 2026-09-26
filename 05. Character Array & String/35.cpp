#include<iostream>
#include<cstring>
using namespace std;

int main() {
    char str[50];
    cin.getline(str, 50);
    
    cout<<"Scentence is => "<<str<<endl;
    cout<<"Length is => "<<strlen(str)<<endl;
    
    return 0;
}