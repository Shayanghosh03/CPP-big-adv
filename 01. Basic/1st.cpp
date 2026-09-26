#include<iostream>
using namespace std;

void pattern1() {
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= 4; j++) {
            cout<<j;
        }
        cout<<endl;
    }
}

void pattern2() {
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= 4; j++) {
            cout<<i;
        }
        cout<<endl;
    }
}

void pattern3() {
    for(int i = 0; i < 4; i++) {
        for(int j = i; j < 4; j++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
} 

void pattern4() {
    for(int i = 4; i >=1; i--) {
        for(int j = i; j <= 4; j++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

void pattern5() {
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= i; j++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

void pattern6() {
    int n = 4;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= (n - i + 1); j++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

void pattern7() {
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= i; j++) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void pattern8() {
    char ch = 'A';
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= i; j++) {
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }
}

void pattern9() {
    int n = 4; 
    for(int i = 1; i <= n; i++) {
        cout<<"*"<<" ";

        for(int j = 1; j <= n-1; j++) {
            if(i == 1 || i == n) {
                cout<<"*"<<" ";
            }else {
                cout<<" "<<" ";
            }
        }

        cout<<"*"<<" "<<endl;
    }
}

void pattern10() {
    int n = 4;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i; j++) {
            cout<<" "<<" ";
        }
        for(int k = 1; k <= i; k++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

void pattern11() {
    int n = 5;
    int num = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout<<num<<" ";
            num++;
        }
        cout<<endl;
    }
}

void pattern12() {
    int n = 5;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i; j++) {
            cout<<" "<<" ";
        }
        for(int j = 1; j <= (2*i-1); j++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    for(int i = n-1; i >=1; i--) {
        for(int j = n-i; j >= 1; j--) {
            cout<<" "<<" ";
        }
        for(int j = (2*i-1); j >= 1; j--) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

void pattern13() {
    int n = 5;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout<<"*"<<" ";
        }
        for(int j = 1; j <= 2*(n-i); j++) {
            cout<<" "<<" ";
        }
        for(int j = 1; j <= i; j++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    for(int i = n-1; i >= 1; i--) {
        for(int j = i; j >= 1; j--) {
            cout<<"*"<<" ";
        }
        for(int j = 2*(n-i); j >= 1; j--) {
            cout<<" "<<" ";
        }
        for(int j = i; j >= 1; j--) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}
void pattern14() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        for (int j = 1; j < 2 * (n - i); j++) {
            cout << "  ";
        }
        if(i == n) {
            for(int j = 1; j < i; j++) {
                cout<<"*"<<" ";
            }
        } else {
            for(int j = 1; j <= i; j++) {
                cout<<"*"<<" ";
            }
        }
        cout << endl;
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        for (int j = 1; j < 2 * (n - i); j++) {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

int main() {
    pattern1();
    cout<<endl;
    pattern2();
    cout<<endl;
    pattern3();
    cout<<endl;
    pattern4();
    cout<<endl;
    pattern5();
    cout<<endl;
    pattern6();
    cout<<endl;
    pattern7();
    cout<<endl;
    pattern8();
    cout<<endl;
    pattern9();
    cout<<endl;
    pattern10();
    cout<<endl;
    pattern11();
    cout<<endl;
    pattern12();
    cout<<endl;
    pattern13();
    cout<<endl;
    pattern14();
    cout<<endl;


    return 0;
}