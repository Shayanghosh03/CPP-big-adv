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

void mergeNodes(vector<int> nodes1, vector<int> nodes2, vector<int>& finalNodes) {
    int i = 0;
    int j = 0;
    while(i < nodes1.size() && j < nodes2.size()) {
        if(nodes1[i] < nodes2[j]) {
            finalNodes.push_back(nodes1[i]);
            i++;
        } else {
            finalNodes.push_back(nodes2[j]);
            j++;
        }
    }

    while(i < nodes1.size()) {
        finalNodes.push_back(nodes1[i]);
        i++;
    }
    while(j < nodes2.size()) {
        finalNodes.push_back(nodes2[j]);
        j++;
    }
}

Node* createBST(vector<int>& nodes, int start, int end) {
    if(start > end) {
        return NULL;
    }

    int mid = start + (end - start) / 2;

    Node* currNode = new Node(nodes[mid]);
    currNode -> left = createBST(nodes, start, mid - 1);
    currNode -> right = createBST(nodes, mid + 1, end);

    return currNode;
}

Node* mergeBST(Node* root1, Node* root2) {
    vector<int> nodes1;
    vector<int> nodes2;
    vector<int> finalNodes;

    getInorder(root1, nodes1);
    getInorder(root2, nodes2);

    mergeNodes(nodes1, nodes2, finalNodes);

    // Create the BST using this 
    int start = 0, end = finalNodes.size() - 1;

    return createBST(finalNodes,start, end);
}

void inorderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    inorderTraversal(root -> left);
    cout << root -> data << " ";
    inorderTraversal(root -> right);
}

int main() {
    Node* root1 = new Node(2);
    root1 -> left = new Node(1);
    root1 -> right = new Node(4);

    Node* root2 = new Node(9);
    root2 -> left = new Node(3);
    root2 -> right = new Node(12);

    Node* root = mergeBST(root1, root2);

    inorderTraversal(root);

    return 0;
}