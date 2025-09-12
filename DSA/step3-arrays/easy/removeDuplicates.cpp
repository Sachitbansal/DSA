#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {1,1,2,2,2,3,3};

    // p2 is always being incremented so this is also fine but for loop can also be used

    int p1 = 0;
    int p2 = 1;
    while (p2!=6) {
        if (arr[p1] == arr[p2]) {
            p2++;
        } else {
            arr[p1+1] = arr[p2];
            p1++;
            p2++;
        }
    }

    for (int i = 0; i <= p1; i++) {
        cout << arr[i] << endl;    
    }

    return 0;
}