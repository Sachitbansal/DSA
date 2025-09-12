#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr2 = {8,10,5,7,9};


    int largest = 0;
    for (auto i: arr2) {
        if (largest < i) {
            largest = i;
        }
    }

    cout << largest;
    return 0;
}