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
        int arr[n];
        for (int j = 0; j < n; j++)
        {
            int num;
            cin >> num;
            arr[j] = num % 3;
        }
        int l = 0;
        int q = 0;
        int p1 = 0;
        int p2 = 0;
        int p3 = 0;
        bool found = false;

        for (int j = 1; j < n; j++)
        {
            p1 += arr[j-1];
            for (int r = j; r < n; r++)
            {
                p2 += arr[r];
                if (p2 == p1)
                {
                    for (int k = r + 1; k < n; r++)
                    {
                        p3 += arr[k];
                    }
                    if (p2 == p3)
                    {
                        found = true;
                        l = j;
                        q = r;
                        break;
                    }
                } else if (p2>p1) 
            }
        }
        if (found) cout<< l<<" "<<q<<endl;
        else cout <<0<<" "<<0<<endl;
    }

    return 0;
}
