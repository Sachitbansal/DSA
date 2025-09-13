#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    int signs[2] = {1, -1};

    for (int i = 0; i < t; i++) {
        
        int a, b;
        cin >> a >> b;

        int kx,ky;
        cin >> kx >> ky;
        int qx,qy;
        cin >> qx >> qy;
        set<array<int, 3>> s;
        int count = 0;

        for (int swap = 0; swap < 2; swap++) {
            int u = (swap == 0 ? a : b);
            int v = (swap == 0 ? b : a);

            for (int k = 0; k < 2; k++) {
                for (int j = 0; j < 2; j++) {
                    int x1 = kx + signs[k] * u;
                    int y1 = ky + signs[j] * v;
                    


                    for (int swap1 = 0; swap1 < 2; swap1++) {
                        int u1 = (swap1 == 0 ? a : b);
                        int v1 = (swap1 == 0 ? b : a);

                        for (int q = 0; q < 2; q++) {
                            for (int w = 0; w < 2; w++) {
                                int x2 = x1 + signs[q] * u1;
                                int y2 = y1 + signs[w] * v1;
                                if (x2 == qx && y2 == qy) {
                                    s.insert({x1, y1});
                                }
                            }
                        }
                    }





                }
            }
        }   
    
        
        cout << s.size() << endl;
    }  

    return 0;
}
