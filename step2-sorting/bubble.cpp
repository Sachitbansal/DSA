#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {13,46,24,52,20,9};


    for (int i = 0; i < 6; i++) {
        bool Didswap = false;
        for (int j = 0; j < 6 - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                Didswap = true;
            }
        }
        if (Didswap) {
            break;
        }
    }


    for (auto i: arr) {
        cout << i << endl;
    }

    return 0;
}