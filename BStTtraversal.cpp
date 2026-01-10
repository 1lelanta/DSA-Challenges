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
            return;
        }
    }
}

void Preorder(Node* CurrNodePtr)
{
    if (CurrNodePtr != NULL)
    {
        cout << CurrNodePtr->Num << " ";
        Preorder(CurrNodePtr->Left);
        Preorder(CurrNodePtr->Right);
    }
}

void Inorder(Node* CurrNodePtr)
{
    if (CurrNodePtr != NULL)
    {
        Inorder(CurrNodePtr->Left);
        cout << CurrNodePtr->Num << " ";
        Inorder(CurrNodePtr->Right);
    }
}

void Postorder(Node* CurrNodePtr)
{
    if (CurrNodePtr != NULL)
    {
        Postorder(CurrNodePtr->Left);
        Postorder(CurrNodePtr->Right);
        cout << CurrNodePtr->Num << " ";
    }
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

    cout << "Preorder Traversal: ";
    Preorder(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    Inorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    Postorder(root);
    cout << endl;

    return 0;
}
