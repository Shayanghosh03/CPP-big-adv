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

Node* buildBST(int arr[], int start, int end) {
    if(start > end) {
        return NULL;
    }

    int mid = start + (end - start) / 2;
    Node* curr = new Node(arr[mid]);

    curr -> left = buildBST(arr, start, mid - 1);
    curr -> right = buildBST(arr, mid + 1, end);

    return curr;
}

void preorderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }
    cout << root -> data << " ";
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
}

int main() {
    int arr[] = {3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int start = 0, end = n - 1;
    Node* root = buildBST(arr, start, end);

    cout << "Preorder Traversal for balanced BST => " << endl;
    preorderTraversal(root);

    return 0;
}