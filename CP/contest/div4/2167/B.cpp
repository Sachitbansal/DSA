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

        string s1;
        string s2;
        cin >>s1>>s2;

        int ter=true;

        int has = true;
        for (int j=0;j<n;j++){
            char ch = s2[j];
            size_t pos = s1.find(ch);
            if (pos != string::npos)
                s1.erase(pos, 1);
            else {
                ter=false;
                continue;
            }
        }

        if (ter) cout << "YES"<<endl;
        else cout << "NO"<<endl;
    }

    return 0;
}
