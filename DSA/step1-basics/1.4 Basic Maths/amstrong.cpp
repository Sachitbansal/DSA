#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int dup = n;
    int amstrong = 0;
    // amstrong number is som of cub of all digits

    while(n > 0) {
        amstrong += pow((n % 10), 3);
        n /= 10;
    }

    cout << amstrong << endl;
    cout << dup;

    return 0;
}