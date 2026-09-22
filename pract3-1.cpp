#include <iostream>
using namespace std;
//implementation of stack using array push,pop,peek and display
class Stack {
    int top;
    int arr[20];
public:
    Stack() {
        top = -1;
    }
    void push(int value) {
        if (top >= 19) {
            cout << "Stack overflow" << endl;
            return;
        } 
        arr[++top] = value;
        cout << "Pushed " << value << " to stack" << endl;
    }
    void pop() {
        if (top < 0) {
            cout << "Stack underflow" << endl;
            return;
        }
        cout << "Popped " << arr[top--] << " from stack" << endl;
    }
    int peek() {
        if (top < 0) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
    void display() {
        if (top < 0) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();
    cout << "Top element is: " << s.peek() << endl;
    return 0;
}