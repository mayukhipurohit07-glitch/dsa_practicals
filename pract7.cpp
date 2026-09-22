#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* last = NULL;

void insertBeginning(int value)
{
    Node* newNode = new Node;
    newNode->data = value;

    if (last == NULL)
    {
        last = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
    }
}

void insertEnd(int value)
{
    Node* newNode = new Node;
    newNode->data = value;

    if (last == NULL)
    {
        last = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void insertAfter(int key, int value)
{
    if (last == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node* temp = last->next;

    do
    {
        if (temp->data == key)
        {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;

            if (temp == last)
                last = newNode;

            return;
        }

        temp = temp->next;
    } while (temp != last->next);

    cout << "Node not found\n";
}

void deleteFirst()
{
    if (last == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node* first = last->next;

    if (first == last)
    {
        last = NULL;
    }
    else
    {
        last->next = first->next;
    }

    delete first;
}

void deleteLast()
{
    if (last == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node* first = last->next;

    if (first == last)
    {
        delete last;
        last = NULL;
        return;
    }

    Node* temp = first;

    while (temp->next != last)
    {
        temp = temp->next;
    }

    temp->next = last->next;
    delete last;
    last = temp;
}

void deleteAfter(int key)
{
    if (last == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node* temp = last->next;

    do
    {
        if (temp->data == key)
        {
            Node* deleteNode = temp->next;

            if (deleteNode == temp)
            {
                last = NULL;
            }
            else
            {
                temp->next = deleteNode->next;

                if (deleteNode == last)
                    last = temp;
            }

            delete deleteNode;
            return;
        }

        temp = temp->next;
    } while (temp != last->next);

    cout << "Node not found\n";
}

void display()
{
    if (last == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node* temp = last->next;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != last->next);

    cout << endl;
}

int main()
{
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    cout << "Original list: ";
    display();

    insertBeginning(5);
    cout << "After inserting at beginning: ";
    display();

    insertEnd(40);
    cout << "After inserting at end: ";
    display();

    insertAfter(20, 25);
    cout << "After inserting 25 after 20: ";
    display();

    deleteFirst();
    cout << "After deleting first node: ";
    display();

    deleteLast();
    cout << "After deleting last node: ";
    display();

    deleteAfter(20);
    cout << "After deleting node after 20: ";
    display();

    return 0;
}