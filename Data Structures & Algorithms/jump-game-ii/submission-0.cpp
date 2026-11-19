class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        auto rec = [&](auto && rec, int i) -> int {
            if (i == n - 1) return 0;
            if (dp[i] != -1) return dp[i];
            int ans = 1e9;
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j <= n - 1) {
                    ans = min(ans, 1 + rec(rec, i + j));
                }
            }
            return dp[i] = ans;
        };
        return rec(rec, 0);
    }
};
