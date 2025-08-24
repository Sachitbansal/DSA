#include <bits/stdc++.h>
using namespace std;

vector<long long> powers;

int main()
{

    long long val = 10;
    for (int i = 0; i <= 19; i++)
    {
        powers.push_back(val + 1);
        val *= 10;
    }

    int t;
    cin >> t;
    while (t--)
    {
        vector<long long> answer;

        long long n;
        cin >> n;

        for (auto i : powers)
        {
            if (n % i == 0)
            {
                answer.insert(answer.begin(), n / i);
            }
        }

        if (answer.size() == 0)
            {cout << 0;}
        else
        {
            cout << answer.size() << endl;
            for (auto j: answer) {
                cout << j << " ";
            } 
        }
        cout << endl;
    }
}
