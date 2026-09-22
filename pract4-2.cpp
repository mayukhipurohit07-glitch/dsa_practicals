#include <iostream>
#include <cmath>      // for pow()
using namespace std;

int stack[20];
int top = -1;

// Push function
void push(int x)
{
   stack[++top] = x;
}

// Pop function
int pop()
{
    return stack[top--];
}

int main()
{
    char postfix[30];
    int i = 0;

    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    while (postfix[i] != '\0')
    {
        char ch = postfix[i];

        // If operand (0-9)
        if (ch >= '0' && ch <= '9')
        {
            push(ch - '0');     // Convert character to integer
        }
        // If operator
        else
        {
            int b = pop();
            int a = pop();
            int result;

            switch (ch)
            {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                case '^': result = pow(a, b); break;
            }

            push(result);
        }

        i++;
    }

    cout << "Result = " << pop();

    return 0;
}