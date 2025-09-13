#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n,m,x,y;
        cin >> n >> m>>x>>y;

        int ai[n];
        int bi[m];
       
        for (int j=0;j<n;j++) cin>> ai[j];
        for (int j=0;j<m;j++) cin>> bi[j];

        cout << m+n<<endl;
    }

    return 0;
}
