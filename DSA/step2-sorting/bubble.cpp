#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int limit, int index) {
    if (index == limit) {
        return;
    } 
    if (arr[index] > arr[index+1]) {
        swap(arr[index], arr[index+1]);
    }
    bubbleSort(arr, limit, index+1);

}

void looping(int arr[], int limit, int index) {
    if (limit == index) {
        return;
    }
    bubbleSort(arr, limit - index - 1, 0);
    looping(arr, limit, index+1);
}


int main() {

    int arr[] = {13,46,24,52,20,9};


    // normal bubble sort

    // for (int i = 0; i < 6; i++) {
    //     bool Didswap = false;
    //     for (int j = 0; j < 6 - i - 1; j++) {
    //         if (arr[j] > arr[j+1]) {
    //             swap(arr[j], arr[j+1]);
    //             Didswap = true;
    //         }
    //     }
    //     if (Didswap) {
    //         break;
    //     }
    // }


    // for (int i = 0; i < 6; i++) {
    //     bubbleSort(arr, 6-i-1, 0);
    // }

    // recursive bubble sort

    looping(arr, 6, 0);


    for (auto i: arr) {
        cout << i << endl;
    }

    return 0;
}