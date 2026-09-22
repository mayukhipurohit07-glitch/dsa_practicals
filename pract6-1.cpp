#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Insert node at beginning
void insertBeginning(Node *&head, int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertEnd(Node *&head, int value)
{
    Node *newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert after a given node
void insertAfter(Node *head, int givenValue, int value)
{
    Node *temp = head;

    while (temp != NULL && temp->data != givenValue)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Given node not found.\n";
        return;
    }

    Node *newNode = new Node;

    newNode->data = value;
    newNode->next = temp->next;

    temp->next = newNode;
}

// Delete first node
void deleteFirst(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;

    head = head->next;

    delete temp;
}

// Delete last node
void deleteLast(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    // If only one node exists
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

// Delete node after a given node
void deleteAfter(Node *head, int givenValue)
{
    Node *temp = head;

    while (temp != NULL && temp->data != givenValue)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        cout << "Node after given node does not exist.\n";
        return;
    }

    Node *deleteNode = temp->next;

    temp->next = deleteNode->next;

    delete deleteNode;
}

// Display all nodes
void display(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;

    cout << "Linked List: ";

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main()
{

    Node *head = NULL;

    // Insert operations
    insertBeginning(head, 20);
    insertBeginning(head, 10);

    insertEnd(head, 40);
    insertEnd(head, 50);

    insertAfter(head, 20, 30);

    cout << "After insertion:\n";
    display(head);

    // Delete first node
    deleteFirst(head);

    cout << "\nAfter deleting first node:\n";
    display(head);

    // Delete last node
    deleteLast(head);

    cout << "\nAfter deleting last node:\n";
    display(head);

    // Delete node after a given node
    deleteAfter(head, 20);

    cout << "\nAfter deleting node after 20:\n";
    display(head);
    return 0;
}