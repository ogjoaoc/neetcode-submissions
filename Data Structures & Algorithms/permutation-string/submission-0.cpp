class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int N = s1.size(), M = s2.size();
        sort(begin(s1), end(s1));
        bool ok = false;
        for (int i = 0; i < M; i++) {   
            string c;
            for (int j = i; j < min(M, N + i); j++) c += s2[j];
            sort(begin(c), end(c));
            ok |= (c == s1);
        }
        return ok;
    }
};
