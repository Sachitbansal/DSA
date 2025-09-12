#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        int a,b,c,d;
        cin >> a >>b>>c>>d;

        int bada1 = max(a,b);
        int chhota1 = min(a,b);
    
        if ((bada1 - (2*chhota1)) <=2 ) {
            c-=a;
            d-=b;

            int bada2 = max(c,d);
            int chhota2 = min(c,d);
            
            if ((bada2 - (2*chhota2)) <=2) {

                cout << "Yes" << endl;
            }  else cout << "No\n"; 
            
        } else cout << "No\n";
    }
    return 0;
}
