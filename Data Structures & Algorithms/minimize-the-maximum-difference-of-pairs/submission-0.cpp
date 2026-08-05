class Solution {
public:
    int minimizeMax(vector<int>& a, int p) {
        using ll = long long;
        ll N = a.size();
        sort(begin(a), end(a));
        auto check = [&](ll mid) -> bool {
            ll t = 0;
            for (ll i = 0; i < N - 1 && t < p; i++) {
                if (a[i + 1] - a[i] <= mid) {
                    t++;
                    i++;
                }
            }   
            return t >= p;
        };
        ll l = 0, r = 1e18, ans = 0;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};