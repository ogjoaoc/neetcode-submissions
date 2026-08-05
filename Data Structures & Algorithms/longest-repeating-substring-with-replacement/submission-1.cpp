class Solution {
public:
    int characterReplacement(string s, int k) {
        int N = s.size();
        auto cost = [&](map<char, int> & mp) -> int {
            int S = 0, mx = 0;
            for (auto & [_, f] : mp) {
                S += f;
                mx = max(mx, f);
            }
            S -= mx;
            return S;
        };
        auto check = [&](int mid) -> bool {
            map<char, int> mp;
            int l = 0;
            for (int r = 0; r < N; r++) {
                mp[s[r]]++;
                while (r - l + 1 > mid) {
                    mp[s[l]]--;
                    if (mp[s[l]] == 0) mp.erase(s[l]);
                    l++;
                }
                if (r - l + 1 == mid) {
                    if (cost(mp) <= k) return true;
                }
            }
            return false;
        };
        int l = 1, r = N, ans = 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
