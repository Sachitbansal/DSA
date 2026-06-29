#include<bits/stdc++.h>
using namespace std;

int f(int w, int h) {
    if (w == 0 && h == 0) return 1;

    int ans = 0;
    for (int width = w; width >= 0; width--) {
        for (int height = h; height >= 0; height--) {
            if (width == 0 && height == 0) continue;
            ans += f(w - width, h - height);

        }
    }
    return ans;

}

int main() {

    int t;
    cin >>t;
    while(t--) {

        int n;
        cin >> n;

        cout << f(2, n) <<endl;

    }

    return 0;
}