class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e9, sum = 0;
        for (int x : nums) {
            sum = max(x, sum + x);
            ans = max(ans, sum);
        }
        return ans;
    }
};
