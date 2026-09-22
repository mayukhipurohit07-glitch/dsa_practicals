#include <iostream>
using namespace std;

int queueData[5];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (rear == 4)
    {
        cout << "Queue overflow" << endl;
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queueData[rear] = x;
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue underflow" << endl;
        return -1;
    }
    int x = queueData[front];
    front++;
    return x;
}

void display()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++)
    {
        cout << queueData[i] << " ";
    }
    cout << endl;
}

int main()
{
    int choice, x;
    while (1)
    {
        cout << "1. Enqueue 2. Dequeue 3. Display 4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter element to enqueue: ";
            cin >> x;
            enqueue(x);
            break;
        case 2:
            x = dequeue();
            if (x != -1)
            {
                cout << "Dequeued element: " << x << endl;
            }
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}