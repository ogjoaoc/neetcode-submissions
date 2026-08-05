class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for (int x : nums) mp[x]++;
        vector<pair<int, int>> v;
        for (auto & [x, freq] : mp) v.push_back({freq, x});
        sort(rbegin(v), rend(v));
        vector<int> ans;
        for (int i = 0; i < min(k, (int)v.size()); i++) ans.push_back(v[i].second);
        return ans;
    }
};
