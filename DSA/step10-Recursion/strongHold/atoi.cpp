class Solution {
public:

    void generate(string &s, bool &positive, long long &ans, int idx, bool started) {
        int n = s.size();
        if (idx >= n) {
            return;
        }

        if (!started && s[idx] == ' ') {
            generate(s, positive, ans, idx + 1, false);
        }
        else if (!started && s[idx] == '-') {
            positive = false;
            generate(s, positive, ans, idx + 1, true);
        }
        else if (isdigit(s[idx])) {
            int digit = s[idx] - '0';

            if (positive) {
                if (ans > (INT_MAX - digit) / 10) {
                    ans = INT_MAX;
                    return;
                }
            } else {
                if (-ans < (INT_MIN + digit) / 10) {
                    ans = -(long long)INT_MIN; // store as positive temporarily
                    return;
                }
            }

            ans = ans * 10 + digit;
            generate(s, positive, ans, idx + 1, true);
        }
        else if (!started && s[idx] == '+') {
            generate(s, positive, ans, idx + 1, true);
        } else return;

        
    }
    int myAtoi(string s) {
        bool positive = true;
        long long ans = 0;

        generate(s, positive, ans, 0, false);
        return positive ? ans : ans *= -1;
        
    }
};