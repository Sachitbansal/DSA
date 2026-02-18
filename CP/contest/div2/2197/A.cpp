#include <bits/stdc++.h>
using namespace std;

long long summ(long long n) {
    long long summ = 0;
    while (n != 0) {
        int digit = n%10;
        n/=10;
        summ += digit;
    }
    return summ;
}

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        
        long long n;
        cin >> n;

        long long ans = 0;
        
        long long range = n + 1LL * 100;
        for (long long i = n; i <= range; i++) {
            if (n == i - summ(i)) {
                ans ++;
            }
        }

        cout << ans << endl;

    }  
    return 0;
}
