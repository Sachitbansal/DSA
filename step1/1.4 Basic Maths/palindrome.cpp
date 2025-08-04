#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;


    // very bad algoooooo
    // just make a duplicate of n, find reverse and compare
    int length = int(log10(n) +1);

    if (length % 2 == 0) {
        int len = length/2;
        int firstHalf = n / pow(10, len);

        int rev = 0;
        for (int i = 0; i < len; i++) {
            rev *= 10;
            rev += n % 10;
            n /= 10;
        }
        cout << firstHalf << endl;
        cout << rev << endl;

        if (rev == firstHalf) {
            cout << true;
        } else {
            cout << false;
        }

    } else {
        cout << false;
    }
    return 0;
}