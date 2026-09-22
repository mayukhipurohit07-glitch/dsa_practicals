#include<iostream>
using namespace std;
int main(){
    //insertion in an array
    int arr[20] = {10, 20, 30, 40, 50};
    int n = 5; 

    int index = 2;
    int insertValue = 25;

    for (int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = insertValue;
    n++;
    cout << "After inserting " << insertValue << " at index " << index << ": \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " \n";
    }
        
//deletetion in an array
int deletePos = 1;

    for (int i = deletePos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;

    cout << "After deleting element at index " << deletePos << ": \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " \n";
    }
    //search in an array
    int searchValue = 30;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == searchValue) {
            found = true;
            cout << "Element " << searchValue << " found at index " << i << endl;
            break;
        }
    }
    if (!found) {
        cout << "Element " << searchValue << " not found in the array." << endl;
    }
    //traversal in an array
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}