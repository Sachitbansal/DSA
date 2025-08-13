#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {13,46,24,52,20,9};


    for (int i = 1; i < 6; i++) {
        // can combine if and for into a single while loop
        // for (int j = i; j >= 1; j--) {
        //     if (arr[j] < arr[j-1]) {
        //         swap(arr[j], arr[j-1]);
        //     }
        // }
        int j = i;
        while (j > 0 && arr[j] < arr[j-1]) {
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
    

    for (auto i: arr) {
        cout << i << endl;
    }

    return 0;
}