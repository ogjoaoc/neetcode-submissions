class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ns;
        for (int x : nums) ns.push_back(to_string(x));
        sort(ns.begin(), ns.end(), []( string &a,  string &b) {
            return a + b > b + a;
        });
        if (ns[0] == "0") return "0";
        string ans;
        for (string s : ns) ans += s;
        return ans;
    } 
};