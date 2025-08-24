#include <bits/stdc++.h>
using namespace std;

string total = "";
int j = 1;

int main() {

    while (total.size() < 1e15) {
        total += to_string(j);
        j ++;
    }

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        
        int k;
        cin >> k;
        string final = total.substr(0, k);
        long long oho = stoi(final);
        long long ans = 0;
        for (int j = 0; j< final.size(); j++) {
            ans += total[j] - '0';
        }
        cout << ans << endl;

        
    }  
    return 0;
}
