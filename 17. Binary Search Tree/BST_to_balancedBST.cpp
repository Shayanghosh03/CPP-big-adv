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

void getInorder(Node* root, vector<int>& nodes) {
    if(root == NULL) {
        return;
    }
    getInorder(root -> left, nodes);
    nodes.push_back(root -> data);
    getInorder(root -> right, nodes);
}

Node* buildBalancedBST(vector<int> nodes, int start, int end) {
    if(start > end) {
        return NULL;
    }

    int mid = start + (end - start) / 2;

    Node* curr = new Node(nodes[mid]);

    curr -> left = buildBalancedBST(nodes, start, mid - 1);
    curr -> right = buildBalancedBST(nodes, mid + 1, end);

    return curr;
}

Node* balancedBST(Node* root) {
    vector<int> nodes;
    getInorder(root, nodes);
    
    return buildBalancedBST(nodes, 0, nodes.size() - 1);
}

void preorder(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

int main() {
    // Normal BST
    Node* root = new Node(6);
    root -> left = new Node(5);
    root -> left -> left = new Node(4);
    root -> left -> left -> left = new Node(3);

    root -> right = new Node(7);
    root -> right -> right = new Node(8);
    root -> right -> right -> right = new Node(9);

    cout << "Normal BST preorder =>" << endl;
    preorder(root);
    cout << endl;

    root = balancedBST(root);
    cout << "After balanced BST preorder =>" << endl;
    preorder(root);

    return 0;
}