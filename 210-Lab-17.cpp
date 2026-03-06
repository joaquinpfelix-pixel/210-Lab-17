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
    Node *head = nullptr;

    //create list using addFront
    for(int i = 0; i <SIZE; i++)
    {
        int tmp_val = rand() % 100;
        addFront(head, tmp_val);
    }

    output(head);

    //delete node
    int entry;
    cout<< "Which node to delete? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;

    deleteNode(head, entry);
    output(head);
    
    // insert Node
    cout << "After which node to insert 10000? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;

    insertNode(head, entry, 10000);
    output(head);


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
    
    if (!head)
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
        current = current->next;
    }

    if (!current) return;
    if (prev == nullptr)
    {
        head = current->next;
    } else{
        prev->next = current->next;
    }

    delete current;
}

// insert node after position
void insertNode(Node *&head, int pos, float val)
{
    Node *current = head;

    for (int i = 1; i < pos && current; i++)
    {
        current = current->next;
    }

    if(!current) return;

    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = current->next;

    current->next = newNode;
}

// delete entire linked list
void deleteList(Node *&head){
    Node *current = head;

    while (current)
    {
        Node *tmp = current;
        current = current->next;
        delete tmp;
    }

    head = nullptr;
}
