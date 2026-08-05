class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int N = a.size();
        int l = 0;
        multiset<int> mt;
        vector<int> ans;
        for (int r = 0; r < N; r++) {
            mt.insert(a[r]);
            while (r - l + 1 > k) {
                mt.erase(mt.find(a[l]));
                l++;
            }
            if (r - l + 1 == k) {
                ans.push_back(*prev(end(mt)));
            } 
        }   
        return ans;
    }
};
