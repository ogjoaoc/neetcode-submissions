class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool has_cycle = false;
        vector<int> state(n, 0);
        int total = 0;
        auto dfs = [&](auto& dfs, int u, int p) -> void {
            if (has_cycle) return;
            state[u] = 1;
            total++;
            for (int v : adj[u]) {
                if (v == p) continue;
                if (state[v] == 1) {
                    has_cycle = true;
                    return;
                } else if (state[v] == 0) {
                    dfs(dfs, v, u);
                } 
            }
            state[u] = 2;
        };
        dfs(dfs, 0, -1);
        return !has_cycle && total == n;
    }
};
