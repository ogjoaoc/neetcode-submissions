class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        int N = temperatures.size();
        vector<int> result(N);
        for (int i = N - 1; i >= 0; i--) {
            while (!empty(st) && st.top().first <= temperatures[i]) st.pop();
            if (!empty(st)) result[i] = st.top().second - i;
            st.push({temperatures[i], i});
        }
        return result;
    }
};
