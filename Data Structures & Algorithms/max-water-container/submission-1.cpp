class Solution {
public:
    int maxArea(vector<int>& heights) {
        vector<pair<int, int>> v;
        int N = heights.size();
        for (int i = 0; i < N; i++) {
            v.push_back({heights[i], i + 1});
        }
        sort(rbegin(v), rend(v));
        set<int> st;
        int ans = 0;
        int i = 0;
        while (i < N) {
            int j = i;
            auto [x, p] = v[i];
            int bi = p;
            while (j < N && v[j].first == v[i].first) {
                st.insert(v[j].second);
                j++;
            }
            int mn = *begin(st);
            bi = max(p, *prev(end(st)));
            cout << "x = " << x << '\n';
            cout << "mn = " << mn << '\n';
            ans = max(ans, x * bi - mn * x); 
            i = j;
        }
        return ans;
    }
};
