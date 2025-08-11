#include <bits/stdc++.h>
using namespace std;

int sumToN(int num) {
    if (num == 1) {
        return 1;
    } else {
        return num + sumToN(num-1);
    }
}

int main() {

    cout << sumToN(10);
    return 0;
}