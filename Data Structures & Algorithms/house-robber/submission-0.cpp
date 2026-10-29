class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 2);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            dp[i + 1] = max(dp[i + 1], dp[i]);
            dp[i + 2] = max(dp[i + 2], dp[i] + nums[i]);
        }
        return *max_element(begin(dp), end(dp));
    }
};
