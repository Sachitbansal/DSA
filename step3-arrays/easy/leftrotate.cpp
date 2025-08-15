#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {8,10,5,7,9};

    // // left rotate by 1 place
    // int temp = arr[0];
    // for (int i = 1; i<5; i++) {
    //     arr[i-1] = arr[i];
    // }
    // arr[4] = temp;

    // for (auto i: arr) {
    //     cout << i << endl;
    // }

    // left rotate by d places
    // we can also do by making temp array, putting all shifting elements in that and shifting in original array and then putting temp elements in last
    int d = 1;
    for (int i = d+1; i < 5; i++) {
        for (int j = i; j>i-2; j--) {
            cout << "swapping " << arr[j] << " and " << arr[j-1] << endl;
            swap(arr[j], arr[j-1]);
        }
    }

    for (auto i: arr) {
        cout << i << endl;
    }

    return 0;
}