#include <iostream>
using namespace std;

int main() {
    //array in reverse order using pointer
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr + 4; // pointer to the last element

    cout << "Array elements in reverse order: ";
    for (int i = 0; i < 5; i++) {
        cout << *ptr << " ";
        ptr--;
    }
    cout << endl;

    return 0;
}