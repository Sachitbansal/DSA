#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        
        for (int j=0;j<n;j++){
            cin >> arr[j];
        }
        int count=0;

        for (int j=0;j<n-1;j++){
            if ((arr[j]%2!=0 && arr[j+1]%2!=0) || (arr[j]%2==0 && arr[j+1]%2==0)){
                arr[j+1] = arr[j]*arr[j+1];
                count ++;
            }
        }
        cout << count<<endl;



    }
    return 0;
}

