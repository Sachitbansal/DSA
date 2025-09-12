#include <bits/stdc++.h>
using namespace std;

void quick(int arr[], int low, int high) {
    if (low>= high) return;
    int lower = low+1;
    int higher = high;

    int pivot = arr[low];

    // while(lower <= higher) {
    //     while (arr[lower] > pivot) lower++;
    //     while (arr[higher] < pivot) higher--;
    //     if (lower > higher) {
    //         swap(arr[lower], arr[higher]);
    //     }
    // }

    for (int i = low+1; i < high; i++) {
        for (int j = high; j > i; j--) {
            if (arr[i] > pivot) {
                if (arr[j] < pivot) {
                    lower = i;
                    higher = j;
                    cout << "swappinggg "<< arr[i] << " " << arr[j] << endl;
                    swap(arr[i], arr[j]);
                    
                }
            }
        }
    }

    cout << "swapping "<< arr[higher] << " " << arr[low] << endl;
    swap(arr[lower], arr[low]);
    
    for (int i = low; i <= high; i++) {
        cout << arr[i] << endl;
    }
    cout << "finihsihnf" << endl;
    quick(arr, low, lower-1);
    quick(arr, lower+1, high);

}



int main() {

    int arr[] = {4,6,2,5,7,9,1,3};

    quick(arr, 0, 5);

    for (auto i: arr) {
        cout << i << endl;
    }
    return 0;
}