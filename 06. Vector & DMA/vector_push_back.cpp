#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> vec;

    for(int i = 0; i < 5; i++) {
        vec.push_back(i);
    }

    cout << "Size is => " << vec.size() << endl;
    cout << "Capacity is => " << vec.capacity() << endl;

    return 0;
}