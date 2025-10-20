#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        long long n;
        cin >> n;

        int ans=1;
        for (int j=0;j<n;j++){
            if (n%ans==0){
                ans++;
            } else break;
        }
        cout << ans -1<<endl;

    }    

    return 0;
}
