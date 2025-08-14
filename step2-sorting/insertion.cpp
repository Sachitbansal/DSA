#include <bits/stdc++.h>
using namespace std;

void whiling(int arr[], int index) {
    
    if (index == 0) return;
    if (arr[index] < arr[index-1]) {
        swap(arr[index], arr[index-1]);
    }
    whiling(arr, index-1);

}

void insertion(int arr[], int limit, int index) {
    
    if (limit == index) return;

    // int j = index;
    // while (j > 0 && arr[j] < arr[j-1]) {
    //     swap(arr[j], arr[j-1]);
    //     j--;
    // }

    whiling(arr, index);
    insertion(arr, limit, index+1);
    
}


int main() {

    int arr[] = {13,46,24,52,20,9};

    // for (int i = 1; i < 6; i++) {
    //     // can combine if and for into a single while loop
    //     // for (int j = i; j >= 1; j--) {
    //     //     if (arr[j] < arr[j-1]) {
    //     //         swap(arr[j], arr[j-1]);
    //     //     }
    //     // }
    //     int j = i;
    //     while (j > 0 && arr[j] < arr[j-1]) {
    //         swap(arr[j], arr[j-1]);
    //         j--;
    //     }
    // }

    insertion(arr, 6, 1);


    for (auto i: arr) {
        cout << i << endl;
    }

    return 0;
}