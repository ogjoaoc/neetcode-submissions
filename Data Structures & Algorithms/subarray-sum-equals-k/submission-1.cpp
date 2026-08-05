class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        using ll = long long;
        map<ll, ll> mp;
        mp[0] = 1ll;
        ll s = 0, ans = 0;
        for (ll x : nums) {
            s += x;
            ans += mp[s - k];
            mp[s]++;
        }   
        return ans;
    }
};