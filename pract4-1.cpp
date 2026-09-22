#include<iostream>
using namespace std;
//convert an expression from infix to postfix using array implementation of stack
class Stack {
    int top;
    char arr[20];
public:
    Stack() {
        top = -1;
    }
    void push(char value) {
        if (top >= 19) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = value;
    }
    char pop() {
        if (top < 0) {
            cout << "Stack underflow" << endl;
            return '\0';
        }
        return arr[top--];
    }
    char peek() {
        if (top < 0) {
            cout << "Stack is empty" << endl;
            return '\0';
        }
        return arr[top];
    }
    bool isEmpty() {
        return top < 0;
    }
};
int precedence1(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 3;
    if (op == '^') return 6;
    if (op == '(') return 9;
    if (op == ')') return '\0';
    return -1;
}
int precedence2(char op) {
    if (op == '+' || op == '-') return 2;
    if (op == '*' || op == '/') return 4;
    if (op == '^') return 5;
    if (op == '(') return '\0' ;
    if (op == ')') return 9;
    return -1;
}
void infixToPostfix(string infix) {
    Stack s;
    string postfix = "";
    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else {
            while (!s.isEmpty() && precedence1(s.peek()) >= precedence2(c)) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        postfix += s.pop();
    }
    cout << "Postfix expression: " << postfix << endl;
}
int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;
    infixToPostfix(infix);
    return 0;
}