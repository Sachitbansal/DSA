#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int start, int end) {
    if (end <= start) {
        return;
    } else {
        swap(arr[start], arr[end]);
        reverseArray(arr, start+1, end-1);
    }
}

int main() {

    int arr[] = {1,2,3,4,5};
    for (auto i: arr) {
        cout << i << endl;
    }
    cout << "reversing" << endl;
    reverseArray(arr, 0, 4);
    for (auto i: arr) {
        cout << i << endl;
    }
    return 0;
}