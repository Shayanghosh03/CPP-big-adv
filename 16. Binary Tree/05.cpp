#include<iostream>
#include<queue>
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

static int idx = -1;
Node* buildTree(vector<int> nodes) {
    idx++;
    if(nodes[idx] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode -> left = buildTree(nodes);
    currNode -> right = buildTree(nodes);

    return currNode;
};

void levelOrderTraversal(Node* root, int key) {
    if(root == NULL) {
        return;
    }

    int count = 1;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if(curr == NULL) {
            count++;
            if(q.empty()) {
                break;
            }
            q.push(NULL);
        } else {
            if(key == count) {
                cout << curr -> data << " ";
            }
            if(curr -> left != NULL) {
                q.push(curr -> left);
            }
            if(curr -> right != NULL) {
                q.push(curr -> right);
            }
        }
    }
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    levelOrderTraversal(root, 2);

    return 0;
}