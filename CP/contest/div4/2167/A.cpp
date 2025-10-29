#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        vector<int> num(4);
        for (int j = 0; j < 4; j++) {
            cin >> num[j];
        }
        if (num[0]== num[1]&& num[1]== num[2]&& num[2]==num[3]) cout<<"YES"<<endl;
        else cout << "NO"<<endl;
    }

    return 0;
}
