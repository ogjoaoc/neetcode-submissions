class Solution {
public:
    string stoneGameIII(vector<int>& a) {
        int N = a.size();
        vector dp(N + 1, vector(2, -1ll));
        auto rec = [&](auto && rec, int i, int turn) -> int {
            if (i == N) return 0;
            if (~dp[i][turn]) return dp[i][turn];
            int ans;
            if (turn == 0) {
                ans = rec(rec, i + 1, turn ^ 1) + a[i];
                if (i + 1 < N) ans = max(ans, rec(rec, i + 2, turn ^ 1) + a[i] + a[i + 1]);
                if (i + 2 < N) ans = max(ans, rec(rec, i + 3, turn ^ 1) + a[i] + a[i + 1] + a[i + 2]);
            } else {
                ans = rec(rec, i + 1, turn ^ 1) - a[i];
                if (i + 1 < N) ans = min(ans, rec(rec, i + 2, turn ^ 1) - a[i] - a[i + 1]);
                if (i + 2 < N) ans = min(ans, rec(rec, i + 3, turn ^ 1) - a[i] - a[i + 1] - a[i + 2]);
            }
            return dp[i][turn] = ans;
        };
        int ans = rec(rec, 0, 0);
        if (ans < 0) return "Bob";
        else if (ans > 0) return "Alice";
        else return "Tie";
    }
};