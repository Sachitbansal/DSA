#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        int n, k, x;
        cin >> n;
        cin >> k;
        cin >> x;

        int total = 0;
        vector<int> arr;
        
        if (k>=1 && x!=1) {
            while(total != n) {
                arr.push_back(1);
                total++;
            }
        } else {
            if (k==1 || n==1) {
                // cout << "No\n";
            }
            if (k>=2 && n%2==0) {
                while(total != n) {
                    arr.push_back(2);
                    total+=2;
                }         
            } else if (k>2 && n%2 != 0 ) {
                arr.push_back(3);
                total +=3;
                while(total != n) {
                    arr.push_back(2);
                    total+=2;
                } 
            }  else {
                // cout << "No\n";
            }
        }



        if (total == n)
        {
            cout << "Yes\n";
            cout << arr.size() << endl;
            for (auto j : arr)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}
