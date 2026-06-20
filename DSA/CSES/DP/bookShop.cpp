#include<bits/stdc++.h>
using namespace std;

int f(int x, vector<int> &prices, vector<int> &pages) {
    if (x <= 0) return 0;

    int ans = 0;
    for (int i = 0; i < prices.size(); i++) {
        if(x >= prices[i]) {
            ans = max(ans, pages[i] + f(x - prices[i], prices, pages));
        }
    }
    return ans;
}

int main() {

    int n, x;
    cin>> n >> x;

    vector<int> prices(n);
    vector<int> pages(n);

    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << f(x, prices, pages);

    return 0;
}