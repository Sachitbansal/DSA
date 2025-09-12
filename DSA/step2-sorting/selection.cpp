#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {13,46,24,52,20,9};


    for (int i = 0; i < 6; i++) {
        // swap with arr[i]
        int minIndex = i;
        for (int j = i+1; j < 6; j++) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }



    for (auto i: arr) {
        cout << i << endl;
    }
    return 0;
}