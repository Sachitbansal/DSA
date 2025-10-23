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
        vector<long long> arr;
        
        for (int j=0;j<n;j++){
            long long num;
            cin >> num;
            arr.push_back(num);
        }
        sort(arr.begin(), arr.end());
        bool found=false;

        for (int j=0;j<n;j++){
            for (int k=0;k<n;k++){
                if (gcd(arr[j], arr[k])<=2){
                    found=true;
                    break;
                }
            }            
        }

        if (found) cout <<"Yes"<<endl;
        else cout << "No"<<endl;

    }
    return 0;
}
