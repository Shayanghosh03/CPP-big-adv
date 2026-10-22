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

Node* getInorderSuccessor(Node* root) {
    while(root -> left != NULL) {
        root = root -> left;
    }
    return root;
}

Node* deleteNode(Node* root, int val) {
    if(root == NULL) {
        return NULL;
    }

    if(val < root -> data) {
        root -> left = deleteNode(root -> left, val);
    } else if(val > root -> data) {
        root -> right = deleteNode(root -> right, val);
    } else {
        // root == val
        // case 1 => 0 children
        if(root -> left == NULL && root -> right == NULL) {
            delete root;
            return NULL;
        }

        // case 2 => 1 children
        if(root -> left == NULL || root -> right == NULL) {
            return root -> left == NULL ? root -> right : root -> left;
        }

        // case 3 => 2 children
        Node* IS = getInorderSuccessor(root -> right);
        root -> data = IS -> data;
        root -> right = deleteNode(root -> right, IS -> data);

        return root;
    }
}

int main() {
    int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    int n = sizeof(arr) /  sizeof(arr[0]);

    Node* root = buildTree(arr, n);

    inorder(root);
    cout << endl;

    cout << "After deleting 4" << endl;

    deleteNode(root, 4);

    inorder(root);

    return 0;
}