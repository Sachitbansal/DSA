#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long int n, k,x;
        cin>>n>>k>>x;

        long long int sumfirst = k*(k+1)/2;
        long long int sumlast = (k)*((2*n) +1 - k)/2;

        // cout << sumfirst << " " << sumlast << endl;

        if (x >= sumfirst && x <= sumlast) cout << "Yes\n";
        else cout <<"No\n";
        

  
        
    }   
    return 0;
}