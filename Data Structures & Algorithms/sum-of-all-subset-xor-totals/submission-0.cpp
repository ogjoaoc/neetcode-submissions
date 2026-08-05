class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        long long N = nums.size();
        long long ans = 0;
        auto rec = [&](auto && rec, long long i, long long cx) -> void {
            if (i == N) {
                ans += cx;
                return;
            }
            rec(rec, i + 1, cx ^ nums[i]);
            rec(rec, i + 1, cx);
        };
        rec(rec, 0, 0);
        return ans;
    }
};