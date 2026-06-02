class Solution {
public:
    int mod = 1e9 + 7;
    int power(long long expo, long long base) {
        long long ans = 1LL;
        
        while(expo) {
            if (expo % 2 == 0) {
                expo >>= 1;
                base = (1LL * base * base) % mod;
            } else {
                expo--;
                ans = (ans * base) % mod;
            }
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long oddP;
        long long evenP;
        if (n % 2 == 0) {evenP = n/2; oddP = n/2;}
        else {evenP = (n+1)/2; oddP = n/2;}
        return (1LL*  power(evenP, 5) % mod) * (1LL * power(oddP, 4) % mod) % mod; 

    }
};