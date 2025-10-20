#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        int n,k;
        cin >> n>>k;

        int arr[n];
        for (int j=0;j<n;j++){
            cin >> arr[j];
        }
        int max=0;
        sort(arr, arr+n);
        int count=0;
        for (int j=0;j<n-1;j++){
            if (arr[j+1]-arr[j]<=k){
                count++;
                if (count>max) {
                    max=count;
                }
            } else {
                if (count>max) {
                    max=count;
                }
                count=0;
            }
            // cout<<count<<endl;
        }

        cout <<n-1- max <<endl;

    }    

    return 0;
}
