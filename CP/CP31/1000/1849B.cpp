#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        long long n, k;
        cin >> n >> k;

        vector<pair<long long,long long>> arr;
   
        for (long long i = 0; i < n; i++) {
            long long num;
            cin >> num;
            long long yoyo = (num % k == 0 ? k : num % k);
            arr.push_back({yoyo, i});
        }

        sort(arr.begin(), arr.end(),
            [](const pair<long long,long long>& a,
                const pair<long long,long long>& b) {
                if (a.first != b.first)
                    return a.first > b.first;  
                return a.second < b.second;   // second ascending
                       // first descending
            });

        for (long long i = 0; i < n; i++) {
            cout << arr[i].second+1 << " ";
        }
        cout << endl;

    }    

    return 0;
}
