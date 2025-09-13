#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long t;
    cin >> t;

    for (long long i = 0; i < t; i++)
    {

        string arr;
        cin >> arr;

        int count0=0;
        int count1=0;
        for (int j=0;j<arr.size();j++){
            if(arr[j]=='1') count1++;
            else count0++;
        }
        if (count0==count1) cout <<0<<endl;
        else cout << abs(count0-count1)<<endl;
    }

    return 0;
}
