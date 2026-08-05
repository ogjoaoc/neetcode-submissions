class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for (auto s : strs) {
            string t = s;
            sort(begin(t), end(t));
            mp[t].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto & [_, v] : mp) {
            ans.push_back(v);
        }
        return ans;
    }
};
