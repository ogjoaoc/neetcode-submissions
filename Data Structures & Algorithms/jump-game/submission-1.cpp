class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        auto rec = [&](auto && rec, int i) -> int {
            if (i >= n-1) return 1;
            if (dp[i] != -1) return dp[i];
            int ans = 0;
            for (int j = i + 1; j <= min(i + nums[i], n-1); j++) {
                ans |= rec(rec, j);
            }
            return dp[i] = ans;
        };
        return rec(rec, 0);
    }
};
