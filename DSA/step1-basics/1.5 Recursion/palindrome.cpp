#include <bits/stdc++.h>
using namespace std;

bool palindrome(int n) {
    int last = n % 10;
    int small = n / 10;
    int len = log10(n) +1;
    if (len == 1) {
        return true;
    }
    int dummy = pow(10, len-2);
    int reduced = small % dummy;
    int opp = (n / pow(10, len-1));
    int oppp = opp % 10;
    if (last == oppp) {
        if (palindrome(oppp)) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }

}

int main() {

    cout << palindrome(123321);
    
    return 0;
}