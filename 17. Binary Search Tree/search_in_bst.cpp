#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this -> data = data;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if(root == NULL) {
        root = new Node(val);
        return root;
    }

    if(val < root -> data) {
        root -> left = insert(root -> left, val);
    } else {
        root -> right = insert(root -> right, val);
    }

    return root;
}

Node* buildTree(int arr[], int n) {
    Node* root = NULL;

    for(int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    return root;
}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

bool searchKey(Node* root, int key) {
    if(root == NULL) {
        return false;
    }

    if(root -> data == key) {
        return true;
    }

    if(root -> data < key) {
        return searchKey(root -> left, key);
    } else {
        return searchKey(root -> right, key);
    }
}

int main() {
    int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    int n = sizeof(arr) /  sizeof(arr[0]);

    Node* root = buildTree(arr, n);

    inorder(root);

    cout << "Searching 6 => " << searchKey(root, 6) << endl; 

    return 0;
}