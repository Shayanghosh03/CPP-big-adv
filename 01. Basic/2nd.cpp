#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    bool prime = true;

    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) {
            prime = false;
            break;
        }
    }

    if(prime == true) {
        cout<<num<<" is prime number"<<endl;
    } else {
        cout<<num<<" is not a prime number"<<endl;
    }

    return 0;
}