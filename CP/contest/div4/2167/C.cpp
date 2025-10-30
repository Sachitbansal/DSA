#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        int n;
        cin >> n;

        vector<int> arr(n);
        for (int j=0;j<n;j++){
            cin >> arr[j];
        }

        int od=false;
        int ev=false;

        for (int j=0;j<n;j++){
            if (arr[j]%2==0) ev=true;
            else od=true;

            if (od && ev) break;
        }

        if (od && ev) {sort(arr.begin(), arr.end());}
        for (int j=0;j<n;j++){
            cout << arr[j]<<" ";
        }
        cout << endl;
    }

    return 0;
}
