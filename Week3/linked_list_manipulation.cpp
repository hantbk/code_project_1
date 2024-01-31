#include <iostream>
#include <map>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
map<int, Node*> linked_list;

Node* addFirst(Node* head, int data)
{
    if (head == NULL)
    {
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = NULL;
        linked_list[data] = new_node;
        return new_node;
    }

    if (linked_list[data] == NULL)
    {
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = head;
        linked_list[data] = new_node;
        return new_node;
    }    
    return head;
}

Node* addLast(Node* head, int data)
{
    if (head == NULL)
    {
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = NULL;
        linked_list[data] = new_node;
        return new_node;
    }

    if(linked_list[data] == NULL)
    {
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = NULL;
        linked_list[data] = new_node;
        Node* node = head;
        while(node->next != NULL)
        {
            node = node->next;
        }
        node->next = new_node;
        return head;
    }
    return head;
}

Node* addAfter(Node* head, int u, int v){
    if (head == NULL)
    {
        Node* new_node = new Node;
        new_node->data = v;
        new_node->next = NULL;
        linked_list[v] = new_node;
        return new_node;
    }

    if (linked_list[v] && linked_list[u] == NULL)
    {
        Node* new_node = new Node;
        new_node->data = u;
        new_node->next = NULL;
        linked_list[u] = new_node;
        Node* node = head;
        while(node->data != v)
        {
            node = node->next;
        }
        new_node->next = node->next;
        node->next = new_node;
        return head;
    }
    return head;
}

Node* addBefore(Node* head, int u, int v){
    if (head == NULL)
    {
        Node* new_node = new Node;
        new_node->data = v;
        new_node->next = NULL;
        linked_list[v] = new_node;
        return new_node;
    }

    if (linked_list[v] && linked_list[u] == NULL)
    {
        Node* new_node = new Node;
        new_node->data = u;
        new_node->next = NULL;
        linked_list[u] = new_node;
        Node* node = head;
        while(node->next->data != v)
        {
            node = node->next;
        }
        new_node->next = node->next;
        node->next = new_node;
        return head;
    }
    return head;
}

Node* remove(Node* head, int u){
    if (head == NULL)
    {
        return NULL;
    }

    if(linked_list[u]==NULL)
    {
        return head;
    }

    if(linked_list[u]==head)
    {
        Node* node = head;
        head = head->next;
        linked_list[u] = NULL;
        delete node;
        return head;
    }

    if(linked_list[u]!=head)
    {
        Node* node = head;
        while(node->next->data != u)
        {
            node = node->next;
        }
        Node* temp = node->next;
        node->next = node->next->next;
        linked_list[u] = NULL;
        delete temp;
        return head;
    }
}

Node* reverse(Node* head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next; 
    }
    head = prev;
    return head;
}

int main()
{
    Node* head = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        head = addLast(head, data);
    }
    string sequence;
    cin >> sequence;
    while (sequence != "#")
    {
        if (sequence == "addfirst")
        {
            int data;
            cin >> data;
            head = addFirst(head, data);
        }
        else if (sequence == "addlast")
        {
            int data;
            cin >> data;
            head = addLast(head, data);
        }
        else if (sequence == "addafter")
        {
            int u, v;
            cin >> u >> v;
            head = addAfter(head, u, v);
        }
        else if (sequence == "addbefore")
        {
            int u, v;
            cin >> u >> v;
            head = addBefore(head, u, v);
        }
        else if (sequence == "remove")
        {
            int u;
            cin >> u;
            head = remove(head, u);
        }
        else if (sequence == "reverse")
        {
            head = reverse(head);
        }
        cin >> sequence;
    }

    for(Node* node = head; node != NULL; node = node->next)
    {
        cout << node->data << " ";
    }
    return 0;
}