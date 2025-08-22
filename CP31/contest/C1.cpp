#include <bits/stdc++.h>
using namespace std;

vector<long long> powers;

long long cost(int x) {
    if (x == 0) return 3; 
    return powers[x+1] + 1LL * x * powers[x-1];
}

int main() {
    long long val = 1;
    for (int i = 0; i <= 20; i++) {
        powers.push_back(val);
        val *= 3;
    }

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        long long copy = n, costt = 0;

        while (copy != 0) {
            int idx = upper_bound(powers.begin(), powers.end(), copy) - powers.begin() - 1;
            copy -= powers[idx];
            costt += cost(idx);
        }

        cout << costt << "\n";
    }
}
