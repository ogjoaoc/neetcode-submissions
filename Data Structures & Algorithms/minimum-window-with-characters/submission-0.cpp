class Solution {
public:
    string minWindow(string s, string t) {
        int N = s.size();
        map<char, int> mpt;
        for (char c : t) mpt[c]++;
        auto ok = [&](map<char, int> & cur) -> bool {
            bool r = true;
            for (auto & [l, f] : mpt) {
                r &= (f <= cur[l]);
            }
            return r;
        };
        auto check = [&](int mid) -> bool {
            int l = 0;
            map<char, int> mp;
            for (int r = 0; r < N; r++) {
                mp[s[r]]++;
                while (r - l + 1 > mid) {
                    mp[s[l]]--;
                    l++;
                }   
                if (r - l + 1 == mid) {
                    if (ok(mp)) return true;
                } 
            }
            return false;
        };
        int l = 1, r = N, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (ans == -1) return "";
        map<char, int> mp;
        l = 0;
        for (int r = 0; r < N; r++) {
            mp[s[r]]++;
            while (r - l + 1 > ans) {
                mp[s[l]]--;
                l++;
            }   
            if (r - l + 1 == ans) {
                if (ok(mp)) {
                    return s.substr(l, ans);
                }
            } 
        }
    }
};
