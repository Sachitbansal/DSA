#include <bits/stdc++.h>
using namespace std;

int main() {

    
    // vector<int> arr = {8,10,5,7,9};
    int arr[]={1,2,4,6,7,5};

    // brute better approach using 2 loops
    // int largest = 0;
    // int second = 0;
    // for (auto i: arr) {
    //     if (largest < i) {
    //         largest = i;
    //     }
    // }
    // cout << largest << endl;
    // for (auto i: arr) {
    //     if (second <= i && i < largest ) {
    //         second = i;
    //     }
    // }
    // cout << second;

    // optimal approach using 2 point approach
    int largest = 0;
    int second = 0;
    for (auto i: arr) {
        if (largest < i) {
            second = largest;
            largest = i;
        } else if (second <= i && i != largest ) {
            second = i;
        }
    }
  
    cout << largest << endl;
    cout << second << endl;
    return 0;
}

