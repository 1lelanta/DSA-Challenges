#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create new node
Node* createNode(int value) {
    Node* node = new Node;
    node->data = value;
    node->left = node->right = nullptr;
    return node;
}

// Insert into BST
Node* insert(Node* root, int value) {
    if (!root) return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

Node* findMaxNode(Node* root) {
    while (root && root->right)
        root = root->right;
    return root;
}

// Merge deletion (always max from left subtree)
Node* mergeDelete(Node* root, int key) {
    if (!root) return nullptr;

    if (key < root->data)
        root->left = mergeDelete(root->left, key);
    else if (key > root->data)
        root->right = mergeDelete(root->right, key);
    else {
        // Node found

        // Case 1: No child
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }

        // Case 2: One child
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children (merge with max from left)
        Node* leftSub = root->left;
        Node* maxNode = findMaxNode(leftSub);

        // Detach maxNode from its parent
        if (maxNode != leftSub) {
            Node* parent = leftSub;
            while (parent->right != maxNode)
                parent = parent->right;
            parent->right = maxNode->left; // attach left subtree of maxNode
            maxNode->left = leftSub;
        }
        maxNode->right = root->right;

        delete root;
        return maxNode;
    }
    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Main
int main() {
    Node* root = nullptr;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter node " << i + 1 << ": ";
        cin >> val;
        root = insert(root, val);
    }

    cout << "Inorder BST: ";
    inorder(root);
    cout << endl;

    int key;
    cout << "Enter node to delete: ";
    cin >> key;

    root = mergeDelete(root, key);

    cout << "BST after merge deletion (inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
