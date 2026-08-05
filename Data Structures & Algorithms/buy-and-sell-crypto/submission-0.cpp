class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        int mx = -1e9;
        int ans = 0;
        for (int i = N - 1; i >= 0; i--) {
            ans = max(ans, mx - prices[i]);
            mx = max(prices[i], mx);
        }
        return ans;
    }
};
