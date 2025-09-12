#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[]={1,2,4,7,6,5};

    // no need to use extra variable. 

    // int temp = 0;
    // for (auto i: arr) {
    //     if (temp > i) {
    //          cout << "False" << endl;
    //          cout << i;
    //     } 
    //     temp = i;
    // }

    // more optimal solution
    for (int i = 1; i<6;i++) {
        if (arr[i] <= arr[i-1]) {
            cout << "false";
            cout << arr[i];
            break;
        }
    }

    return 0;
}