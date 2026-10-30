class TimeMap {
public:
    map<string, vector<pair<int, string>>> mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});    
    }
    
    string get(string key, int timestamp) {
        if (mp.count(key) == 0) return "";
        auto & v = mp[key];
        int n = v.size();
        int l = 0, r = n - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (v[mid].first <= timestamp) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }       
        if (ans == -1) return "";
        return v[ans].second;
    }
};
