class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        vector<int> prefMax(N, -1e9), sufMax(N, -1e9);
        for (int i = 0; i < N; i++) {
            if (i) prefMax[i] = prefMax[i - 1];
            prefMax[i] = max(prefMax[i], height[i]);
        }
        for (int i = N-1; i >= 0; i--) {
            if (i + 1 < N) sufMax[i] = sufMax[i + 1];
            sufMax[i] = max(sufMax[i], height[i]);
        }
        int ans = 0;
        for (int i = 1; i < N - 1; i++) {
            int cur = min(prefMax[i - 1], sufMax[i + 1]);
            ans += max(0, cur - height[i]);
        }
        return ans;
    } 
};
