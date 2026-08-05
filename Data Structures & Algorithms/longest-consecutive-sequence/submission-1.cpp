class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> mp, vis;
        for (int x : nums) {
            mp[x] = true;
        }
        int ans = 0;
        for (int x : nums) {
            if (vis[x]) continue;
            if (!mp[x - 1]) {
                int cur = x, len = 0;
                while (mp[cur] == true) {
                    len++;
                    vis[cur] = true;
                    cur++;
                } 
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
