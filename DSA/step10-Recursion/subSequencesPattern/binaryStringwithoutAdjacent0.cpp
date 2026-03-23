class Solution {
public:

    void generate(int n, vector<string> &ans, string &curr) {
        int len = curr.size();
        if (len == n) {
            ans.push_back(curr);
           
            return;
        }

        char prev = len >0 ? curr[len-1] : 'x';

        if (prev == 'x' || prev == '1') {
            // any of 1 or 0 can comeA
            
            curr+='1';
            generate(n, ans, curr);
            curr.pop_back();

            curr+='0';
            generate(n, ans, curr);
            curr.pop_back();
        } else {
            // last element is 0 so next can only be 1
            curr+='1';
            generate(n, ans, curr);
            curr.pop_back();
        }
        
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        string curr = "";

        generate(n, ans, curr);

        return ans;
    }
};