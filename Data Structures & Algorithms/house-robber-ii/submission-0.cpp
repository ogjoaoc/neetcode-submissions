class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1ll));
        auto rec = [&](auto && rec, int i, int robbed_first) -> int {
            if (i >= n) return 0;
            if (dp[i][robbed_first] != -1) return dp[i][robbed_first];
            int ans = rec(rec, i + 1, robbed_first);
            if (i == n - 1) {
                if (!robbed_first) ans = max(ans, rec(rec, i + 2, robbed_first) + nums[i]);
            } else {
                ans = max(ans, rec(rec, i + 2, robbed_first | (i == 0)) + nums[i]);
            }
            return dp[i][robbed_first] = ans;
        };
        return rec(rec, 0, 0);
    }
};
