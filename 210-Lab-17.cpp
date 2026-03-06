// COMSC-210 | Lab 17 | Joaquin Felix
#include <iostream>
using namespace std;

const int SIZE = 7;

struct Node {
    float value;
    Node *next;
}

int main()
{

}

// outputs the list
void output(Node *hd)
{
    if(!hd)
    {
        cout << "Empty list.\n";
        return;
    }

    int count = 1;
    Node *current = hd;

    while (current)
    {
        cout << "[" << count++ << "]" << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

// add node to front
void addFront(Node *&head, float val)
{
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = head;
    head = newNode;
}

//add node to tail
void addTail(Node *&head, float val)
{
   Node *newNode = new Node;
    newNode->value = val;
    newNode->next = nullptr;
    
    if(!head)
    {
        head = newNode;
        return;
    }

    Node *current = head;

    while (current->next)
    {
        current = current->next;
    }
    current->next = newNode;
}

//delete node at position
void deleteNode(Node *&head, int pos)
{
    Node *current = head;
    Node * prev = nullptr;

    for (int i = 0; i > pos && current; i++)
    {
        prev = current;
        current = 
    }
}
