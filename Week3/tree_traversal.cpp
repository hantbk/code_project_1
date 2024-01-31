#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    vector<Node*> children;
};

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    return node;
}

Node* insertNode(Node* node, int data, int parent)
{
    if (node == NULL)
        return newNode(data);
    if (node->data == parent)
    {
        node->children.push_back(newNode(data));
        return node;
    }
    for (int i = 0; i < node->children.size(); i++)
        node->children[i] = insertNode(node->children[i], data, parent);
    return node;
}

void printPostorder(Node* node)
{
    if (node == NULL)
        return;
    for (int i = 0; i < node->children.size(); i++)
        printPostorder(node->children[i]);
    cout << node->data << " ";
}

void printPreorder(Node* node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    for (int i = 0; i < node->children.size(); i++)
        printPreorder(node->children[i]);
}

void printInorder(Node* node)
{
    if (node == NULL)
        return;
    if (node->children.size() >= 2)
    {
        printInorder(node->children[0]);
        cout << node->data << " ";
        for (int i = 1; i < node->children.size(); i++)
            printInorder(node->children[i]);
    }
    else
    {
        cout << node->data << " ";
        for (int i = 0; i < node->children.size(); i++)
            printInorder(node->children[i]);
    }
}

int main()
{
    string sequence;
    Node* root = NULL;
    cin >> sequence;
    while (sequence != "*")
    {
        if (sequence == "MakeRoot")
        {
            int data;
            cin >> data;
            root = newNode(data);
        }
        if(sequence == "Insert")
        {
            int data,parent;
            cin >> data >> parent;
            root = insertNode(root, data, parent);
        }
        if (sequence == "PreOrder")
        {
            printPreorder(root);
            cout << endl;
        }
        if (sequence == "PostOrder")
        {
            printPostorder(root);
            cout << endl;
        }
        if (sequence == "InOrder")
        {
            printInorder(root);
            cout << endl;
        }
        cin >> sequence;
    }
    
    return 0;
}