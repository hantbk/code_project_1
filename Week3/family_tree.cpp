#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct Node
{
    string name;
    vector<Node *> list_child;
};

unordered_map<string, Node *> family_tree;

void insertChild(Node *parent, string child_name)
{
    if (family_tree.find(child_name) != family_tree.end())
    {
        Node *child = family_tree[child_name];
        parent->list_child.push_back(child);
        return;
    }
    Node *child = new Node;
    child->name = child_name;
    parent->list_child.push_back(child);
    family_tree[child_name] = child;
}

int countDescentants(Node *node)
{
    int count = 0;
    for (Node *child : node->list_child)
    {
        count += 1 + countDescentants(child);
    }
    return count;
}

int countGeneration(Node *node)
{
    int maxGeneration = 0;
    for (Node *child : node->list_child)
    {
        maxGeneration = max(maxGeneration, 1 + countGeneration(child));
    }
    return maxGeneration;
}

// void printPostorder(Node* node) {
//     if (node == NULL)
//         return;
//     for (int i = 0; i < node->list_child.size(); i++)
//         printPostorder(node->list_child[i]);
//     cout << node->name << " ";
// }

int main()
{

    string child, parent;
    cin >> child >> parent;
    Node *root = new Node;
    root->name = parent;
    family_tree[parent] = root;
    insertChild(root, child);
    while (cin >> child)
    {
        if (child == "***")
        {
            string sequence;
            cin >> sequence;
            while (sequence != "***")
            {
                if (sequence == "descendants")
                {
                    string name;
                    cin >> name;
                    cout << countDescentants(family_tree[name]) << endl;
                }
                else if (sequence == "generation")
                {
                    string name;
                    cin >> name;
                    cout << countGeneration(family_tree[name]) << endl;
                }
                cin >> sequence;
                if(sequence == "***")
                    break;
            }
        }
        else
        {
            cin >> parent;
            if (family_tree.find(parent) == family_tree.end())
            {
                Node *new_parent = new Node;
                new_parent->name = parent;
                family_tree[parent] = new_parent;
            }
            insertChild(family_tree[parent], child);
        }
    }
    // cout << countDescentants(root) << endl;
    // cout << countGeneration(root) << endl;
    // printPostorder(root);
    return 0;
}