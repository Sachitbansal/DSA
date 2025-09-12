#include <bits/stdc++.h>
using namespace std;

int fibonacci(int num) {
    if (num == 1 ) {
        return 1;
    } else if (num == 0) {
        return 0;
    } else {
        return fibonacci(num-1) + fibonacci(num-2);
    }
}


int main() {

    cout << fibonacci(7);
    return 0;
}