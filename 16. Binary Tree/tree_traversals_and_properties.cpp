#include<iostream>
#include<queue>
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

static int idx = -1;
Node* buildTree(vector<int> nodes) {
    idx++;

    if(nodes[idx] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode -> left = buildTree(nodes); // Left Subtree
    currNode -> right = buildTree(nodes); // Right Subtree

    return currNode;
}

void preorder(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void postorder(Node* root) {
    if(root == NULL) {
        return;
    }

    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

void levelorder(Node* root) {
    if(root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if(curr == NULL) {
            cout << endl;
            if(q.empty()) {
                break;
            }
            q.push(NULL);
        } else {
            cout << curr -> data << " ";

            if(curr -> left != NULL) {
                q.push(curr -> left);
            }
            if(curr -> right != NULL) {
                q.push(curr -> right);
            }
        }
    }
}

int height(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int left = height(root -> left);
    int right = height(root -> right);

    int currHeight = max(left, right) + 1;

    return currHeight;
}

int countNode(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftCount = countNode(root -> left);
    int rightCount = countNode(root -> right);

    return leftCount + rightCount + 1;
}

int nodeSum(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftSum = nodeSum(root -> left);
    int rightSum = nodeSum(root -> right);

    int currSum = leftSum + rightSum + root -> data;

    return currSum;
}

int diameter1(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int currHt = height(root -> left) + height(root -> right) + 1;
    int leftHt = diameter1(root -> left);
    int rightHt = diameter1(root -> right);

    return max(currHt, max(leftHt, rightHt));

}

pair<int, int> diameter2(Node* root) {
    if(root == NULL) {
        return {0, 0};
    }

    pair<int, int> leftInfo = diameter2(root -> left); // LD LH
    pair<int, int> rightInfo = diameter2(root -> right); // RD RH

    int currDiam = leftInfo.second + rightInfo.second + 1;
    int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first));

    int finalHeight = max(leftInfo.second, rightInfo.second) + 1;

    return make_pair(finalDiam, finalHeight);
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1}; // Preorder Sequence

    Node* root = buildTree(nodes);

    cout << "Root Node => " << root -> data << endl;

    cout << "Preorder Traversal" << endl;
    preorder(root);
    cout << endl;

    cout << "Inorder Traversal" << endl;
    inorder(root);
    cout << endl;

    cout << "Postorder Traversal" << endl;
    postorder(root);
    cout << endl;

    cout << "Levelorder Traversal" << endl;
    levelorder(root);

    cout << "Height of the tree is => " << height(root) << endl;

    cout << "Total no of Nodes => " << countNode(root) << endl;

    cout << "Total node sum is => " << nodeSum(root) << endl;

    cout << "Diameter of this tree is => " << diameter1(root) << endl;
    cout << "Optimal Diameter of this tree is =>" << diameter2(root).first << endl;
    cout << "Hight of this tree is => " << diameter2(root).second << endl;
    
    return 0;
}