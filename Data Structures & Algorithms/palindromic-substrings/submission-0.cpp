class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1ll));
        auto rec = [&](auto & rec, int l, int r) -> int {
            if (l > r) return 0;
            if (l == r) return 1;
            if (dp[l][r] != -1) return dp[l][r];
            if (s[l] == s[r]) return dp[l][r] = rec(rec, l + 1, r - 1) + 2;
            return dp[l][r] = 0;
        };
        int ans = 0;
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                int len = r - l + 1;
                if (rec(rec, l, r) == len) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
