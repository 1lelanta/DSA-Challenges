#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Insert into BST
Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

// Find maximum node in a subtree (inorder predecessor)
Node* findMax(Node* root) {
    while (root && root->right != NULL)
        root = root->right;
    return root;
}

// Delete using copying
Node* deleteByCopying(Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data) {
        root->left = deleteByCopying(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteByCopying(root->right, key);
    }
    else {
        // Node found

        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children (COPYING)
        else {
            Node* pred = findMax(root->left); // inorder predecessor
            root->data = pred->data;          // copy value
            root->left = deleteByCopying(root->left, pred->data); // delete copied node
        }
    }
    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Driver code
int main() {
    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder before deletion: ";
    inorder(root);

    root = deleteByCopying(root, 50); // delete node with two children

    cout << "\nInorder after deletion: ";
    inorder(root);

    return 0;
}
