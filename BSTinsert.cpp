#include <iostream>
using namespace std;

struct Node
{
    int Num;
    Node* Left;
    Node* Right;
};

Node* CreateNode(int value)
{
    Node* n = new Node;
    n->Num = value;
    n->Left = NULL;
    n->Right = NULL;
    return n;
}

void InsertBST(Node* root, Node* newNode)
{
    while (true)
    {
        if (newNode->Num < root->Num)
        {
            if (root->Left == NULL)
            {
                root->Left = newNode;
                return;
            }
            root = root->Left;
        }
        else if (newNode->Num > root->Num)
        {
            if (root->Right == NULL)
            {
                root->Right = newNode;
                return;
            }
            root = root->Right;
        }
        else
        {
            // Duplicate key not allowed
            return;
        }
    }
}

void InOrder(Node* root)
{
    if (root == NULL)
        return;

    InOrder(root->Left);
    cout << root->Num << " ";
    InOrder(root->Right);
}

int main()
{
    Node* root = CreateNode(50);

    InsertBST(root, CreateNode(30));
    InsertBST(root, CreateNode(70));
    InsertBST(root, CreateNode(20));
    InsertBST(root, CreateNode(40));
    InsertBST(root, CreateNode(60));
    InsertBST(root, CreateNode(80));

    cout << "Inorder Traversal: ";
    InOrder(root);

    return 0;
}
