class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int N = s.size();
        map<char, int> mp;
        int ans = 0;
        int l = 0;
        for (int r = 0; r < N; r++) {
            while (mp[s[r]] > 0) {
                mp[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
            mp[s[r]]++;
        }
        return ans;
    }
};
