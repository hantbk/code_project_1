#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};

Node *newNode(int data)
{
    Node *node = new Node;
    node->key = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node *insertNode(Node *node, int key)
{
    if (node == nullptr)
    {
        return newNode(key);
    }
    if (key < node->key)
    {
        node->left = insertNode(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insertNode(node->right, key);
    }
    return node;
}

void preorderTraversal(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    cout << node->key << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

int main()
{
    string sequence;
    int root;
    cin >> sequence >> root;
    Node *node = newNode(root);
    cin>>sequence;
    while (sequence != "#")
    {
        if (sequence == "insert")
        {
            int n;
            cin >> n;
            insertNode(node, n);
        }
        cin >> sequence;
    }
    preorderTraversal(node);
    return 0;
}