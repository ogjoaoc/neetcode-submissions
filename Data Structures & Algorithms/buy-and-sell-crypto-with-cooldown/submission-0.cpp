class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, -1));
        auto rec = [&](auto && rec, int i, int buy) -> int {
            if (i >= n) return 0;
            if (dp[i][buy] != -1) return dp[i][buy];
            int ans = rec(rec, i + 1, buy);
            if (buy) ans = max(ans, rec(rec, i + 1, 0) - prices[i]);
            else ans = max(ans, rec(rec, i + 2, 1) + prices[i]);
            return dp[i][buy] = ans;
        };
        return rec(rec, 0, 1);
    }
};
