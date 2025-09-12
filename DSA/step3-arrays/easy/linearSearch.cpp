#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {1,2,4,5,6,7,78};
    int n = 4;
    // p2 is always being incremented so this is also fine but for loop can also be used

    int p = -1;
    
    for (int i = 0; i < 7; i++) {
        if (n == arr[i]) p = i;
    }

    cout << p << endl;

    return 0;
}