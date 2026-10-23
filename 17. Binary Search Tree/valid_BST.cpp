// Min Max Method
#include<iostream>
#include<vector>
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

    if(root -> data > val) {
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

void inorderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    inorderTraversal(root -> left);
    cout << root -> data << " ";
    inorderTraversal(root -> right);
}

bool validedHelper(Node* root, Node* min, Node* max) {
    if(root == NULL) {
        return true;
    }

    if(min != NULL && root -> data <= min -> data) {
        return false;
    }
    if(max != NULL && root -> data >= max -> data) {
        return false;
    }

    return validedHelper(root -> left, min, root) && validedHelper(root -> right, root, max);
}

bool validedBST(Node* root) {
    return validedHelper(root, NULL, NULL);
}

int main() {
    int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node* root = buildTree(arr, 9);
    // root -> data = 15; Not valid when root is 15

    inorderTraversal(root);
    cout << endl;

    validedBST(root) ? cout << "This is a valid BST" << endl : cout << "This is not a valid BST" << endl;
    

    return 0;
}