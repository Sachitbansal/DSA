class Solution {
public:

    int minJumps(vector<int>& nums) {

        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        // SPF sieve
        vector<int> spf(mx + 1);

        for (int i = 0; i <= mx; i++) {
            spf[i] = i;
        }w

        for (int i = 2; i * i <= mx; i++) {

            if (spf[i] == i) {

                for (int j = i * i; j <= mx; j += i) {

                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }

        // prime -> indices divisible by prime
        unordered_map<int, vector<int>> primes;

        for (int i = 0; i < n; i++) {

            int x = nums[i];
            unordered_set<int> usedFactors;

            while (x > 1) {

                int p = spf[x];

                if (usedFactors.find(p) == usedFactors.end()) {
                    primes[p].push_back(i);
                    usedFactors.insert(p);
                }

                x /= p;
            }
        }

        vector<int> dist(n, 1e9);
        dist[0] = 0;

        queue<int> q;
        q.push(0);

        unordered_set<int> usedPrime;

        while (!q.empty()) {

            int index = q.front();
            q.pop();

            if (index == n - 1) {
                return dist[index];
            }

            // adjacent right
            if (index + 1 < n &&
                dist[index + 1] > dist[index] + 1) {

                dist[index + 1] = dist[index] + 1;
                q.push(index + 1);
            }

            // adjacent left
            if (index - 1 >= 0 &&
                dist[index - 1] > dist[index] + 1) {

                dist[index - 1] = dist[index] + 1;
                q.push(index - 1);
            }

            // teleport
            int val = nums[index];

            // teleport allowed only if current value itself is prime
            if (val > 1 &&
                spf[val] == val &&
                usedPrime.find(val) == usedPrime.end()) {

                for (int nextIndex : primes[val]) {

                    if (dist[nextIndex] > dist[index] + 1) {

                        dist[nextIndex] = dist[index] + 1;
                        q.push(nextIndex);
                    }
                }

                usedPrime.insert(val);
            }
        }

        return dist[n - 1];
    }
};