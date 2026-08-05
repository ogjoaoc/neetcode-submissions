class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& g) {
        int N = g.size();
        int M = g[0].size();
        vector<pair<int, int>> dirs = { { 1, 0 }, { -1, 0 }, {0, 1}, {0, -1 } };
        auto check = [&](int i, int j) -> bool {
            return i >= 0 && i < N && j >= 0 && j < M; 
        };
        vector dp(N + 1, vector(M + 1, -1ll));
        auto rec = [&](auto && rec, int i, int j) -> int {
            if (~dp[i][j]) return dp[i][j];
            int ans = 0;
            for (auto & [a, b] : dirs) {
                if (check(i + a, j + b)) {
                    if (g[i + a][j + b] > g[i][j]) {
                        ans = max(ans, rec(rec, i + a, j + b) + 1);
                    }
                }
            }
            return dp[i][j] = ans;
        };
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                ans = max(ans, rec(rec, i, j));
            }
        }
        return ans + 1;
    }
};
