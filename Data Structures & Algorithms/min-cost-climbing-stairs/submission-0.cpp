class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 1000000000);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i + 1 <= n) dp[i] = min(dp[i], dp[i + 1] + cost[i]);
            if (i + 2 <= n) dp[i] = min(dp[i], dp[i + 2] + cost[i]);
        }
        return min(dp[0], dp[1]);
    }
};
