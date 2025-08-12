#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    // algo to reverse a number.
    // modulus will give us last digit which will be the first so we have to keep multiplying by 10 and keep adding the last digit

    int reverse = 0;
    while (n != 0) {
        reverse *= 10;
        reverse += n % 10;
        n /= 10;
    }

    cout << reverse;
    return 0;
}