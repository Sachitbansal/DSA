#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[3][5]; // 3 rows 5 columns

    arr[1][3] = 75;
    cout << arr[1][3] << endl; // gives 75

    // for un-initialised values, it gives some garbage values
    cout << arr[1][2];
    return 0;
}