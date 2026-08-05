class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n), s(n);
        p[0] = nums[0];
        s[n - 1] = nums.back();
        for (int i = 1; i < n; i++) p[i] = p[i - 1] * nums[i];
        for (int i = n - 2; i >= 0; i--) s[i] = s[i + 1] * nums[i];
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int left = (i >= 1 ? p[i - 1] : 1);
            int right = (i < n - 1 ? s[i + 1] : 1);
            ans.push_back(left * right);
        }
        return ans;
    }
};
