#include <bits/stdc++.h>
using namespace std;

// You are given an integer n. You need to return the number of digits in the number.
// The number will have no leading zeroes, except when the number is 0 itself.


int main() {
 
    int n;
    cin >> n;
    int coun = int(log10(n) + 1);
    // one way is to devide by 10 because jitni baar 10 se devicde hoga, utne digits hian usmein

    int count = 0;
    while (n != 0) {
        n = n / 10;
        count ++;
    }

    cout << count << endl;

    // another way is to use log base 10 and add one to it
    
    cout << coun;

    // if the number of times a loop runs is based on devision, the TC will be log n
    // so time complexity of upper code with while loop is big-oh of log base 10 n
    return 0;
}