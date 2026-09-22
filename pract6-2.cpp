#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

// Insert at end (helper, just to build the list for testing)
void insertEnd(int val)
{
    Node *n = new Node{val, NULL};
    if (head == NULL)
    {
        head = n;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = n;
}

// Delete first node
void deleteFirst()
{
    if (head == NULL)
        return;
    Node *temp = head;
    head = head->next;
    delete temp;
}

// Delete last node
void deleteLast()
{
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

// Delete node after a given node (by value)
void deleteAfter(int key)
{
    Node *temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
    {
        cout << "Cannot delete\n";
        return;
    }
    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}

// Display list
void display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main()
{
    insertEnd(10);
    insertEnd(20);
    insertEnd(25);
    insertEnd(30);
    display();
    deleteFirst();
    display();
    deleteLast();
    display();
    insertEnd(30);
    deleteAfter(20);
    display();

    return 0;
}
