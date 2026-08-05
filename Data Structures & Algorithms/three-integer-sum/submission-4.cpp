class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int N = nums.size();
        unordered_map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }
        set<vector<int>> ans;
        auto fix = [&](vector<int> & v) -> void {
            int pmx = max_element(begin(v), end(v)) - begin(v);
            swap(v[2], v[pmx]);
            int pmn = min_element(begin(v), end(v)) - begin(v);
            swap(v[0], v[pmn]);
        };
        for (int i = 0; i < N; i++) {
            mp[nums[i]]--;
            int tgt = - nums[i];
            for (int j = 0; j < N; j++) {
                if (j == i) continue;
                int need = tgt - nums[j];
                mp[nums[j]]--;
                if (mp[need] > 0) {
                    vector<int> t = { nums[i], nums[j], need };
                    fix(t);
                    ans.insert(t);
                }
                mp[nums[j]]++;
            }
            mp[nums[i]]++;
        }
        vector<vector<int>> r;
        for (auto vv : ans) r.push_back(vv);
        return r;
    }
};
