#include<bits/stdc++.h>
using namespace std;

int f(string n, string m, int i, int j, vector<vector<int>> &dp) {
    if (i < 0) return j+1;
    if (j < 0) return i +1;

    if (dp[i][j] != -1) return dp[i][j];

    if (n[i] == m[j]) return dp[i][j] = f(n , m, i-1, j-1, dp);
    else {
        int one = 1 + f(n, m, i-1, j, dp);
        int two = 1 + f(n, m, i, j-1, dp);
        int three = 1 + f(n, m, i-1, j-1, dp);
        return dp[i][j] = min(one, min(two, three));
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string n;
    string m;

    cin >> n;
    cin >> m;
    int i = n.size();
    int j = m.size();
    //vector<vector<int>> dp(i, vector<int> (j, -1));
    //cout << f(n, m, i-1, j-1, dp) <<endl;


    //vector<vector<int>> dp(i+1, vector<int> (j+1, 0));
    vector<int> prev(j+1, 0);
    vector<int> curr(j+1, 0);

    for (int a = 0; a <= j; a++) {
        // a is moving and b is fix
        prev[a] = a;
    }
    
    // for (int b = 0; b <= j; b++) {
    //     dp[0][b] = b;
    // }

    for (int a = 1; a <= i; a++) {
        curr[0] = a;
        for (int b = 1; b <= j; b++) {

            if (n[a-1] == m[b-1]) curr[b] = prev[b-1];
            else {
                curr[b] = min(1 + curr[b-1], min(1 + prev[b], 1 + prev[b-1]));
            }

        }
        prev=  curr;
    }

    cout << prev[j]<<endl;
    return 0;
}