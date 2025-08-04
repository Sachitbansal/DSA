#include <bits/stdc++.h>
using namespace std;

void printName(string name) {
    cout << "Hello, " << name << "!" << endl;
}

// pass by value example
// the original value of num will not change
void doSomething(int num) {
    cout << num << endl;
    num += 5; // incrementing num by 5
    cout << "After incrementing: " << num << endl;  
}

// pass by reference example
// the original value of name will change
void changeName(string &name) {
    name = "Changed Name"; // this will change the original string
}

// array always goes by reference
void changeArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] += 1; // increment each element by 1
    }
}

int main() {
    string name;
    cin >> name;
    printName(name);

    int num = 10;
    doSomething(num); // a copy of num is passed
    cout << "Final value of num: " << num << endl;

    changeName(name); // name is passed by reference where the address of the original string is passed
    // this means that the original string will be modified
    cout << "Name after change: " << name << endl;

    int arr[] = {1, 2, 3, 4, 5};
    cout << "Array before change: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    changeArray(arr, 5); // pass the array and its size
    cout << "Array after change: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
