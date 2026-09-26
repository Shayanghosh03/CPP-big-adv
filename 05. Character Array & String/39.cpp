#include<iostream>
#include<cstring>
using namespace std;

int main() {
    char str1[100];

    strcpy(str1, "Shayan Ghosh");  // Copy src to des
    cout<<str1<<endl;

    char str2[10] = "Shayan";
    char str3[10] = "Sonali";

    strcpy(str2, str3); 

    cout<<str2<<endl;
    cout<<str3<<endl;

    strcat(str2, str3); // Concatination

    cout<<str2<<endl;

    char str4[10] = "abc";
    char str5[10] = "abc";
    char str6[10] = "xyz";

    cout<<strcmp(str4, str5)<<endl; // compares two string on values (-ve, 0, +ve)
    cout<<strcmp(str4, str6)<<endl;
    cout<<strcmp(str6, str4)<<endl;

    return 0;
}