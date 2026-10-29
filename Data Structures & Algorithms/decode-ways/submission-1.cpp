class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 5, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') dp[i + 1] += dp[i];
            if (i + 2 <= n) {
                int num = stoi(s.substr(i, 2));
                if (num >= 10 && num <= 26) dp[i + 2] += dp[i];
            }
        }
        return dp[n];
    }
};
