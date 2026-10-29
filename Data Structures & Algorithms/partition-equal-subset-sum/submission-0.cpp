class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        if (sum & 1) return false;
        int target = sum / 2;
        vector<int> dp(target + 5, 0);
        dp[0] = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] |= dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};
