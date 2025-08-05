#include <bits/stdc++.h>
using namespace std;

int main() {

    int n1;
    int n2;
    int hcf = 0;

    cin >> n1;
    cin >> n2;

    int bada = max(n1, n2);
    int chhota = min(n1, n2);
    // cout << bada << endl;

    for (int i = chhota; i > 0 ; i --) {
        if (bada % i == 0 && chhota % i == 0) {
                hcf = i;
                break;
        }
    }

    cout << hcf;
    return 0;
}
