#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;
        long long ans;
        long long count=0;
        if (n<10) {ans = n;}
        else {
            while (n>9) {
                count ++;
                n/=10;
                
            }
        }
        if (n==0)n++;
        ans = (9* count )+n;
        // cout << n <<" "<<count<<endl;
        cout << ans<<endl;  


    }
    return 0;
}

