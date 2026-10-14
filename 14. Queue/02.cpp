
#include<iostream>
using namespace std;

class Queue {
    int *arr;
    int capacity;
    int currSize;
    int f, r;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        currSize = 0;
        f = r = -1;
    }

    void enqueue(int data) {
        if(currSize == capacity) {
            cout << "Queue is full" << endl;
            return;
        }

        if(f == -1) {
            f = 0;
        }

        r = (r + 1) % capacity;
        arr[r] = data;
        currSize++;
    }

    void dequeue() {
        if(empty()) {
            cout << "Queue is empty..." << endl;
            return;
        }

        f = (f + 1) % capacity;
        currSize--;

        if(currSize == 0) {
            f = r = -1;
        }
    }

    int front() {
        if(empty()) {
            return -1;
        }
        return arr[f];
    }

    bool empty() {
        return currSize == 0;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q1(4);

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);

    cout << "Front element: " << q1.front() << endl;

    q1.dequeue();
    cout << "Front after dequeue: " << q1.front() << endl;

    q1.enqueue(50);
    cout << "Front after enqueue: " << q1.front() << endl;

    return 0;
}
