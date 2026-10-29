class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 5, 1000000000);
        dp[0] = 0;
        for (int x = 1; x <= amount; x++) {
            for (int c : coins) {
                if (x - c >= 0) 
                    dp[x] = min(dp[x], dp[x - c] + 1);
            }
        }
        if (dp[amount] == 1000000000) return -1;
        return dp[amount];
    }
};
