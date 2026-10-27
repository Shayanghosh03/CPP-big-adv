#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Heap {
    vector<int> vec; // CBT MAX HEAP
public:

    void push(int val) {
        vec.push_back(val);

        int childIdx = vec.size() - 1;
        int parentIdx = (childIdx - 1) / 2;

        while(parentIdx >= 0 && vec[childIdx] > vec[parentIdx]) {
            swap(vec[childIdx], vec[parentIdx]);

            childIdx = parentIdx;
            parentIdx = (childIdx - 1) / 2;
        }
    }

    void heapify(int parIdx) {
        if(parIdx >= vec.size()) {
            return;
        }

        int lIdx = 2 * parIdx + 1;
        int rIdx = 2 * parIdx + 2;

        int maxIdx = parIdx;

        if(lIdx < vec.size() && vec[parIdx] < vec[lIdx]) {
            maxIdx = lIdx;
        }
        if(rIdx < vec.size() && vec[parIdx] < vec[rIdx]) {
            maxIdx = rIdx;
        }

        swap(vec[maxIdx], vec[parIdx]);

        if(maxIdx != parIdx) {
            heapify(maxIdx);
        }
    }

    void pop() {
        swap(vec[0], vec[vec.size() - 1]);
        vec.pop_back();

        //fixed
        heapify(0);
    }

    int top() {
        return vec[0];
    }

    bool empty() {
        return vec.size() == 0;
    }
};

int main() {
    Heap hp;
    hp.push(20);
    hp.push(40);
    hp.push(10);
    hp.push(80);
    hp.push(60);

    cout << "Top => " << hp.top() << endl;

    while(!hp.empty()) {
        cout << hp.top() << " ";
        hp.pop();
    }
    cout << endl;

    return 0;
}