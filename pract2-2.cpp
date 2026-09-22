#include<iostream>
using namespace std;
// ---------- CALL BY VALUE ----------

void swapByValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
    cout << "Inside swapByValue: x = " << x << ", y = " << y << endl;
}

// ---------- CALL BY REFERENCE ----------

void swapByReference(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
    cout << "Inside swapByReference: x = " << x << ", y = " << y << endl;
}

int main() {
    int a = 10, b = 20;

    cout << "--- Call by Value ---" << endl;
    cout << "Before call: a = " << a << ", b = " << b << endl;
    swapByValue(a, b);
    cout << "After call:  a = " << a << ", b = " << b << endl;
    cout << "(Original values unchanged, since only copies were modified)\n" << endl;

    cout << "--- Call by Reference ---" << endl;
    cout << "Before call: a = " << a << ", b = " << b << endl;
    swapByReference(a, b);
    cout << "After call:  a = " << a << ", b = " << b << endl;
    cout << "(Original values changed, since actual variables were modified)" << endl;

    return 0;

}