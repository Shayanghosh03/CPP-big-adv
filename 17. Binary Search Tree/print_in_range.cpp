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

Node* insertNode(Node* root, int val) {
    if(root == NULL) {
        root = new Node(val);
        return root;
    }

    if(val < root -> data) {
        root -> left = insertNode(root -> left, val);
    } else {
        root -> right = insertNode(root -> right, val);
    }

    return root;
}

Node* buildTree(int arr[], int n) {
    Node* root = NULL;

    for(int i = 0; i< n; i++) {
        root = insertNode(root, arr[i]);
    }

    return root;
}

void inorderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    inorderTraversal(root -> left);
    cout << root -> data << " ";
    inorderTraversal(root -> right);
}

void printInRange(Node* root, int start, int end) {
    if(root == NULL) {
        return;
    }

    if(start <= root -> data && root -> data <= end) {
        cout << root -> data << " ";
        printInRange(root -> left, start, end);
        printInRange(root -> right, start, end);
    } else if(root -> data < start) {
        printInRange(root -> right, start, end);
    } else {
        printInRange(root -> left, start, end);
    }
}

int main() {
    int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    int n = sizeof(arr) /  sizeof(arr[0]);

    Node* root = buildTree(arr, n);

    inorderTraversal(root);
    cout << endl;

    cout << "Print in range 5 to 12 in this BST =>" << endl;
    printInRange(root, 5, 12);

    return 0;
}